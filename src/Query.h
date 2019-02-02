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
    string month;
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
    inline string getRequestURL() const { return RequestURL; };
    inline string getRefererURL() const { return RefererURL; };
    inline int getHour() const { return DateOfQuery.hour; };

    void makeDate(string strToConvert);
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
    Query ( const Query & aQuery );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Query(const string dataIn, const string host_url);
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    //Data from query line
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
    string BrowserClient;

    //Name of local website
    string HostURL;
};

//-------------------------------- Autres définitions dépendantes de <Query>

#endif // QUERY_H
