/*************************************************************************
                           Parser  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Parser> (fichier Parser.h) ----------------
#if ! defined ( PARSER_H )
#define PARSER_H

//--------------------------------------------------- Interfaces utilisées
#include <set>
#include <string>

#include "Query.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Parser>
//
//
//------------------------------------------------------------------------

class Parser
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void SendDataToGraph(bool createGraph, string graph_fileName);
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void filterURLs(string contain);

//------------------------------------------------- Surcharge d'opérateurs
    Parser & operator = ( const Parser & unParser );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Parser ( const Parser & unParser );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Parser (string log_fileName);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Parser ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    set<Query> querySet;
};

//-------------------------------- Autres définitions dépendantes de <Parser>

#endif // PARSER_H
