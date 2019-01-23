/*************************************************************************
                           Graph  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Graph> (fichier Graph.h) ----------------
#if ! defined ( GRAPH_H )
#define GRAPH_H

//--------------------------------------------------- Interfaces utilisées

#include <set>
#include <map>

#include "Query.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Graph>
//
//
//------------------------------------------------------------------------

class Graph
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void createGraphFile(string graph_fileName);

    void printHits();
    /*
    Contrat :
    Affiche les N_PRINT pages les plus consultées (ou l'intégralité des hits
    si le log en contient moins)
    Si certaines pages ont le même nombre de hits, elles sont ordonnées par
    ordre alphabétique décroissant
    */


//------------------------------------------------- Surcharge d'opérateurs
    Graph & operator = ( const Graph & unGraph );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Graph ( const Graph & unGraph );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Graph (set<Query>& queryList);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Graph ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    map<string,int> nodeLinks;
    map<string,int> pageHits;
    map<int,string> graphNodes;
};

//-------------------------------- Autres définitions dépendantes de <Graph>

#endif // GRAPH_H
