/*************************************************************************
                           Query  -  description
                             -------------------
    début                : 13/02/2019
    copyright            : (C) 2019 par Baptiste Lotigier et Téo Bouvard
*************************************************************************/

//---------- Interface de la classe <Query> (fichier Query.h) ----------------
#if ! defined ( QUERY_H )
#define QUERY_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <iostream>
#include <string>

using namespace std;

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
// Contient toutes les informations d'une requête du fichier log.
//
//------------------------------------------------------------------------

class Query
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    inline string GetRequestURL() const { return RequestURL; };
    /*
        Contrat :
            Renvoie l'URL demandée par la requête
    */

    inline string GetRefererURL() const { return RefererURL; };
    /*
        Contrat :
            Renvoie l'URL d'origine de la requête
    */

    inline int GetHour() const { return DateOfQuery.hour; };
    /*
        Contrat :
            Renvoie l'heure d'execution de la requête
    */

    void MakeDate(string strToConvert);
    /*
        Mode d'emploi :
            strToConvert -> chaîne de caractères à analyser
        Contrat :
            Crée une instance de la structure Date avec les informations contenues dans strToConvert
    */


//------------------------------------------------- Surcharge d'opérateurs
    friend bool operator<(const Query& q1, const Query& q2);
    /*
        Contrat :
            Renvoie true. Necessaire pour l'insertion dans un set.
    */

    friend ostream& operator<<(ostream& os, const Query& q);
    /*
        Contrat :
            Réalise l'affichage de la requête dans le flux utilisé
    */


//-------------------------------------------- Constructeurs - destructeur
    Query(const Query & aQuery);
    /*
        Mode d'emploi :
            aQuery -> objet Query à copier
        Contrat :
            Copie les attributs de aQuery dans la nouvelle instance de Query
    */

    Query(const string dataIn, const string host_url);
    /*
        Mode d'emploi :
            dataIn -> ligne de fichier log contenant les informations d'une requête
            host_url -> URL locale du log
        Contrat :
            Récupère les informations de dataIn et les stocke dans les attributs de la classe
    */

//------------------------------------------------------------------ PRIVE

protected:
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

#endif // QUERY_H
