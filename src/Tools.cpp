#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include "Tools.h"

using namespace std;

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

bool isCharacter(string s){
    return s == "" || s == " ";
}

void RemoveEmptyStrings(vector<string>& strings)
{
  vector<string>::iterator it = remove_if(strings.begin(), strings.end(),isCharacter);
  //erase the removed elements
  strings.erase(it, strings.end());
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

