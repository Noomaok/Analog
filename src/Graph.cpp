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
#include <fstream>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Graph.h"
#include "Tools.h"
#include "Query.h"

//------------------------------------------------------------- Constantes
#define N_PRINT 10
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Graph::createGraphFile(string graph_fileName)
{
    ofstream graphFile;
    graphFile.open(graph_fileName.c_str());

    graphFile << "digraph{" << endl;
    graphFile << "A->B" << endl;
    graphFile << "}";
} //----- Fin de Méthode

void Graph::printHits()
{
    //flip map to get URL sorted by hits
    multimap<int,string> flipped_pageHits = flip_map(pageHits);
    multimap<int,string>::reverse_iterator r_it;

    //iterate through multimap until N_PRINT elements have been printed or end of multimap
    for (r_it = flipped_pageHits.rbegin(); distance(flipped_pageHits.rbegin(),r_it) < N_PRINT && r_it != flipped_pageHits.rend(); r_it++)
    {
        cout << setw(25) << left << r_it->second << " (" << r_it->first << " hits)" << endl;
    }
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


Graph::Graph (set<Query>& querySet)
{
    for (set<Query>::iterator it = querySet.begin(); it != querySet.end(); it++)
    {
        //fill nodeLinks map with concatenated URL and hits counter
        string concatenated_URL = it->getRequestURL() + '|' + it->getRefererURL();
        if (nodeLinks.find(concatenated_URL) == nodeLinks.end() )
        {
            // not found
            nodeLinks.insert(make_pair(concatenated_URL,1));
        }
        else
        {
            // found
            map<string,int>::iterator found = nodeLinks.find(concatenated_URL);
            found->second++;
        }

        //fill pageHits map with concatenated URL and hits counter
        if (pageHits.find(it->getRequestURL()) == pageHits.end())
        {
            // not found
            pageHits.insert(make_pair(it->getRequestURL(),1));
        }
        else
        {
            // found
            map<string,int>::iterator found = pageHits.find(it->getRequestURL());
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
