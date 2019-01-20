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
using namespace std;

//------------------------------------------------------ Include personnel
#include "Query.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
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
    vector<string> elements = Split(dataIn, ' ');
#ifdef MAP
    cout << "Appel au constructeur de <Query>" << endl;
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
