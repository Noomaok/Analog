/*************************************************************************
                           Graph  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Graph> (fichier Graph.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Graph.h"
#include "Tools.h"

//------------------------------------------------------------- Constantes
//
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Graph::createGraphFile()
// Algorithme :
//
{

} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//Graph & Graph::operator = ( const Graph & unGraph )
// Algorithme :
//
//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Graph::Graph ( const Graph & unGraph )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Graph>" << endl;
#endif
} //----- Fin de Graph (constructeur de copie)


Graph::Graph (set<Query> querySet)
{
    for (set<Query>::iterator it = querySet.begin(); it != querySet.end(); it++)
    {
        string mapKey = it->getRequestURL() + '|' + it->getRefererURL();

        if (nodeLinks.find(mapKey) == nodeLinks.end() ) 
        {
            // not found
            nodeLinks.insert(make_pair(mapKey,1));
        } 
        else 
        {
            // found
            map<string,int>::iterator found = nodeLinks.find(mapKey);
            found->second++;
        }
    }
#ifdef MAP
    cout << "Appel au constructeur de <Graph>" << endl;

    for (map<string,int>::iterator it = nodeLinks.begin(); it != nodeLinks.end(); it++)
    {
        cout << "First : " << it->first << " Second : " << it->second << endl;
    }

#endif
} //----- Fin de Graph


Graph::~Graph ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Graph>" << endl;
#endif
} //----- Fin de ~Graph


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
