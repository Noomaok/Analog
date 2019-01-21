#ifndef TOOLS_H
#define TOOLS_H

#include <vector>
#include <string>
#include <map>

using namespace std;

vector<string> Split(string strToSplit, char delimiter);
void RemoveEmptyStrings(vector<string>& strings);


pair<int,string> flip_pair(const pair<string,int> &p);

multimap<int,string> flip_map(const map<string,int>& src);

#endif
