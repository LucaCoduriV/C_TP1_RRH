/*
 -----------------------------------------------------------------------------------
 Nom du fichier : main.c
 Auteur(s)      : Luca Coduri & Chloé Fontaine & Tania Nunez
 Date creation  : 03.04.2021

 Description    : Ce fichier met en oeuvre le test des différentes fonctionnalités
                  des listes chainées implémentées dans le fichier
                  listes_dynamiques.h. Le test crée et manipule deux objets de
                  cette classe.

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#include <stdio.h>
#include "listes_dynamiques.h"
#include <stdlib.h>

bool estPaire(size_t position, const Info* info) {
	return *info % 2 == 0;
}

bool estImpaire(size_t position, const Info* info) {
   return *info % 2 != 0;
}

void afficherStatus(Status status) {
   printf("Status : ");
   switch(status) {
      case OK: printf("OK.");
      case MEMOIRE_INSUFFISANTE: printf("Memoire insuffisante.");
      case LISTE_VIDE: printf("Liste vide.");
      case POSITION_NON_VALIDE: printf("Position non valide.");
      default: printf("Status inconnu.");
   }
   printf("\n");
}

int main() {

   Liste* Liste1 = initialiser();
   Liste* Liste2 = initialiser();


   Info info = 0;
   Info info1 = 100;
   Info info2 = 58;
   Info info3 = 200;
   Info info4 = 201;
   Info info5 = 202;

   printf("Premiere liste : ");
   afficher(Liste1, FORWARD);
   printf("Deuxieme liste : ");
   afficher(Liste2, FORWARD);

   printf("\nInsertion de 3 elements en tete de la premiere liste.\n");
   insererEnTete(Liste1, &info);
   insererEnTete(Liste1, &info1);
   insererEnTete(Liste1, &info2);
   afficher(Liste1, FORWARD);

   printf("\nInsertion de 3 elements en queue de la premiere liste.\n");
   insererEnQueue(Liste1, &info3);
   insererEnQueue(Liste1, &info4);
   insererEnQueue(Liste1, &info5);
   afficher(Liste1, FORWARD);

   printf("\nAffichage en mode BACKWARD de la deuxieme liste.\n");
   insererEnTete(Liste2, &info);
   insererEnTete(Liste2, &info1);
   insererEnTete(Liste2, &info2);
   insererEnQueue(Liste2, &info3);
   insererEnQueue(Liste2, &info4);
   insererEnQueue(Liste2, &info5);
   afficher(Liste2, BACKWARD);

   printf("\n");
   if (sontEgales(Liste1, Liste2)) printf("Les listes sont egales.\n");
   else printf("Les listes sont inegales.\n");

   Info supprimerListe1;
   supprimerEnQueue(Liste1, &supprimerListe1);
   printf("\nElement supprime en queue de la premiere liste: %i\n", supprimerListe1);
   afficher(Liste1, FORWARD);


   Info supprimerListe2;
   supprimerEnTete(Liste2, &supprimerListe2);
   printf("\nElement supprime en tete de la deuxieme liste: %i\n", supprimerListe2);
   afficher(Liste2, FORWARD);

   printf("\n");
   printf("Premiere liste de taille %i: ", longueur(Liste1));
   afficher(Liste1, FORWARD);
   printf("Deuxieme liste de taille %i: ", longueur(Liste2));
   afficher(Liste2, FORWARD);

   printf("\nVide la premiere liste depuis le debut.\n");
   vider(Liste1, 0);
   afficher(Liste1, FORWARD);
   if (estVide(Liste1)) printf("Liste vide.");
   else printf("Liste non vide.");

   insererEnTete(Liste2, &info);
   insererEnTete(Liste2, &info1);
   insererEnTete(Liste2, &info2);
   printf("Vide la deuxieme liste depuis la position 3.\n");
   vider(Liste2, 3);
   afficher(Liste2, FORWARD);
   if (estVide(Liste2)) printf("Liste vide.");
   else printf("Liste non vide.");
   printf("\n");

   printf("Premiere liste : ");
   afficher(Liste1, FORWARD);
   printf("Deuxieme liste : ");
   afficher(Liste2, FORWARD);


   if (sontEgales(Liste1, Liste2)) printf("Les listes sont égales.\n");
   else printf("Les listes sont inegales.\n");


   Info impaire = 3;
   Info paire = 22;
   insererEnQueue(Liste1, &impaire);
   insererEnQueue(Liste1, &paire);
   insererEnTete(Liste1, &impaire);
   insererEnTete(Liste1, &paire);
   printf("\n");
   afficher(Liste1, FORWARD);
   printf("Suppression d'element(s) impair(s).\n");
   supprimerSelonCritere(Liste1, estImpaire);
   afficher(Liste1, FORWARD);


   insererEnQueue(Liste2, &impaire);
   insererEnQueue(Liste2, &paire);
   insererEnTete(Liste2, &impaire);
   insererEnTete(Liste2, &paire);
   printf("\n");
   afficher(Liste2, FORWARD);
   printf("Suppression d'element(s) pair(s).\n");
   supprimerSelonCritere(Liste2, estPaire);
   afficher(Liste2, FORWARD);

   free(Liste1);
   free(Liste2);
   return 0;
}
