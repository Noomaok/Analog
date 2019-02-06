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

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
//type Nom ( liste de paramètres )
// Algorithme :
//

vector<string> split(string strToSplit, char delimiter)
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
template <typename A, typename B>
pair<B,A> flip_pair(const pair<A,B> &p)
{
    return pair<B,A>(p.second, p.first);
}

multimap<int,string> flip_map(const map<string,int>& src)
{
    multimap<int,string> dst;
    transform(src.begin(), src.end(), inserter(dst, dst.begin()), flip_pair<string,int>);
    return dst;
}
