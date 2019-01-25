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

bool nextArgCorrect(int index, int size, char** args, string extension)
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
    bool createGraph = false;
    bool getOnlyHTML = false;

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
                    getOnlyHTML = true;
                    if(nextArgCorrect(i, argc, argv, ""))
                    {
                        parser_urlFilter = argv[++i];
                    }
                    cout << "Exclude all URL other than html" << endl;
                    break;
                case 't':
                    cout << "Only hits between xh and x+1h have been taken into account" << endl;
                    break;
                case 'u':
                    if(nextArgCorrect(i, argc, argv, ""))
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

    if(getOnlyHTML)
        p.filterURLs(parser_urlFilter);

    p.SendDataToGraph(createGraph, graph_fileName); //où mettre le graph ? nouveau dossier ?

    if(createGraph)
    {
        system("dot -Tpng -o tmp/graphTest.png tmp/graphTest.dot"); //à paramétrer
        cout << "Dot-file " << graph_fileName << " generated" << endl;
    }
}