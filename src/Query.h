/*************************************************************************
                           Query  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Query> (fichier Query.h) ----------------
#if ! defined ( QUERY_H )
#define QUERY_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Query>
//
//
//------------------------------------------------------------------------

class Query
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Query & operator = ( const Query & unQuery );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Query ( const Query & unQuery );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Query ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Query ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Query>

#endif // QUERY_H
