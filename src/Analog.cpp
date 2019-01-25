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
    if(index+1 < size)
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
    cout << "-e [filter]          : Keep all requested urls where the filter string is present, others are deleted. Referer urls are not affected. If no filter is given, then the default filter will be "".html\"" << endl;
    cout << "-g [dot_file_name]   : Generate a Dot-file out of the analysed log file" << endl;
    cout << "-t [hour]            : Keep all requested urls whitin the interval [hour ; hour+1], others are deleted" << endl;
    cout << "-u [host_url]        : Change the default host url (http://intranet-if.insa-lyon.fr) to the one passed in parameter" << endl;
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
                        cerr << "Error : Specify a correct name for the Dot-file" << endl;
                        return 1;
                    }
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
                            return 1;
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
                        return 1;
                    }
                    break;

                case 'h':

                    displayHelp();
                    break;

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
                            return 1;
                        }
                    }
                    break;

                default:
                    cerr << "Error : Invalid command" << endl;
                    cout << "- Use ./analog -h for help" << endl;
                    return 1;
                    break;
            }
        }
        else
        {
            log_fileName = argv[i];
        }
    }
    if(log_fileName == "")
    {
        cerr << "Error : Missing file to analyse" << endl;
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

    if(createGraph)
    {
        system("dot -Tpng -o tmp/graphTest.png tmp/graphTest.dot"); //à paramétrer
        cout << "Dot-file " << graph_fileName << " generated" << endl;
    }

    return 0;
}
