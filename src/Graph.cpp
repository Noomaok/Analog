/*************************************************************************
                           Graph  -  description
                             -------------------
    début                : 13/02/2019
    copyright            : (C) 2019 par Baptiste Lotigier et Téo Bouvard
*************************************************************************/

//---------- Réalisation de la classe <Graph> (fichier Graph.cpp) ------------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
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
void Graph::createGraphFile(string graph_fileName, unsigned int nArcs)
{
    //flip map to get graph arcs sorted by hits
    multimap<int,string> flipped_nodeLinks = flip_map(nodeLinks);
    multimap<int,string>::reverse_iterator r_it;

    ofstream graphFile;
    graphFile.open(graph_fileName.c_str());

    graphFile << "digraph{" << endl;

    //iterate through multimap until N_GRAPH elements have been added to the graph (or end of multimap)
    for (r_it = flipped_nodeLinks.rbegin(); distance(flipped_nodeLinks.rbegin(),r_it) < nArcs && r_it != flipped_nodeLinks.rend(); r_it++)
    {
        vector<string> nodes = split(r_it->second,'|');

        graphFile << "\"" << nodes.back() << "\" -> \"" << nodes.front() << "\"";
        graphFile << " [label=\"" << r_it->first << "\"]" << endl;
    }

    graphFile << "}";

} //----- Fin de createGraphFile

void Graph::printHits()
{
    //flip map to get URL sorted by hits
    multimap<int,string> flipped_pageHits = flip_map(pageHits);
    multimap<int,string>::reverse_iterator r_it;

    cout << endl << "10 most requested URL sorted by hits :" << endl;
    //iterate through multimap until N_PRINT elements have been printed (or end of multimap)
    for (r_it = flipped_pageHits.rbegin(); distance(flipped_pageHits.rbegin(),r_it) < N_PRINT && r_it != flipped_pageHits.rend(); r_it++)
    {
        cout << setw(30) << left << r_it->second << " (" << r_it->first << " hits)" << endl;
    }
    cout << endl;
} //----- Fin de printHits

//-------------------------------------------- Constructeurs - destructeur
Graph::Graph (set<Query>& querySet)
{
    for (set<Query>::iterator it = querySet.begin(); it != querySet.end(); it++)
    {
        //fill nodeLinks map with concatenated URL and hits counter
        string concatenated_URL = it->GetRequestURL() + '|' + it->GetRefererURL();
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

        //fill pageHits map with requested URL and hits counter
        if (pageHits.find(it->GetRequestURL()) == pageHits.end())
        {
            // not found
            pageHits.insert(make_pair(it->GetRequestURL(),1));
        }
        else
        {
            // found
            map<string,int>::iterator found = pageHits.find(it->GetRequestURL());
            found->second++;
        }
    }
#ifdef MAP
    cout << "Appel au constructeur de <Graph>" << endl;
#endif
} //----- Fin du constructeur de Graph
