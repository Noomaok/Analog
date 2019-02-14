/*************************************************************************
                           Tools  -  description
                             -------------------
    début                : 13/02/2019
    copyright            : (C) 2019 par Baptiste Lotigier et Téo Bouvard
*************************************************************************/

//---------- Réalisation du module <Tools> (fichier Tools.cpp) ---------------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Tools.h"

//----------------------------------------------------------------- PUBLIC
//---------------------------------------------------- Fonctions publiques

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
}//-------Fin de split

template <typename A, typename B>
pair<B,A> flip_pair(const pair<A,B> &p)
{
    return pair<B,A>(p.second, p.first);
}//--------Fin de flip_pair

multimap<int,string> flip_map(const map<string,int>& src)
{
    multimap<int,string> dst;
    transform(src.begin(), src.end(), inserter(dst, dst.begin()), flip_pair<string,int>);
    return dst;
}//--------Fin de flip_map
