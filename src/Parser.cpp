/*************************************************************************
                           Parser  -  description
                             -------------------
    début                : 13/02/2019
    copyright            : (C) 2019 par Baptiste Lotigier et Téo Bouvard
*************************************************************************/

//---------- Réalisation de la classe <Parser> (fichier Parser.cpp) ------------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Parser.h"
#include "Graph.h"
#include "Query.h"

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

void Parser::SendDataToGraph(bool convertGraph, string graph_fileName, unsigned int nArcs)
{
    Graph graph(querySet);
    graph.printHits();

    if (convertGraph)
    {
        graph.createGraphFile(graph_fileName,nArcs);
    }
}//---------Fin de SendDataToGraph

void Parser::FilterURLs(string extension)
{
    set<Query>::iterator it = querySet.begin();
    while(it != querySet.end())
    {
        if(it->GetRequestURL().find(extension) == string::npos)
        {
            querySet.erase(it++);
        }
        else
        {
            it++;
        }
    }
}//--------Fin de filterURLs

void Parser::FilterHour(int hour)
{
    set<Query>::iterator it = querySet.begin();
    while(it != querySet.end())
    {
        if(it->GetHour() != hour)
        {
            querySet.erase(it++);
        }
        else
        {
            it++;
        }
    }
}//--------Fin de filterTime

void Parser::RemoveUndefined()
{
    set<Query>::iterator it = querySet.begin();
    while(it != querySet.end())
    {
        if(it->GetRefererURL() == "Undefined")
        {
            querySet.erase(it++);
        }
        else
        {
            it++;
        }
    }
}

//-------------------------------------------- Constructeurs - destructeur

Parser::Parser (const string log_fileName, const string host_url)
{
    ifstream logFile;
    logFile.open(log_fileName.c_str());

    string line;
    regex lineReg("\\d+\\.\\d+\\.\\d+\\.\\d+ [^ ]+ [^ ]+ \\[\\d+\\/\\w+\\/\\d+\\:\\d+\\:\\d+\\:\\d+ (\\+|\\-)\\d+\\] \"\\w+ [^ ]+ [^ |\"]+\" \\d+ (\\d+|-) \"[^ |\"]+\" \"[^\"]+\"$");
    while (getline(logFile, line))
    {
        if(regex_match(line,lineReg))
        {
            Query query(line, host_url);
            querySet.insert(query);
        }
    }

#ifdef MAP
    cout << "Appel au constructeur de <Parser>" << endl;
#endif
} //----- Fin de Parser
