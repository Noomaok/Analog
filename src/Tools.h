/*************************************************************************
                           Tools  -  description
                             -------------------
    début                : 13/02/209
    copyright            : (C) 2019 par Baptiste Lotigier et Téo Bouvard
*************************************************************************/

//---------- Interface du module <Tools> (fichier Tools.h) -------------------
#if ! defined ( TOOLS_H )
#define TOOLS_H

//------------------------------------------------------------------------
// Rôle du module <Tools>
//  Permet d'utiliser des méthodes génériques qui sont utilisé par
//  plusieurs classes.
//------------------------------------------------------------------------

//---------------------------------------------------------------- INCLUDE
//--------------------------------------------------- Interfaces utilisées

#include <vector>
#include <string>
#include <map>

using namespace std;

//----------------------------------------------------------------- PUBLIC
//---------------------------------------------------- Fonctions publiques

vector<string> split(string strToSplit, char delimiter);
/*
    Mode d'emploi :
        strToSplit -> string à découper
        delimiter -> caractère autour duquel strToSplit sera découpé
    Contrat :
        renvoie un vecteur de strings correspondant aux sous-strings
*/

template <typename A, typename B>
pair<B,A> flip_pair(const pair<A,B> &p);
/*
    Mode d'emploi :
        p -> pair à retourner
    Contrat :
        renvoie un pair avec les éléments inversés
*/

multimap<int,string> flip_map(const map<string,int>& src);
/*
    Mode d'emploi :
        src -> map à retourner
    Contrat :
        renvoie une map ayant ces composantes inversées
*/

#endif // TOOLS_H
