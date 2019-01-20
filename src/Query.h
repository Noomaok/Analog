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
#include <vector>
#include <iostream>
#include <string>

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef struct Date_t{
    int day;
    string mounth;
    int year;
    int hour;
    int minute;
    int second;
    int offset;
} Date_t;

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
    vector<string> Split(string strToSplit, char delimiter);
    void RemoveEmptyStrings(vector<string>& strings);
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    friend bool operator<(const Query& q1, const Query& q2);
    friend ostream& operator<<(ostream& os, const Query& q);
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

    Query(string dataIn);
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

    string IPClient;
    string UserLogName;
    string AuthenticatedUser;
    Date_t DateOfQuery;
    string ActionType;
    string RequestURL;
    string Protocol;
    int ReturnCode;
    int DataSent;
    string RefererURL;
    string LocalURL;
    string BrowserClient;
};

//-------------------------------- Autres définitions dépendantes de <Query>

#endif // QUERY_H
