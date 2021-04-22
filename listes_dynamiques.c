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

#include <stdlib.h>
#include "listes_dynamiques.h"
#include <stdlib.h>
#include <stdio.h>
Liste* initialiser(){
	Liste* liste = (Liste*) malloc(sizeof(Liste));
	liste->queue = NULL;
	liste->tete = NULL;
   return liste;
}

bool estVide(const Liste* liste){

}

size_t longueur(const Liste* liste){

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
   Element* newTete = malloc(sizeof(Element));

   if(newTete == NULL){
      return MEMOIRE_INSUFFISANTE;
   }
   newTete->info = *info;
   newTete->suivant = liste->tete;
   newTete->precedent = NULL;

   if(liste->tete != NULL)
      liste->tete->precedent = newTete;
   liste->tete = newTete;

   return OK;
}

Status insererEnQueue(Liste* liste, const Info* info){
   Element* newQueue = malloc(sizeof(Element));

   if(newQueue == NULL){
      return MEMOIRE_INSUFFISANTE;
   }
   newQueue->info = *info;
   newQueue->precedent = liste->queue;
   newQueue->suivant = NULL;

   if(liste->queue != NULL)
      liste->queue->suivant = newQueue;
   liste->queue = newQueue;

   return OK;
}

Status supprimerEnTete(Liste* liste, Info* info){

}

Status supprimerEnQueue(Liste* liste, Info* info){

}

void supprimerSelonCritere(Liste* liste,
                           bool (*critere)(size_t position, const Info* info)){

}

void vider(Liste* liste, size_t position){

}

bool sontEgales(const Liste* liste1, const Liste* liste2){

}
