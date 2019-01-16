/*******************************************
    Programme   : hotel
    Fichier     : hotel.cpp
    Objectif    : implémentation de la classe hôtel
    Auteur      : Nicolas TOURRETTE (ESIREM Dijon) - nicolas_tourrette@etu.u-bourgogne.fr
    Date        : 15-01-2019
    Version     : V1
********************************************/

#include "hotel.hpp"

Hotel::Hotel(int nombre_chambres, float prix_chambres, string nom_hotel){
    if(nombre_chambres < 0){
        nombre_chambres = -nombre_chambres ;
        cerr << "\n** Une correction a été faite sur le nombre de chambres, il était négatif **" << endl ;
    }
    else if(nombre_chambres == 0){
        nombre_chambres++ ;
        cerr << "\n** Une correction a été faite sur le nombre de chambres, il était nul **" << endl ;
        cerr << "**    Vous avez maintenant par défaut une chambre dans votre hôtel    **" << endl ;
    }
    if(prix_chambres <= 0){
        prix_chambres = -prix_chambres ;
        cerr << "\n** Une correction a été faite sur le prix des chambres, il était négatif **" << endl ;
    }
    m_nom_hotel = nom_hotel ;
    m_nombre_chambres = nombre_chambres ;
    m_prix_chambres = prix_chambres ;
    m_occupation = new int[nombre_chambres] ;
    m_chiffre_affaire = 0.0 ;
    cout << "\n-------------------------------------------" << endl ;
    cout << "Création de l'hôtel " << m_nom_hotel << " :" << endl ;
    cout << "   - Nombre de chambres : " << m_nombre_chambres << endl ;
    cout << "   - Prix des chambres  : " << m_prix_chambres << "€" << endl ;
}

Hotel::Hotel(const Hotel& un_hotel){
    m_nom_hotel = un_hotel.m_nom_hotel + "_COPIE" ;
    m_nombre_chambres = un_hotel.m_nombre_chambres ;
    m_prix_chambres = un_hotel.m_prix_chambres ;
    m_occupation = un_hotel.m_occupation ;
    m_chiffre_affaire = un_hotel.m_chiffre_affaire ;
    cout << "\n-------------------------------------------" << endl ;
    cout << "Création de la copie de l'hôtel " << m_nom_hotel << " :" << endl ;
    cout << "   - Nombre de chambres : " << m_nombre_chambres << endl ;
    cout << "   - Prix des chambres  : " << m_prix_chambres << "€" << endl ;
}

Hotel::~Hotel(){
    delete[] m_occupation ;
    cout << "\n-------------------------------------------" << endl ;
    cout << "Hôtel " << m_nom_hotel << " détruit." << endl ;
}

string Hotel::getNom() const{
    return m_nom_hotel ;
}

void Hotel::setNom(string nom_hotel){
    cout << "\n-------------------------------------------" << endl ;
    cout << "Renommage de l'hôtel " << m_nom_hotel << " en " << nom_hotel << "." << endl ;
    m_nom_hotel = nom_hotel ;
}

int Hotel::getNombreChambres(){
    return m_nombre_chambres ;
}

float Hotel::getPrixChambres(){
    return m_prix_chambres ;
}

void Hotel::setPrixChambres(float prix_chambres){
    m_prix_chambres = prix_chambres ;
    cout << "\n-------------------------------------------" << endl ;
    cout << "Le prix des chambres de l'hôtel " << m_nom_hotel << " est désormais de " << prix_chambres << "€." << endl ;
}

float Hotel::getChiffreAffaireMax(){
    return (float)m_nombre_chambres*m_prix_chambres ;
}

float Hotel::getChiffreAffaire (){
    int nombre_chambres_occupees = 0 ;
    for(int i=0 ; i<m_nombre_chambres ; i++){
        if(m_occupation[i] >= 1){
            nombre_chambres_occupees++ ;
        }
    }
    m_chiffre_affaire = (float)nombre_chambres_occupees*m_prix_chambres ;
    //cout << "Chiffre affaire calculé : " << m_chiffre_affaire << endl ;

    return m_chiffre_affaire ;
}

void Hotel::setOccupation(int numero_chambre, int etat_occupation){
    if(etat_occupation < 0){
        cerr << "** L'occupation ne peut pas être définie **" << endl ;
    }
    else{
        m_occupation[numero_chambre] = etat_occupation ;
        cout << "\n-------------------------------------------" << endl ;
        cout << "Modification de l'occupation de l'hôtel " << m_nom_hotel << " :" << endl ;
        if(etat_occupation == 0){
            cout << "La chambre " << numero_chambre << " a été marquée comme libérée." << endl ;
        }
        else{
            cout << "La chambre " << numero_chambre << " a été marquée comme occupée par " << etat_occupation << " personne(s)." << endl ;
        }
    }
}

void Hotel::getOccupation(){
    cout << "\n-------------------------------------------" << endl ;
    cout << "Affichage de l'occupation de l'hôtel " << m_nom_hotel << " :" << endl ;
    for(int i=0 ; i<m_nombre_chambres ; i++){
        if(m_occupation[i] == 0){
            cout << "La chambre " << i+1 << " est libre." << endl ;
        }
        else{
            cout << "La chambre " << i+1 << " est occupée par " << m_occupation[i] << " personne(s)." << endl ;
        }
    }
}

ostream& operator <<(ostream& flux, Hotel& un_hotel) {
    flux << "\n-------------------------------------------" << endl ;
    flux << "Affichage de l'hôtel " << un_hotel.m_nom_hotel << " :" << endl ;
    flux << "   - Nombre de chambres        : " << un_hotel.m_nombre_chambres << endl ;
    flux << "   - Prix des chambres         : " << un_hotel.m_prix_chambres << endl ;
    flux << "   - CA maximal journalier     : " << (float)un_hotel.m_nombre_chambres*un_hotel.m_prix_chambres << "€." << endl ;
    flux << "   - Chiffre d'affaire courant : " << un_hotel.getChiffreAffaire() << "€." << endl ;

    return flux ;
}
