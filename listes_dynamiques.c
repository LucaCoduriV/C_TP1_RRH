/*
 -----------------------------------------------------------------------------------
 Nom du fichier : listes_dynamiques.h
 Auteur(s)      : Luca Coduri & Chloé Fontaine & Tania Nunez
 Date creation  : 22.04.2021

 Description    : Ce fichier contient l'implémentation de toutes les fonctions
                  mettant en oeuvre l'instanciation, la manipulation et la
                  destruction de listes chaînées non circulaires.

 Remarque(s)    : Les fonctions insererEnTete et insererEnQueue vérifient que le
                  paramètre info n'est pas égal à NULL. Si c'est le cas, on
                  attribue à info la valeur de 0 par défaut. Nous avons choisi
                  cette option car aucun statut de l'enum de statuts ne
                  correspond à cette situation.

 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include "listes_dynamiques.h"

Liste* initialiser(){
	Liste* liste = (Liste*) malloc(sizeof(Liste));
	if(!liste) return NULL;
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
   while (courant){
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

   if(!nouvelleTete){
      return MEMOIRE_INSUFFISANTE;
   }

   // Insérer l'élément en première position
   if (info != NULL) nouvelleTete->info = *info;
   else nouvelleTete->info = 0;
   nouvelleTete->suivant = liste->tete;
   nouvelleTete->precedent = NULL;

   // Déplacer l'ancienne tête en deuxième position
   if(liste->tete) {
		liste->tete->precedent = nouvelleTete;
   } else {
      liste->queue = nouvelleTete;
   }
   liste->tete = nouvelleTete;

   return OK;
}

Status insererEnQueue(Liste* liste, const Info* info){
   Element* nouvelleQueue = malloc(sizeof(Element));

   if(!nouvelleQueue){
      return MEMOIRE_INSUFFISANTE;
   }

   // Insérer l'élément en dernière position
   if (info != NULL) nouvelleQueue->info = *info;
   else nouvelleQueue->info = 0;
   nouvelleQueue->precedent = liste->queue;
   nouvelleQueue->suivant = NULL;

   // Déplacer l'ancienne queue en avant dernière position
   if(liste->queue) {
		liste->queue->suivant = nouvelleQueue;
   } else {
      liste->tete = nouvelleQueue;
   }
   liste->queue = nouvelleQueue;

   return OK;
}

Status supprimerEnTete(Liste* liste, Info* info){
	if (estVide(liste)) {
		return LISTE_VIDE;
	}
   if (info != NULL) *info = liste->tete->info;

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
	if (info != NULL) *info = liste->queue->info;

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
				Info info;

				if (element == liste->tete) {
					supprimerEnTete(liste, &info);
					element = liste->tete;
				} else if (element == liste->queue) {
					supprimerEnQueue(liste, &info);
				} else {
					Element* tmp = element;
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
	if (!estVide(liste)) {
		int nbElements = (int)longueur(liste) - (int)position;
		for (int i = 0; i < nbElements; ++i) {
			supprimerEnQueue(liste, NULL);
		}
	}
}

bool sontEgales(const Liste* liste1, const Liste* liste2){
   Element* tete1 = liste1->tete;
   Element* tete2 = liste2->tete;

   while(tete1) {
      if(!tete2 || tete1->info != tete2->info){
			return false;
      }
      tete1 = tete1->suivant;
      tete2 = tete2->suivant;
   }

   // Si la liste 2 est plus grande que la liste 1, elles ne sont pas égales.
   if(tete2){
		return false;
   }

   return true;
}
