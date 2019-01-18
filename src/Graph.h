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
    void createGraphFile();
    
    // Mode d'emploi :
    //
    // Contrat :
    //





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

    Graph (set<Query> queryList);
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

};

//-------------------------------- Autres définitions dépendantes de <Graph>

#endif // GRAPH_H
