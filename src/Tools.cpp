#include <iostream>
#include <sstream>
#include <vector>
#include <string>
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
