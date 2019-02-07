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
#include <time.h> //measuring performance
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Parser.h"
#include "Query.h"

//------------------------------------------------------------- Constantes
#define EXIT_SUCCESS 0
#define MISSING_LOG_ARG 1
#define BAD_ARG_LOG_NOT_FOUND 2
#define BAD_ARG_HOUR 3
#define BAD_ARG_HOST 4
#define BAD_ARG_ARCS 5
#define NO_DOT_FILE 6
#define NO_ARG_HOUR 7
#define NO_ARG_ARCS 8
#define INVALID_COMMAND 100

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

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
    cout << "-d                   : Generate a PDF version of the graph graph. Must be used with -g" << endl;
    cout << "-e [filter]          : Filter out all requested urls not containing the [filter] string. Referer urls are not affected. Default filter is \".html\"" << endl;
    cout << "-g dot_file_name     : Generate a Dot-file out of the analysed log file" << endl;
    cout << "-n nb_arcs           : When used with -g, specifies the number of arcs in the graph. Default value is 10" << endl;
    cout << "-t hour              : Filter out every request not sent within the interval [hour ; hour+1]" << endl;
    cout << "-u host_url          : Change the default host url (http://intranet-if.insa-lyon.fr) to the one passed in parameter" << endl;
    cout << "-x                   : Do not display all undefined referer requests" << endl;
}

int main(int argc, char* argv[])
{
    #ifdef SPEEDTEST
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    #endif

    string log_fileName =  "";
    string graph_fileName = "";
    string parser_urlFilter = ".html";
    string query_hosturl = "http://intranet-if.insa-lyon.fr";

    int parser_hitHour = 0;
    int graph_nArcs = 10;

    bool makeDotFile = false;
    bool doFilterURL = false;
    bool doFilterHour = false;
    bool doFilterUndefined = false;
    bool doFilterArcs = false;
    bool doDrawGraph = false;

    for(int i = 1; i < argc; i++)
    {
        if(argv[i][0] == '-')
        {
            switch (argv[i][1])
            {
                case 'g':
                    makeDotFile = true;
                    if(nextArgCorrect(i, argc, argv, ".dot"))
                    {
                        graph_fileName = argv[++i];
                    }
                    else
                    {
                        if(nextArgCorrect(i, argc, argv))
                        {
                            graph_fileName = string(argv[++i]) + ".dot";
                        }
                        else
                        {
                            graph_fileName = "out.dot";
                        }
                    }
                    cout << "- Generate Dot-file of the graph : " << graph_fileName << endl;
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
                            return BAD_ARG_HOUR;
                        }
                    }
                    else{
                        cerr << "Error : No hour specified" << endl;
                        return NO_ARG_HOUR;
                    }
                    cout << "- Only hits between " << parser_hitHour << "h and " << parser_hitHour + 1 << "h have been taken into account" << endl;
                    break;

                case 'u':
                    if(nextArgCorrect(i, argc, argv))
                    {
                        query_hosturl = argv[++i];
                        cout << "- Analyze for the host : " << query_hosturl << endl;
                    }
                    else
                    {
                        cerr << "Error : No host name specified" << endl;
                        return BAD_ARG_HOST;
                    }
                    break;

                case 'h':
                    displayHelp();
                    return EXIT_SUCCESS;

                case 'x':
                    doFilterUndefined = true;
                    cout << "- Undefined referer urls are not taken into account" << endl;
                    break;

                case 'n':
                    if(nextArgCorrect(i, argc, argv))
                    {
                        graph_nArcs = atoi(argv[++i]);
                        doFilterArcs = true;
                        if (graph_nArcs <= 0)
                        {
                            cerr << "Error : Number of arcs must be a positive integer" << endl;
                            return BAD_ARG_ARCS;
                        }
                        cout << "- Graph will contain " << graph_nArcs << " arcs" << endl;
                    }
                    else{
                        cerr << "Error : Must specify positive number of arcs" << endl;
                        return NO_ARG_ARCS;
                    }
                    break;

                case 'd':
                    doDrawGraph = true;
                    cout << "- Generate PDF file of the graph" << endl;
                    break;

                default:
                    cerr << "Error : Invalid command" << endl;
                    cout << "- Use ./analog -h for help" << endl;
                    return INVALID_COMMAND;
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
                return BAD_ARG_LOG_NOT_FOUND;
            }
        }
    }

    if(log_fileName == "")
    {
        cerr << "Error : Missing file to analyze" << endl;
        return MISSING_LOG_ARG;
    }

    Parser p(log_fileName,query_hosturl);

    if(doFilterURL)
    {
        p.FilterURLs(parser_urlFilter);
    }

    if(doFilterHour)
    {
        p.FilterHour(parser_hitHour);
    }

    if(doFilterUndefined)
    {
        p.RemoveUndefined();
    }

    p.SendDataToGraph(makeDotFile, graph_fileName, graph_nArcs);

    if(doDrawGraph)
    {
        if(makeDotFile)
        {
            string s = "dot -Tpdf -o " + graph_fileName.substr(0,graph_fileName.length()-4) + ".pdf " + graph_fileName;
            system(s.c_str());
            cout << "Dot-file " << graph_fileName << " converted to PDF file" << endl;
        }
        else
        {
            cerr << "Error : no Dot-file generated" << endl;
            return NO_DOT_FILE;
        }
    }
    else if (doFilterArcs)
    {
        cerr << "Error : no Dot-file generated" << endl;
        return NO_DOT_FILE;
    }

    #ifdef SPEEDTEST
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    clog << "Temps d'exécution : " << cpu_time_used << endl;
    #endif
    
    return EXIT_SUCCESS;
}
