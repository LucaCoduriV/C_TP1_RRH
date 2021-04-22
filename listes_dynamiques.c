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
   return liste->queue == NULL && liste->tete == NULL;
}

size_t longueur(const Liste* liste){
   size_t taille = 0;
   Element* courant = liste->tete;
   while (courant != NULL){
      courant = courant->suivant;
      taille++;
   }
   return taille;
}

void afficher(const Liste* liste, Mode mode){
   Element* courant;
   if (mode == FORWARD) {
      courant = liste->tete;
      while(courant != NULL) {
         printf("%d ", courant->info);
         courant = courant->suivant;
      }
   }
   else if (mode == BACKWARD){
      courant = liste->queue;
      while(courant != NULL) {
         printf("%d ", courant->info);
         courant = courant->precedent;
      }
   }
   printf("\n");
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
   else{
      liste->queue = newTete;
   }
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
   else{
      liste->tete = newQueue;
   }
   liste->queue = newQueue;

   return OK;
}

Status supprimerEnTete(Liste* liste, Info* info){

   return OK;
}

Status supprimerEnQueue(Liste* liste, Info* info){
	if (estVide(liste)) {
		return LISTE_VIDE;
	}
	*info = liste->queue->info;
	free(liste->queue);
   return OK;
}

void supprimerSelonCritere(Liste* liste,
                           bool (*critere)(size_t position, const Info* info)){

}

void vider(Liste* liste, size_t position){
   Element* current = liste->tete;
   for(int i = 0; i < position;i++){
      if(current->suivant != NULL)
         current = current->suivant;
   }
   if(position != 0){
      current->precedent->suivant = NULL;
      liste->queue = current->precedent;
   }else{
      liste->tete = NULL;
      liste->queue = NULL;
   }


   while(current != NULL){
      Element* next = current->suivant;
      free(current);
      current = next;
   }
}

bool sontEgales(const Liste* liste1, const Liste* liste2){

}
