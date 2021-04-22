/*
 -----------------------------------------------------------------------------------
 Nom du fichier : listes_dynamiques.h
 Auteur(s)      : René Rentsch
 Date creation  : 03.04.2021

 Description    : Librairie permettant la gestion de listes doublement chaînées
                  non circulaires

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#include "listes_dynamiques.h"
#include <stdlib.h>
#include <stdio.h>
Liste* initialiser(){
   return NULL;
}

bool estVide(const Liste* liste){
   return NULL;
}

size_t longueur(const Liste* liste){
   return NULL;
}

void afficher(const Liste* liste, Mode mode){
   if (mode == FORWARD) {
      Element* courant = liste->tete;
      while(courant != NULL) {
         printf("%d ", courant->info);
         courant = courant->suivant;
      }
   }
   else {
      Element* courant = liste->queue;
      while(courant != NULL) {
         printf("%d ", courant->info);
         courant = courant->precedent;
      }
   }
}

Status insererEnTete(Liste* liste, const Info* info){
   return NULL;
}

Status insererEnQueue(Liste* liste, const Info* info){
   return NULL;
}

Status supprimerEnTete(Liste* liste, Info* info){
   return NULL;
}

Status supprimerEnQueue(Liste* liste, Info* info){
   return NULL;
}

void supprimerSelonCritere(Liste* liste,
                           bool (*critere)(size_t position, const Info* info)){

}

void vider(Liste* liste, size_t position){

}

bool sontEgales(const Liste* liste1, const Liste* liste2){
   return NULL;
}
