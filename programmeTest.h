/*
 -----------------------------------------------------------------------------------
 Nom du fichier : programmeTest.h
 Auteur(s)      : Luca Coduri & Chloé Fontaine & Tania Nunez
 Date creation  : 22.04.2021

 Description    : Ce fichier contient les prototypes des fonctions du programme de
 						test de la structure Liste (implémentée dams listes_dynamiques.h).

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#ifndef C_TP1_RRH_PROGRAMMETEST_H
#define C_TP1_RRH_PROGRAMMETEST_H

#include "listes_dynamiques.h"

bool estPaire(size_t position, const Info *info);

bool estImpaire(size_t position, const Info *info);

bool positionEtValeurPaires(size_t position, const Info *info);

void afficherStatus(Status status);

void afficherEstVide(const Liste *liste);

void afficherSontEgal(const Liste *liste1, const Liste *liste2);

// Entrée du programme de test
void programmeTest();

#endif //C_TP1_RRH_PROGRAMMETEST_H
