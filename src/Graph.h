/*************************************************************************
                           Graph  -  description
                             -------------------
    début                : 13/02/2019
    copyright            : (C) 2019 par Baptiste Lotigier et Téo Bouvard
*************************************************************************/

//---------- Interface de la classe <Graph> (fichier Graph.h) ----------------
#if ! defined ( GRAPH_H )
#define GRAPH_H

//--------------------------------------------------- Interfaces utilisées
#include <set>
#include <map>

#include "Query.h"


//------------------------------------------------------------------------
// Rôle de la classe <Graph>
// Générer les fichiers de sortie et afficher le top 10 des hits du fichier 
// log sur la sortie standard.
//------------------------------------------------------------------------

class Graph
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void createGraphFile(string graph_fileName, unsigned int nArcs);
    /*
        Mode d'emploi :
            graph_fileName -> nom du fichier dot à générer
            nArcs -> nombre d'arcs à prendre en compte dans la création
        Contrat :
            Crée un fichier dot avec le nom fourni et le nombre d'arcs demandé
            Si le nombre d'arcs excède la quantité max d'arcs du fichiers, alors le graph
            s'arrète quand il atteint le max
    */

    void printHits();
    /*
        Contrat :
            Affiche les N_PRINT pages les plus consultées (ou l'intégralité des hits
            si le log en contient moins)
            Si certaines pages ont le même nombre de hits, elles sont ordonnées par
            ordre alphabétique décroissant
    */

//-------------------------------------------- Constructeurs - destructeur

    Graph (set<Query>& queryList);
    /*
        Mode d'emploi :
            queryList -> liste des requête à utiliser pour générer le graph
        Contrat :
            Organise les requêtes passées en paramêtre dans une map pour les 
            trier et les ordonnées
            pour la suite des traitements
    */

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    map<string,int> nodeLinks;
    map<string,int> pageHits;
};

#endif // GRAPH_H
