/*************************************************************************
                           Query  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Query> (fichier Query.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Query.h"
#include "Tools.h"

//------------------------------------------------------------- Constantes
static int nbExceptions = 0;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int Query::getNbExceptions() { return nbExceptions; }

void Query::makeDate(string strToConvert)
{
    vector<string> date_mainelement = Split(strToConvert,' ');
    vector<string> date_day = Split(date_mainelement.front(),'/');
    vector<string> date_hour = Split(date_day.back(),':');

    DateOfQuery.day = atoi(date_day.front().c_str());
    DateOfQuery.mounth = date_day.at(1);
    DateOfQuery.year = atoi(date_day.at(2).c_str());
    DateOfQuery.hour = atoi(date_hour.at(1).c_str());
    DateOfQuery.minute = atoi(date_hour.at(2).c_str());
    DateOfQuery.second = atoi(date_hour.back().c_str());
    DateOfQuery.offset = atoi(date_mainelement.back().c_str());
}

//------------------------------------------------- Surcharge d'opérateurs

ostream& operator<<(ostream& os, const Query& q)
{
    os << "-----------------------------------------" << setfill('0') << endl;
    os << q.IPClient << " " << q.UserLogName << " " << q.AuthenticatedUser << endl;
    os << "[" << q.DateOfQuery.day << "/" << q.DateOfQuery.mounth << "/" << q.DateOfQuery.year << " " << setw(2) << q.DateOfQuery.hour << ":" << setw(2) << q.DateOfQuery.minute << ":" << setw(2) << q.DateOfQuery.second << "]" << endl;
    os << q.ActionType << " " << q.RequestURL << " " << q.Protocol << endl;
    os << q.ReturnCode << " " << q.DataSent << endl;
    os << q.RefererURL <<endl;
    os << q.BrowserClient << setfill(' ');
    return os;
}

//opérateur de comparaison nécéssaire à l'insert dans un set
bool operator < (const Query& q1, const Query& q2)
{
    return (q1.IPClient < q2.IPClient
            || q1.DateOfQuery.hour < q2.DateOfQuery.hour
            || q1.DateOfQuery.minute < q2.DateOfQuery.minute
            || q1.DateOfQuery.second < q2.DateOfQuery.second
            || q1.DateOfQuery.day < q2.DateOfQuery.day
            || q1.DateOfQuery.mounth < q2.DateOfQuery.mounth
            || q1.DateOfQuery.year < q2.DateOfQuery.year);
}

//-------------------------------------------- Constructeurs - destructeur
Query::Query (const Query & aQuery)
{
    IPClient = aQuery.IPClient;
    RequestURL = aQuery.RequestURL;
    RefererURL = aQuery.RefererURL;

#ifdef MAP
    cout << "Appel au constructeur de copie de <Query>" << endl;
#endif
} //----- Fin de Query (constructeur de copie)


Query::Query(string dataIn)
{
    //TODO : make it a changeable parameter
    LocalURL = "http://intranet-if.insa-lyon.fr";

    //Make all the split needed
    vector<string> query_elements = Split(dataIn, '"');
    vector<string> query_ipdate = Split(query_elements.front(),'[');
    vector<string> query_ipIdent = Split(query_ipdate.front(), ' ');
    vector<string> query_URL = Split(query_elements.at(1), ' ');
    string code = query_elements.at(2);
    vector<string> query_codebyte = Split(code.substr(1,code.length()-1),' ');
    string completeRefUrl = query_elements.at(3);

    //affect data to correct variable
    IPClient = query_ipIdent.front();
    UserLogName = query_ipIdent.at(1);
    AuthenticatedUser = query_ipIdent.back();
    makeDate(query_ipdate.at(1).substr(0,query_ipdate.at(1).length()-2));
    ActionType = query_URL.front();
    RequestURL = query_URL.at(1);
    Protocol = query_URL.back();
    ReturnCode = atoi(query_codebyte.front().c_str());
    DataSent = atoi(query_codebyte.back().c_str());

    //Special handle for RefererURL variable
    if(completeRefUrl.find(LocalURL) == string::npos)
    {
        if(completeRefUrl.find("http") == string::npos)
        {
            RefererURL = "Undefined";
        }
        else
        {
            vector<string> urlProccess = Split(completeRefUrl, '/');
            RefererURL = urlProccess.at(2);
        }
    }
    else
    {
        RefererURL = completeRefUrl.substr(LocalURL.length(),completeRefUrl.length());
    }

    BrowserClient = query_elements.back();

#ifdef MAP
    cout << "Appel au constructeur de <Query>" << endl;
    cout << *this << endl;
#endif
} //----- Fin de Query


Query::~Query ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Query>" << endl;
#endif
} //----- Fin de ~Query


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
