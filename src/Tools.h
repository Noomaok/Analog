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
/* 
    Mode d'emploi :
        strToSplit -> string à découper
        delimiter -> caractère autour duquel strToSplit sera découpé
    Contrat :
        renvoie un vecteur de strings correspondant aux sous-strings
*/

void RemoveEmptyStrings(vector<string>& strings);
/* 
    Mode d'emploi :
        strings -> vecteur de strings à épurer
    Contrat :
        renvoie un vecteur correspondant au vecteur initial moins les
        éléments supprimés (string vide et blanc souligné)
*/
pair<int,string> flip_pair(const pair<string,int> &p);
multimap<int,string> flip_map(const map<string,int>& src);

#endif // TOOLS_H


