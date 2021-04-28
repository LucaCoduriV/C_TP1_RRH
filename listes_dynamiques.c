/*
 -----------------------------------------------------------------------------------
 Nom du fichier : listes_dynamiques.h
 Auteur(s)      : Luca Coduri & Chloé Fontaine & Tania Nunez
 Date creation  : 03.04.2021

 Description    : Ce fichier contient l'implémentation de toutes les fonctions
                  mettant en oeuvre l'instanciation, la manipulation et la
                  destruction de listes chainées.

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include "listes_dynamiques.h"
#include <stdio.h>

Liste* initialiser(){
	Liste* liste = (Liste*) malloc(sizeof(Liste));
	liste->queue = NULL;
	liste->tete = NULL;
   return liste;
}

bool estVide(const Liste* liste){
   return liste->tete == NULL;
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
   printf("[");
   if (mode == FORWARD) {
      courant = liste->tete;
      while(courant) {
			courant->suivant ? printf("%d, ", courant->info) :
									 printf("%d", courant->info);
			courant = courant->suivant;
      }
   } else if (mode == BACKWARD){
      courant = liste->queue;
      while(courant) {
			courant->precedent ? printf("%d, ", courant->info) :
									   printf("%d", courant->info);
         courant = courant->precedent;
      }
   }
   printf("]\n");
}

Status insererEnTete(Liste* liste, const Info* info){
   Element* nouvelleTete = malloc(sizeof(Element));

   if(nouvelleTete == NULL){
      return MEMOIRE_INSUFFISANTE;
   }
   nouvelleTete->info = *info;
   nouvelleTete->suivant = liste->tete;
   nouvelleTete->precedent = NULL;

   if(liste->tete != NULL)
      liste->tete->precedent = nouvelleTete;
   else{
      liste->queue = nouvelleTete;
   }
   liste->tete = nouvelleTete;

   return OK;
}

Status insererEnQueue(Liste* liste, const Info* info){
   Element* nouvelleQueue = malloc(sizeof(Element));

   if(nouvelleQueue == NULL){
      return MEMOIRE_INSUFFISANTE;
   }
   nouvelleQueue->info = *info;
   nouvelleQueue->precedent = liste->queue;
   nouvelleQueue->suivant = NULL;

   if(liste->queue != NULL)
      liste->queue->suivant = nouvelleQueue;
   else{
      liste->tete = nouvelleQueue;
   }
   liste->queue = nouvelleQueue;

   return OK;
}

Status supprimerEnTete(Liste* liste, Info* info){
	if (estVide(liste)) {
		return LISTE_VIDE;
	}
	*info = liste->tete->info;

	if (longueur(liste) == 1) {
		free(liste->tete);
		liste->queue = NULL;
		liste->tete = NULL;
	} else {
		liste->tete = liste->tete->suivant;
		free(liste->tete->precedent);
		liste->tete->precedent = NULL;
	}

   return OK;
}

Status supprimerEnQueue(Liste* liste, Info* info) {
	if (estVide(liste)) {
		return LISTE_VIDE;
	}
	*info = liste->queue->info;

	if (longueur(liste) == 1) {
		free(liste->tete);
		liste->queue = NULL;
		liste->tete = NULL;
	} else {
		liste->queue = liste->queue->precedent;
		free(liste->queue->suivant);
		liste->queue->suivant = NULL;
	}

   return OK;
}

void supprimerSelonCritere(Liste* liste,
                           bool (*critere)(size_t position, const Info* info)) {
	if (!estVide(liste)) {
		Element *element = liste->tete;
	   size_t taille = longueur(liste);
		for (size_t pos = 0; pos < taille; ++pos) {

			if (critere(pos, &(element->info))) {
				Element* tmp = element;
				Info info;

				if (element == liste->tete) {
					supprimerEnTete(liste, &info);
					element = liste->tete;

				} else if (element == liste->queue) {
					supprimerEnQueue(liste, &info);
				} else {
					element->precedent->suivant = element->suivant;
					element->suivant->precedent = element->precedent;
					element = element->suivant;
					free(tmp);
				}

			} else {
				element = element->suivant;
			}
		}
	}
}

void vider(Liste* liste, size_t position){
   Element* courant = liste->tete;
   for(int i = 0; i < position;i++){
      if(courant->suivant != NULL)
         courant = courant->suivant;
   }
   if(position != 0){
      courant->precedent->suivant = NULL;
      liste->queue = courant->precedent;
   }else{
      liste->tete = NULL;
      liste->queue = NULL;
   }

   while(courant != NULL){
      Element* next = courant->suivant;
      free(courant);
      courant = next;
   }
}

bool sontEgales(const Liste* liste1, const Liste* liste2){
   Element* tete1 = liste1->tete;
   Element* tete2 = liste2->tete;
   bool estEgal = true;

   while(tete1 != NULL){
      if(!tete2 || tete1->info != tete2->info){
         estEgal = false;
         break;
      }
      tete1 = tete1->suivant;
      tete2 = tete2->suivant;
   }
   if(tete2 != NULL){
      estEgal = false;
   }

   return estEgal;
}
