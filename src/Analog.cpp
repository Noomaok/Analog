/*************************************************************************
                           Analog  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Analog> (fichier Analog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Analog.h"
#include "Parser.h"
#include "Query.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Analog::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool nextArgCorrect(int index, int size, char** args, string contain)
{
    if(index+1 < size)
    {
        if(args[index+1][0] != '-')
        {
            string s = args[index+1];
            if(s.find(contain) != string::npos)
                return true;
        }   
    }
    return false;
}

int main(int argc, char* argv[])
{
    string fileName =  "";
    bool createGraph = false;
    string graphOut = "";

    for(int i = 1; i < argc; i++)
    {
        if(argv[i][0] == '-')
        {
            switch (argv[i][1])
            {
                case 'g':
                    createGraph = true;
                    if(nextArgCorrect(i, argc, argv, ".dot"))
                    {
                        graphOut = argv[++i];
                        cout << "Dot-file " << graphOut << " generated" << endl;
                    }
                    else
                    {
                        cerr << "Error : Specify a correct name for the Dot-file" << endl;
                        return 1;
                    }
                    break;
                case 'e':
                    cout << "exclude all document apart from html" << endl;
                    break;
                case 't':
                    cout << "take only hour passed in parameter" << endl;
                    break;
                default:
                    cerr << "Error : Commande incorrect" << endl;
                    return 1;
                    break;
            }
        }
        else
        {
            fileName = argv[i];
        }
    }
    if(fileName == "")
    {
        cerr << "Error : Missing file to analyse" << endl;
        return 1;
    }

    Parser p(fileName);
    p.SendDataToGraph(createGraph,graphOut);
    //system("dot -Tpng tmp/graphTest.png tmp/graphTest.dot");
}

//------------------------------------------------- Surcharge d'opérateurs
//Analog & Analog::operator = ( const Analog & unAnalog )
// Algorithme :
//
//----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Analog::Analog ( const Analog & unAnalog )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Analog>" << endl;
#endif
} //----- Fin de Analog (constructeur de copie)


Analog::Analog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Analog>" << endl;
#endif
} //----- Fin de Analog


Analog::~Analog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Analog>" << endl;
#endif
} //----- Fin de ~Analog


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
