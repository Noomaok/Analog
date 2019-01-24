/*************************************************************************
                           Tools  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <Tools> (fichier Tools.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm> //for remove_if
#include <map>

using namespace std;
//------------------------------------------------------ Include personnel
#include "Tools.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
//type Nom ( liste de paramètres )
// Algorithme :
//

vector<string> Split(string strToSplit, char delimiter)
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

//flip map(key,value) into multimap(value,key)
pair<int,string> flip_pair(const pair<string,int> &p)
{
    return pair<int,string>(p.second, p.first);
}

multimap<int,string> flip_map(const map<string,int>& src)
{
    multimap<int,string> dst;
    transform(src.begin(), src.end(), inserter(dst, dst.begin()), flip_pair);
    return dst;
}
