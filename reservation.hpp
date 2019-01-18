/*******************************************
    Programme   : hotel
    Fichier     : reservation.hpp
    Objectif    : fichier contenant la classe d'une réservation d'une chambre d'hôtel
    Auteur      : Nicolas TOURRETTE (ESIREM Dijon) - nicolas_tourrette@etu.u-bourgogne.fr
    Date        : 18-01-2019
    Version     : V1
********************************************/

#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class Reservation{
    private:
    int m_reservation_id ;
    string m_client ;
    int m_numero_chambre ;
    int m_date_debut ;
    int m_date_fin ;

    public:
    Reservation(string client, int numero_chambre, int date_debut, int date_fin) ;
    int getReservationId() ;
    string getClient() ;
    int getNumeroChambre() ;
    void setNumeroChambre(int numero_chambre) ;
    int getDateDebut() ;
    int getDateFin() ;
    void setDate(int date_debut, int date_fin) ;

    friend ostream& operator <<(ostream& flux, Reservation& une_reservation) ;

} ;

#endif
