/*************************************************************************
                           Analog  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Analog> (fichier Analog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Parser.h"
#include "Query.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Analog::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool nextArgCorrect(int index, int size, char** args, string extension = "")
{
    if(index+1 < size-1)
    {
        if(args[index+1][0] != '-')
        {
            string s = args[index+1];
            if(s.find(extension) != string::npos)
                return true;
        }
    }
    return false;
}

void displayHelp()
{
    cout << "-h                   : Display this message" << endl;
    cout << "-d                   : Generate the pdf graph" << endl;
    cout << "-e [filter]          : Keep all requested urls where the filter string is present, others are deleted. Referer urls are not affected. If no filter is given, then the default filter will be "".html\"" << endl;
    cout << "-g dot_file_name     : Generate a Dot-file out of the analysed log file" << endl;
    cout << "-n nb_arcs           : Do not display all undefined referer requests" << endl;
    cout << "-t hour              : Keep all requested urls whitin the interval [hour ; hour+1], others are deleted" << endl;
    cout << "-u host_url          : Change the default host url (http://intranet-if.insa-lyon.fr) to the one passed in parameter" << endl;
    cout << "-x                   : Do not display all undefined referer requests" << endl;
}

int main(int argc, char* argv[])
{
    string log_fileName =  "";
    string graph_fileName = "";
    string parser_urlFilter = ".html";
    string query_hosturl = "http://intranet-if.insa-lyon.fr";
    int parser_hitHour = 0;
    int graph_nArcs = 10;
    bool createGraph = false;
    bool doFilterURL = false;
    bool doFilterHour = false;
    bool doFilterUndefined = false;
    bool doDrawGraph = false;

    for(int i = 1; i < argc; i++)
    {
        if(argv[i][0] == '-')
        {
            switch (argv[i][1])
            {
                case 'g':
                    createGraph = true;
                    if(nextArgCorrect(i, argc, argv, ".dot"))
                    {
                        graph_fileName = argv[++i];
                    }
                    else
                    {
                        if(nextArgCorrect(i, argc, argv))
                        {
                            graph_fileName = string(argv[++i]) + ".dot";
                            cout << graph_fileName << endl;
                        }
                        else
                        {
                            graph_fileName = "out.dot";
                        }
                    }
                    cout << "- Generate Dot-file of the graph" << endl;
                    break;

                case 'e':
                    doFilterURL = true;
                    if(nextArgCorrect(i, argc, argv))
                    {
                        parser_urlFilter = argv[++i];
                    }
                    cout << "- Exclude all URL not containing \"" << parser_urlFilter << "\"" << endl;
                    break;

                case 't':
                    if(nextArgCorrect(i, argc, argv))
                    {
                        int tmp = atoi(argv[++i]);
                        if (tmp >= 0 && tmp < 24)
                        {
                            doFilterHour = true;
                            parser_hitHour = tmp;
                        }
                        else
                        {
                            cerr << "Error : Hour must be an integer between 0 and 23" << endl;
                            return 3;
                        }
                    }
                    cout << "- Only hits between " << parser_hitHour << "h and " << parser_hitHour + 1 << "h have been taken into account" << endl;
                    break;

                case 'u':
                    if(nextArgCorrect(i, argc, argv))
                    {
                        query_hosturl = argv[++i];
                        cout << "- Analyze for the host : " << endl;
                    }
                    else
                    {
                        cerr << "Error : No host name specified !" << endl;
                        return 4;
                    }
                    break;

                case 'h':
                    displayHelp();
                    return 0;

                case 'x':
                    doFilterUndefined = true;
                    cout << "- Undefined referer urls are not taken into account !" << endl;
                    break;

                case 'n':
                    if(nextArgCorrect(i, argc, argv))
                    {
                        graph_nArcs = atoi(argv[++i]);
                        if (graph_nArcs <= 0)
                        {
                            cerr << "Error : Number of arcs must be a positive integer" << endl;
                            return 5;
                        }
                        cout << "- Graph will contain " << graph_nArcs << " arcs" << endl;
                    }
                    break;

                case 'd':
                    doDrawGraph = true;
                    cout << "- Generating PDF file of the graph ..." << endl;
                    break;

                default:
                    cerr << "Error : Invalid command" << endl;
                    cout << "- Use ./analog -h for help" << endl;
                    return 100;
                    break;
            }
        }
        else
        {
            log_fileName = argv[i];
            ifstream file(log_fileName.c_str());
            if(!file.is_open())
            {
                cerr << "Error : Log file " << log_fileName << " not found" << endl;
                return 2;
            }
        }
    }

    if(log_fileName == "")
    {
        cerr << "Error : Missing file to analyze" << endl;
        return 1;
    }

    Parser p(log_fileName,query_hosturl);

    if(doFilterURL)
    {
        p.filterURLs(parser_urlFilter);
    }

    if(doFilterHour)
    {
        p.filterHour(parser_hitHour);
    }

    if(doFilterUndefined)
    {
        p.removeUndefined();
    }

    p.SendDataToGraph(createGraph, graph_fileName, graph_nArcs);

    if(doDrawGraph)
    {
        if(createGraph)
        {
            string s = "dot -Tpdf -o " + graph_fileName.substr(0,graph_fileName.length()-4) + ".pdf " + graph_fileName;
            system(s.c_str());
            cout << "Dot-file " << graph_fileName << " converted to PDF file" << endl;
        }
        else
        {
            cerr << "Error : no Dot-file generated" << endl;
            return 6;
        }
    }

    return 0;
}
