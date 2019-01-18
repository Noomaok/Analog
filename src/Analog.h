/*************************************************************************
                           Analog  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Analog> (fichier Analog.h) ----------------
#if ! defined ( ANALOG_H )
#define ANALOG_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Analog>
//
//
//------------------------------------------------------------------------

class Analog
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Analog & operator = ( const Analog & unAnalog );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Analog ( const Analog & unAnalog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Analog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Analog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Analog>

#endif // ANALOG_H
