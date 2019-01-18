/*******************************************
    Programme   : hotel
    Fichier     : chambre.cpp
    Objectif    : implémentation de la classe Chambre
    Auteur      : Nicolas TOURRETTE (ESIREM Dijon) - nicolas_tourrette@etu.u-bourgogne.fr
    Date        : 18-01-2019
    Version     : V1
********************************************/

#include "chambre.hpp"

Chambre::Chambre(int numero_chambre, string type_chambre, float prix_chambre) : m_numero_chambre(numero_chambre), m_type_chambre(type_chambre) {
    if(prix_chambre <= 0){
        prix_chambre = -prix_chambre ;
        cerr << "\n** Une correction a été faite sur le prix des chambres, il était négatif **" << endl ;
    }
    m_prix_chambre = prix_chambre ;
    m_etat_chambre = 0 ;
    cout << "\n-------------------------------------------" << endl ;
    cout << "Création de la chambre n°" << m_numero_chambre << " :" << endl ;
    cout << "   - Type de chambre    : " << m_type_chambre << endl ;
    cout << "   - Prix de la chambre : " << m_prix_chambre << "€" << endl ;
    cout << "   - Disponibilité      : " << getEtatChambre() << endl ;
}

int Chambre::getNumeroChambre(){
    return m_numero_chambre ;
}

string Chambre::getTypeChambre(){
    return m_type_chambre ;
}

int Chambre::getEtatChambre(){
    return m_etat_chambre ;
}

void Chambre::setEtatChambre(int etat_occupation){
    if(etat_occupation < 0){
        cerr << "** L'occupation ne peut pas être définie **" << endl ;
    }
    else{
        m_etat_chambre = etat_occupation ;
        /*cout << "\n-------------------------------------------" << endl ;
        cout << "Modification de la chambre n°" << m_numero_chambre << " :" << endl ;
        if(etat_occupation == 0){
            cout << "La chambre " << m_numero_chambre << " a été marquée comme libérée." << endl ;
        }
        else{
            cout << "La chambre " << m_numero_chambre << " a été marquée comme occupée par " << etat_occupation << " personne(s)." << endl ;
        }*/
    }
}

float Chambre::getPrixChambre(){
    return m_prix_chambre ;
}

void Chambre::setPrixChambre(float prix_chambre){
    if(prix_chambre <= 0){
        prix_chambre = -prix_chambre ;
        cerr << "\n** Une correction a été faite sur le prix des chambres, il était négatif **" << endl ;
    }
    m_prix_chambre = prix_chambre ;
    cout << "\n-------------------------------------------" << endl ;
    cout << "Modification de la chambre n°" << m_numero_chambre << " :" << endl ;
    cout << "   - Nouveau prix de la chambre : " << m_prix_chambre << "€" << endl ;
}

ostream& operator <<(ostream& flux, Chambre& une_chambre) {
    flux << "\n-------------------------------------------" << endl ;
    cout << "Affichage de la chambre n°" << une_chambre.m_numero_chambre << " :" << endl ;
    cout << "   - Type de chambre    : " << une_chambre.m_type_chambre << endl ;
    cout << "   - Prix de la chambre : " << une_chambre.m_prix_chambre << "€" << endl ;

    return flux ;
}
