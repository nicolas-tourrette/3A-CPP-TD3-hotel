/*******************************************
    Programme   : hotel
    Fichier     : reservation.cpp
    Objectif    : implémentation de la classe Reservation
    Auteur      : Nicolas TOURRETTE (ESIREM Dijon) - nicolas_tourrette@etu.u-bourgogne.fr
    Date        : 18-01-2019
    Version     : V1
********************************************/

#include "reservation.hpp"

Reservation::Reservation(string client, int numero_chambre, int date_debut, int date_fin){
    if(numero_chambre <= 0){
        numero_chambre = -numero_chambre ;
        cerr << "\n** Une correction a été faite sur le nombre de chambres, il était négatif **" << endl ;
    }
    if(client != ""){
        if(date_debut <= 0 || date_debut <= 0 || date_fin-date_debut < 0){
            cerr << "\n** Une erreur s'est produite : dates invalides **" << endl ;
        }
        else{
            m_reservation_id = rand()%998 + 1 ;
            m_client = client ;
            m_numero_chambre = numero_chambre ;
            m_date_debut = date_debut ;
            m_date_fin = date_fin ;
            cout << "\n-------------------------------------------" << endl ;
            cout << "Création de la réservation de la chambre n°" << m_numero_chambre << " :" << endl ;
            cout << "   - N° de réservation            : " << m_reservation_id << endl ;
            cout << "   - Client pour la réservation   : " << m_client << endl ;
            cout << "   - Date de début et date de fin : du " << m_date_debut << " au " << m_date_fin << endl ;
        }
    }
    else{
        cerr << "\n** Une erreur s'est produite : nom de client vide **" << endl ;
    }
}


int Reservation::getReservationId(){
    return m_reservation_id ;
}

string Reservation::getClient(){
    return m_client ;
}

int Reservation::getNumeroChambre(){
    return m_numero_chambre ;
}

void Reservation::setNumeroChambre(int numero_chambre){
    if(numero_chambre <= 0){
        numero_chambre = -numero_chambre ;
        cerr << "\n** Une correction a été faite sur le nombre de chambres, il était négatif **" << endl ;
    }
    m_numero_chambre = numero_chambre ;
    cout << "\n-------------------------------------------" << endl ;
    cout << "Modification de la réservation n°" << m_reservation_id << " :" << endl ;
    cout << "*  - N° de la nouvelle chambre    : " << m_numero_chambre << endl ;
    cout << "   - Client pour la réservation   : " << m_client << endl ;
    cout << "   - Date de début et date de fin : du " << m_date_debut << " au " << m_date_fin << endl ;
}

int Reservation::getDateDebut(){
    return m_date_debut ;
}

int Reservation::getDateFin(){
    return m_date_fin ;
}

void Reservation::setDate(int date_debut, int date_fin){
    if(date_debut <= 0 || date_debut <= 0 || date_fin-date_debut < 0){
        cerr << "\n** Une erreur s'est produite : dates invalides **" << endl ;
    }
    else{
        m_date_debut = date_debut ;
        m_date_fin = date_fin ;
        cout << "\n-------------------------------------------" << endl ;
        cout << "Modification de la réservation de la chambre n°" << m_numero_chambre << " :" << endl ;
        cout << "   - N° de réservation            : " << m_reservation_id << endl ;
        cout << "   - Client pour la réservation   : " << m_client << endl ;
        cout << "*  - Date de début et date de fin : du " << m_date_debut << " au " << m_date_fin << endl ;
    }
}

ostream& operator <<(ostream& flux, Reservation& une_reservation){
    flux << "\n-------------------------------------------" << endl ;
    flux << "Affichage de la réservation n°" << une_reservation.m_reservation_id << " :" << endl ;
    flux << "   - N° de chambre                : " << une_reservation.m_numero_chambre << endl ;
    flux << "   - Client pour la réservation   : " << une_reservation.m_client << endl ;
    flux << "   - Date de début et date de fin : du " << une_reservation.m_date_debut << " au " << une_reservation.m_date_fin << endl ;

    return flux ;
}
