#ifndef TOOLS_H
#define TOOLS_H

#include <vector>
#include <string>

using namespace std;

vector<string> Split(string strToSplit, char delimiter);
void RemoveEmptyStrings(vector<string>& strings);

#endif
