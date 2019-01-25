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

int main(int argc, char* argv[])
{
    string log_fileName =  "";
    string graph_fileName = "";
    string parser_urlFilter = ".html";
    string query_hosturl = "http://intranet-if.insa-lyon.fr";
    int parser_hitHour = 0;
    bool createGraph = false;
    bool doFilterURL = false;
    bool doFilterHour = false;

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
                    cout << "Exclude all URL other than html" << endl;
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
                            cerr << "L'heure doit être un entier compris entre 0 et 23" << endl;
                        }
                    }
                    cout << "Only hits between " << parser_hitHour << "h and " << parser_hitHour + 1 << "h have been taken into account" << endl;
                    break;
                case 'u':
                    if(nextArgCorrect(i, argc, argv))
                    {
                        query_hosturl = argv[++i];
                        cout << "Analyse for the host : " << endl;
                    }
                    else
                    {
                        cerr << "Error : No host name specified !" << endl;
                        return 1;
                    }
                    break;
                default:
                    cerr << "Error : Commande incorrecte" << endl;
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

    p.SendDataToGraph(createGraph, graph_fileName);

    if(createGraph)
    {
        system("dot -Tpng -o tmp/graphTest.png tmp/graphTest.dot"); //à paramétrer
        cout << "Dot-file " << graph_fileName << " generated" << endl;
    }
}
