/*******************************************
    Programme   : hotel
    Fichier     : main.cpp ## MAINFILE
    Objectif    : réaliser la gestion d'un hôtel
    Auteur      : Nicolas TOURRETTE (ESIREM Dijon) - nicolas_tourrette@etu.u-bourgogne.fr
    Date        : 15-01-2019
    Version     : V1
********************************************/

//using namespace std ;

#include "hotel.hpp"
#include "chambre.hpp"
#include "reservation.hpp"

int main(){
    srand(time(NULL)) ;
    /*Hotel au_bon_dodo(2, "Au Bon Dodo") ;
    cout << "L'hôtel créé se nomme : " << au_bon_dodo.getNom() << "." << endl ;
    cout << "L'hôtel créé a        : " << au_bon_dodo.getNombreChambres() << " chambres." << endl ;
    cout << au_bon_dodo << endl ;
    cout << "Le chiffre d'affaire maximal journalier pour l'hôtel \"Au Bon Dodo\" est de " << au_bon_dodo.getChiffreAffaireMax() << "€." << endl ;

    Chambre ma_chambre(101, "single", 45.0) ;
    ma_chambre.setEtatChambre(2) ;
    ma_chambre.setPrixChambre(150) ;
    cout << ma_chambre << endl ;

    au_bon_dodo.setOccupation(1,9) ;
    au_bon_dodo.getOccupation() ;

    Hotel au_bon_dodo2 = au_bon_dodo ;
    au_bon_dodo2.setPrixChambre(2,70) ;
    au_bon_dodo2.setOccupation(2,3) ;
    au_bon_dodo2.getOccupation() ;

    cout << au_bon_dodo2 << endl ;*/

    Reservation ma_reservation("M. GINHAC Dominique", 45, 18012019, 19012019) ;
    cout << ma_reservation << endl ;

    return EXIT_SUCCESS ;
}
