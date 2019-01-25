/*************************************************************************
                           Parser  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Parser> (fichier Parser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Parser.h"
#include "Graph.h"
#include "Query.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Parser::SendDataToGraph(bool createGraph, string graph_fileName = "")
{
    Graph graph(querySet);
    graph.printHits();

    if (createGraph)
    {
        graph.createGraphFile(graph_fileName);
    }
}//---------Fin de SendDataToGraph

void Parser::filterURLs(string extension)
{
    set<Query>::iterator it = querySet.begin();
    while(it != querySet.end())
    {
        if(it->getRequestURL().find(extension) == string::npos)
        {
            querySet.erase(it++);
        }
        else
        {
            it++;
        }
    }
}//--------Fin de filterURLs

void Parser::filterHour(int hour)
{
    set<Query>::iterator it = querySet.begin();
    while(it != querySet.end())
    {
        if(it->getHour() != hour)
        {
            querySet.erase(it++);
        }
        else
        {
            it++;
        }
    }
}//--------Fin de filterTime

void Parser::removeUndefined()
{
    set<Query>::iterator it = querySet.begin();
    while(it != querySet.end())
    {
        if(it->getRefererURL() == "Undefined")
        {
            querySet.erase(it++);
        }
        else
        {
            it++;
        }
    }
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Parser::Parser ( const Parser & unParser )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Parser>" << endl;
#endif
} //----- Fin de Parser (constructeur de copie)


Parser::Parser (const string log_fileName, const string host_url)
// Algorithme :
//
{
    ifstream logFile;
    logFile.open(log_fileName.c_str());

    string line;
    while (getline(logFile, line))
    {
        Query query(line, host_url);
        querySet.insert(query);
    }

#ifdef MAP
    cout << "Appel au constructeur de <Parser>" << endl;

    cout << endl << "Nb Exceptions : " << Query::getNbExceptions() << endl;
    cout << "Nb Requêtes : " << querySet.size() << endl;
#endif
} //----- Fin de Parser


Parser::~Parser ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Parser>" << endl;
#endif
} //----- Fin de ~Parser


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
