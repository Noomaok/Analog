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

//------------------------------------------------------------- Constantes

#define QUERY_LENGTH 11

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool isCharacter(string s)
{
    return s == " " || s == "";
}

vector<string> Query::Split(string strToSplit, char delimiter)
{
    stringstream ss(strToSplit);
    string item;
    vector<string> splittedString;

    while(getline(ss, item, delimiter))
    {
        splittedString.push_back(item);
    }
    return splittedString;
}

void Query::RemoveEmptyStrings(vector<string>& strings)
{
  vector<string>::iterator it = remove_if(strings.begin(), strings.end(),isCharacter);
  //erase the removed elements
  strings.erase(it, strings.end());
}

//------------------------------------------------- Surcharge d'opérateurs
//Query & Query::operator = ( const Query & unQuery )
// Algorithme :
//
//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Query::Query ( const Query & unQuery )
// Algorithme :
//
{
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
    //RefererURL = query_elements.at(10);

    
#ifdef MAP
    cout << "Appel au constructeur de <Query>" << endl;

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
