/*************************************************************************
                           Tools  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface du module <Tools> (fichier Tools.h) -------------------
#if ! defined ( TOOLS_H )
#define TOOLS_H

//------------------------------------------------------------------------
// Rôle du module <Tools>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

#include <vector>
#include <string>
#include <map>

using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

vector<string> Split(string strToSplit, char delimiter);
void RemoveEmptyStrings(vector<string>& strings);

pair<int,string> flip_pair(const pair<string,int> &p);
multimap<int,string> flip_map(const map<string,int>& src);

#endif // TOOLS_H


