/*************************************************************************
                           Parser  -  description
                             -------------------
    début                : 13/02/2019
    copyright            : (C) 2019 par Baptiste Lotigier et Téo Bouvard
*************************************************************************/

//---------- Interface de la classe <Parser> (fichier Parser.h) ----------------
#if ! defined ( PARSER_H )
#define PARSER_H

//--------------------------------------------------- Interfaces utilisées
#include <set>
#include <string>

#include "Query.h"

//------------------------------------------------------------------------
// Rôle de la classe <Parser>
// Analyser et traiter chaque ligne du fichier log afin de créer une liste
// de requêtes valide. 
// Filtrer cette liste de requêtes selon les options utilisées.
//------------------------------------------------------------------------

class Parser
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void SendDataToGraph(bool convertGraph, string graph_fileName, unsigned int nArcs = 10);
    /*
        Mode d'emploi :
            convertGraph -> condition pour générer le fichier dot
            graph_fileName -> nom du graphe à générer
            nArcs -> nombre d'arcs a utiliser pour le graphe, valeur par défaut 10
        Contrat :
            Crée un objet graph pour finir l'analyse du fichier
    */

    void FilterURLs(string contain);
    /*
        Mode d'emploi :
            contain -> chaîne de caractère utilisée pour filtrer les urls des requêtes
        Contrat :
            Supprime du set les requêtes qui ne contiennent pas la chaîne de caractères
    */

    void FilterHour(int hour);
    /*
        Mode d'emploi :
            hour -> heure utilisée pour filtrer les dates des requêtes
        Contrat :
            Supprime du set les requêtes qui ne se trouvent pas dans la tranche horaire [hour; hour+1[ 
    */

    void RemoveUndefined();
    /*
        Contrat:
            Supprime du set les requêtes qui n'ont pas d'url referer (URL Undefined)
    */

//-------------------------------------------- Constructeurs - destructeur

    Parser (const string log_fileName, const string host_url);
    /*
        Mode d'emploi :
            log_fileName -> nom du fichier log à analyser
            host_url -> nom de l'URL locale du fichier log
        Contrat :
            Ouvre et analyse chaque ligne du fichier.
            La vérification de l'exitence du fichier doit être faite au préalable
    */

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    set<Query> querySet;
};

#endif // PARSER_H
