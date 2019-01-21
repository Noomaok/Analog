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

void Parser::SendDataToGraph(bool createGraph){
    Graph graph(querySet);
    graph.printHits();
    if (createGraph)
    {
        graph.createGraphFile();
    }
}
// type Parser::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//Parser & Parser::operator = ( const Parser & unParser )
// Algorithme :
//
//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Parser::Parser ( const Parser & unParser )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Parser>" << endl;
#endif
} //----- Fin de Parser (constructeur de copie)


Parser::Parser (const string fileName)
// Algorithme :
//
{
    ifstream logFile;
    logFile.open(fileName);

    string line;
    while (getline(logFile, line))
    {
        Query query(line);
        querySet.insert(query);
    }

    cout << "Nb Exceptions : " << Query::getNbExceptions() << endl;
    cout << "Nb Requêtes : " << querySet.size() << endl;

#ifdef MAP
    cout << "Appel au constructeur de <Parser>" << endl;
#endif
} //----- Fin de Parser


Parser::~Parser ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Parser>" << endl;
#endif
} //----- Fin de ~Parser


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
