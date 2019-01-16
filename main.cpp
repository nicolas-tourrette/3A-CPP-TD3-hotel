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

int main(){
    Hotel au_bon_dodo(4, 45.0, "Au Bon Dodo") ;
    cout << "L'hôtel créé se nomme : " << au_bon_dodo.getNom() << "." << endl ;
    cout << "L'hôtel créé a        : " << au_bon_dodo.getNombreChambres() << " chambres." << endl ;
    cout << "Une chambre coûte     : " << au_bon_dodo.getPrixChambres() << "€." << endl ;
    cout << au_bon_dodo << endl ;
    au_bon_dodo.setPrixChambres(50.0) ;
    cout << au_bon_dodo << endl ;
    cout << "Le chiffre d'affaire maximal journalier pour l'hôtel \"Au Bon Dodo\" est de " << au_bon_dodo.getChiffreAffaireMax() << "€." << endl ;

    Hotel sans_nom(0, 256.0) ;
    cout << sans_nom << endl ;
    sans_nom.setNom("Sans sommeil") ;
    sans_nom.setPrixChambres(120.0) ;

    au_bon_dodo.setOccupation(0,1) ;
    au_bon_dodo.setOccupation(2,1) ;
    au_bon_dodo.setOccupation(4,1) ;

    au_bon_dodo.getOccupation() ;

    Hotel au_bon_dodo2 = au_bon_dodo ;
    au_bon_dodo2.setPrixChambres(45.0) ;
    cout << au_bon_dodo2 << endl ;
    au_bon_dodo2.getOccupation() ;
    cout << au_bon_dodo << endl ;

    cout << "Le chiffre d'affaire réel de " << au_bon_dodo.getNom() << " est de " << au_bon_dodo.getChiffreAffaire() << "€." << endl ;

    return EXIT_SUCCESS ;
}
