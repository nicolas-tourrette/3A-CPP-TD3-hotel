/*******************************************
    Programme   : hotel
    Fichier     : chambre.hpp
    Objectif    : fichier contenant la classe d'une chambre d'hôtel
    Auteur      : Nicolas TOURRETTE (ESIREM Dijon) - nicolas_tourrette@etu.u-bourgogne.fr
    Date        : 18-01-2019
    Version     : V1
********************************************/

#ifndef CHAMBRE_HPP
#define CHAMBRE_HPP

#include <iostream>
#include <string>

using namespace std;

class Chambre{
    private:
    int m_numero_chambre ;
    string m_type_chambre ;
    int m_etat_chambre ;
    float m_prix_chambre ;

    public:
    Chambre(int numero_chambre, string type_chambre, float prix_chambre) ;
    int getNumeroChambre() ;
    string getTypeChambre() ;
    int getEtatChambre() ;
    void setEtatChambre(int etat_occupation) ;
    float getPrixChambre() ;
    void setPrixChambre(float prix_chambre) ;

    friend ostream& operator <<(ostream& flux, Chambre& une_chambre) ;
} ;

#endif
