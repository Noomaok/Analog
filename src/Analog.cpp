/*************************************************************************
                           Analog  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Analog> (fichier Analog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Analog.h"
#include "Parser.h"
#include "Query.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Analog::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

int main(int argc, char * argv[])
{
    bool createGraph = true;

    Parser p("tmp/court.log");
    p.SendDataToGraph(createGraph,"tmp/graphTest");
    //system("dot -Tpng tmp/graphTest.png tmp/graphTest.dot");
}


//------------------------------------------------- Surcharge d'opérateurs
//Analog & Analog::operator = ( const Analog & unAnalog )
// Algorithme :
//
//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Analog::Analog ( const Analog & unAnalog )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Analog>" << endl;
#endif
} //----- Fin de Analog (constructeur de copie)


Analog::Analog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Analog>" << endl;
#endif
} //----- Fin de Analog


Analog::~Analog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Analog>" << endl;
#endif
} //----- Fin de ~Analog


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
