/*************************************************************************
                           Tools  -  description
                             -------------------
    début                : 13/02/2019
    copyright            : (C) 2019 par Baptiste Lotigier et Téo Bouvard
*************************************************************************/

//---------- Interface du module <Tools> (fichier Tools.h) -------------------
#if ! defined ( TOOLS_H )
#define TOOLS_H

//------------------------------------------------------------------------
// Rôle du module <Tools>
// Permet d'utiliser des méthodes génériques dans plusieurs classes.
//
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
        Renvoie un vecteur de strings correspondant aux sous-strings
*/

template <typename A, typename B>
pair<B,A> flip_pair(const pair<A,B> &p);
/*
    Mode d'emploi :
        p -> pair à inverser
    Contrat :
        Renvoie une pair avec les éléments inversés
*/

multimap<int,string> flip_map(const map<string,int>& src);
/*
    Mode d'emploi :
        src -> map à retourner
    Contrat :
        Renvoie une multimap correspondant à l'inversion des pair
        de tous les éléments de la map src.
*/

#endif // TOOLS_H
