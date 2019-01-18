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
using namespace std;

//------------------------------------------------------ Include personnel
#include "Query.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Query::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Query & Query::operator = ( const Query & unQuery )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Query::Query ( const Query & unQuery )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Query>" << endl;
#endif
} //----- Fin de Query (constructeur de copie)


Query::Query ( )
// Algorithme :
//
{
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
