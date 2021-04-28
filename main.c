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

   Liste* maListe = initialiser();
   Liste* maListe2 = initialiser();


   Info info = 0;
   Info info1 = 100;
   Info info2 = 58;
   Info info3 = 200;
   Info info4 = 201;
   Info info5 = 202;

   printf("Premiere liste : ");
   afficher(maListe, FORWARD);
   printf("Deuxieme liste : ");
   afficher(maListe2, FORWARD);

   printf("\nInsertion de 3 elements en tete de la premiere liste.\n");
   insererEnTete(maListe, &info);
   insererEnTete(maListe, &info1);
   insererEnTete(maListe, &info2);
   afficher(maListe, FORWARD);

   printf("\nInsertion de 3 elements en queue de la premiere liste.\n");
   insererEnQueue(maListe, &info3);
   insererEnQueue(maListe, &info4);
   insererEnQueue(maListe, &info5);
   afficher(maListe, FORWARD);

   printf("\nAffichage en mode BACKWARD de la deuxieme liste.\n");
   insererEnTete(maListe2, &info);
   insererEnTete(maListe2, &info1);
   insererEnTete(maListe2, &info2);
   insererEnQueue(maListe2, &info3);
   insererEnQueue(maListe2, &info4);
   insererEnQueue(maListe2, &info5);
   afficher(maListe2, BACKWARD);

   if (sontEgales(maListe, maListe2)) printf("Les listes sont egales,\n");
   else printf("Les listes sont inegales.\n");

   Info supprimerListe1;
   supprimerEnQueue(maListe, &supprimerListe1);
   printf("\nElement supprime en queue de la premiere liste: %i\n", supprimerListe1);
   afficher(maListe, FORWARD);


   Info supprimerListe2;
   supprimerEnTete(maListe2, &supprimerListe2);
   printf("\nElement supprime en tete de la deuxieme liste: %i\n", supprimerListe2);
   afficher(maListe2, FORWARD);

   afficher(maListe, FORWARD);
   printf("\nVide la premiere liste depuis le debut.\n");
   vider(maListe, 0);
   afficher(maListe, FORWARD);

   afficher(maListe2, FORWARD);
   insererEnTete(maListe2, &info);
   insererEnTete(maListe2, &info1);
   insererEnTete(maListe2, &info2);
   printf("Vide la deuxieme liste depuis la position 1.\n");
   vider(maListe2, 1);
   afficher(maListe2, FORWARD);


   printf("Premiere liste : ");
   afficher(maListe, FORWARD);
   printf("Deuxieme liste : ");
   afficher(maListe2, FORWARD);


   if (sontEgales(maListe, maListe2)) printf("Les listes sont égales,\n");
   else printf("Les listes sont inegales.\n");


   Info impaire = 3;
   Info paire = 22;
   insererEnQueue(maListe, &impaire);
   insererEnQueue(maListe, &paire);
   insererEnTete(maListe, &impaire);
   insererEnTete(maListe, &paire);
   afficher(maListe, FORWARD);
   printf("Suppression d'element(s) impair(s).\n");
   supprimerSelonCritere(maListe, estImpaire);
   afficher(maListe, FORWARD);


   insererEnQueue(maListe2, &impaire);
   insererEnQueue(maListe2, &paire);
   insererEnTete(maListe2, &impaire);
   insererEnTete(maListe2, &paire);
   afficher(maListe2, FORWARD);
   printf("Suppression d'element(s) pair(s).\n");
   supprimerSelonCritere(maListe2, estPaire);
   afficher(maListe2, FORWARD);

   free(maListe);
   free(maListe2);
   return 0;
}
