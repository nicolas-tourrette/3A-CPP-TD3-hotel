/*******************************************
    Programme   : hotel
    Fichier     : hotel.cpp
    Objectif    : implémentation de la classe hôtel
    Auteur      : Nicolas TOURRETTE (ESIREM Dijon) - nicolas_tourrette@etu.u-bourgogne.fr
    Date        : 15-01-2019
    Version     : V1
********************************************/

#include "hotel.hpp"

Hotel::Hotel(int nombre_chambres, string nom_hotel){
    if(nombre_chambres < 0){
        nombre_chambres = -nombre_chambres ;
        cerr << "\n** Une correction a été faite sur le nombre de chambres, il était négatif **" << endl ;
    }
    else if(nombre_chambres == 0){
        nombre_chambres++ ;
        cerr << "\n** Une correction a été faite sur le nombre de chambres, il était nul **" << endl ;
        cerr << "**    Vous avez maintenant par défaut une chambre dans votre hôtel    **" << endl ;
    }
    m_nom_hotel = nom_hotel ;
    m_nombre_chambres = nombre_chambres ;
    for(int i=0 ; i<nombre_chambres ; i++){
        int numero_chambre ; float prix_chambre ; string type_chambre ;
        cout << "\nSaisir le numéro de la chambre : " ;
        cin >> numero_chambre ;
        cout << "Saisir le prix de la chambre   : " ;
        cin >> prix_chambre ;
        cout << "Saisir le type de la chambre   : " ;
        cin >> type_chambre ;
        Chambre une_chambre(numero_chambre, type_chambre, prix_chambre) ;
        m_chambres.push_back(une_chambre) ;
    }
    m_chiffre_affaire = 0.0 ;
    cout << "\n-------------------------------------------" << endl ;
    cout << "Création de l'hôtel " << m_nom_hotel << " :" << endl ;
    cout << "   - Nombre de chambres : " << m_nombre_chambres << endl ;
}

Hotel::Hotel(const Hotel& un_hotel){
    m_nom_hotel = un_hotel.m_nom_hotel + "_COPIE" ;
    m_nombre_chambres = un_hotel.m_nombre_chambres ;
    m_chiffre_affaire = un_hotel.m_chiffre_affaire ;
    m_chambres = un_hotel.m_chambres ;
    cout << "\n-------------------------------------------" << endl ;
    cout << "Création de la copie de l'hôtel " << m_nom_hotel << " :" << endl ;
    cout << "   - Nombre de chambres : " << m_nombre_chambres << endl ;
}

Hotel::~Hotel(){
    //delete[] m_occupation ;
    m_chambres.clear() ;
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

float Hotel::getChiffreAffaireMax(){
    float chiffre_affaire_max = 0 ;
    for(int i=0 ; i<m_nombre_chambres ; i++){
        chiffre_affaire_max += m_chambres[i].getPrixChambre() ;
    }
    return chiffre_affaire_max ;
}

float Hotel::getChiffreAffaire (){
    m_chiffre_affaire = 0 ;
    for(int i=0 ; i<m_nombre_chambres ; i++){
        if(m_chambres[i].getEtatChambre() >= 1){
            m_chiffre_affaire += m_chambres[i].getPrixChambre() ;
        }
    }

    return m_chiffre_affaire ;
}

void Hotel::setOccupation(int numero_chambre, int etat_occupation){
    if(etat_occupation < 0){
        cerr << "** L'occupation ne peut pas être définie **" << endl ;
    }
    else{
        m_chambres[numero_chambre-1].setEtatChambre(etat_occupation) ;
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
        if(m_chambres[i].getEtatChambre() == 0){
            cout << "La chambre " << i+1 << " est libre." << endl ;
        }
        else{
            cout << "La chambre " << i+1 << " est occupée par " << m_chambres[i].getEtatChambre() << " personne(s)." << endl ;
        }
    }
}

void Hotel::setPrixChambre(int numero_chambre, float prix_chambre){
    if(prix_chambre <= 0){
        prix_chambre = -prix_chambre ;
        cerr << "\n** Une correction a été faite sur le prix des chambres, il était négatif **" << endl ;
    }
    cout << "\nHôtel " << m_nom_hotel ;
    m_chambres[numero_chambre-1].setPrixChambre(prix_chambre) ;
}

ostream& operator <<(ostream& flux, Hotel& un_hotel){
    flux << "\n-------------------------------------------" << endl ;
    flux << "Affichage de l'hôtel " << un_hotel.m_nom_hotel << " :" << endl ;
    flux << "   - Nombre de chambres        : " << un_hotel.m_nombre_chambres << endl ;
    flux << "   - CA maximal journalier     : " << un_hotel.getChiffreAffaireMax() << "€." << endl ;
    flux << "   - Chiffre d'affaire courant : " << un_hotel.getChiffreAffaire() << "€." << endl ;

    return flux ;
}
