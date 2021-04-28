/*
 -----------------------------------------------------------------------------------
 Nom du fichier : programmeTest.h
 Auteur(s)      : Luca Coduri & Chloé Fontaine & Tania Nunez
 Date creation  : 03.04.2021

 Description    : Ce fichier contient l'implémentation de toutes les fonctions
                  mettant en oeuvre l'instanciation, la manipulation et la
                  destruction de listes chainées.

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#ifndef C_TP1_RRH_PROGRAMMETEST_H
#define C_TP1_RRH_PROGRAMMETEST_H

#include "listes_dynamiques.h"

bool estPaire(size_t position, const Info* info);

bool estImpaire(size_t position, const Info* info);

bool positionEtValeurPaires(size_t position, const Info* info);

void afficherStatus(Status status);

void afficherEstVide(const Liste* liste);

void afficherSontEgal(const Liste* liste1, const Liste* liste2);

void programmeTest();

#endif //C_TP1_RRH_PROGRAMMETEST_H
