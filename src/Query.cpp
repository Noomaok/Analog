/*************************************************************************
                           Query  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Query> (fichier Query.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Query.h"
#include "Tools.h"

//------------------------------------------------------------- Constantes
static int nbExceptions = 0;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int Query::getNbExceptions() { return nbExceptions; }

//------------------------------------------------- Surcharge d'opérateurs

ostream& operator<<(ostream& os, const Query& q)
{
    os << q.IPClient << endl;
    os << q.RequestURL << endl;
    os << q.RefererURL;
    return os;
}

//opérateur de comparaison nécéssaire à l'insert du set
bool operator<(const Query& q1, const Query& q2)
{
    return (q1.IPClient < q2.IPClient);
}

//-------------------------------------------- Constructeurs - destructeur
Query::Query (const Query & aQuery)
{
    IPClient = aQuery.IPClient;
    RequestURL = aQuery.RequestURL;
    RefererURL = aQuery.RefererURL;

#ifdef MAP
    cout << "Appel au constructeur de copie de <Query>" << endl;
#endif
} //----- Fin de Query (constructeur de copie)


Query::Query(string dataIn)
{
    vector<string> query_elements = Split(dataIn, '"');
    vector<string> query_URL = Split(query_elements.at(1), ' ');
    vector<string> query_referer_URL = Split(query_elements.at(3), '/');

    //a optimiser
    RemoveEmptyStrings(query_elements);
    RemoveEmptyStrings(query_referer_URL);

    //TODO : check if query format is adequate 
    IPClient = query_elements.at(0);
    RequestURL = query_URL.at(1);

    try 
    {
        RefererURL = "/" + query_referer_URL.at(2);
    }
    catch (const exception& e) 
    {
        nbExceptions++;
    }
    
    
#ifdef MAP
    cout << "Appel au constructeur de <Query>" << endl;

    /*
    for(int i=0; i<query_elements.size(); i++)
    {
        cout << "query_elements(" << i << ") : " << query_elements.at(i) << endl;
    }

    for(int i=0; i<query_URL.size(); i++)
    {
        cout << "query_URL(" << i << ") : " << query_URL.at(i) << endl;
    }

    for(int i=0; i<query_referer_URL.size(); i++)
    {
        cout << "query_referer_URL(" << i << ") : " << query_referer_URL.at(i) << endl;
    }
    */

#endif
} //----- Fin de Query


Query::~Query ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Query>" << endl;
#endif
} //----- Fin de ~Query


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
