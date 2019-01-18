/*******************************************
    Programme   : hotel
    Fichier     : hotel.hpp
    Objectif    : fichier contenant la classe de l'hôtel
    Auteur      : Nicolas TOURRETTE (ESIREM Dijon) - nicolas_tourrette@etu.u-bourgogne.fr
    Date        : 15-01-2019
    Version     : V1
********************************************/

#ifndef HOTEL_HPP
#define HOTEL_HPP

#include "chambre.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Hotel{
    private:
    string m_nom_hotel ;
    int m_nombre_chambres ;
    vector<Chambre> m_chambres ;
    float m_chiffre_affaire ;

    public:
    Hotel(int nombre_chambres, string nom_hotel = "*VOID*") ;
    Hotel(const Hotel& un_hotel) ;
    ~Hotel() ;
    string getNom() const ;
    void setNom(string nom_hotel) ;
    int getNombreChambres() ;
    void setOccupation(int numero_chambre, int etat_occupation) ;
    void getOccupation() ;
    float getChiffreAffaireMax() ;
    float getChiffreAffaire() ;
    void setPrixChambre(int numero_chambre, float prix_chambre) ;

    friend ostream& operator <<(ostream& flux, Hotel& un_hotel) ;
} ;

#endif
