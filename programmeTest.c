/*
 -----------------------------------------------------------------------------------
 Nom du fichier : programmeTest.c
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
#include <stdio.h>
#include <inttypes.h>
#include "programmeTest.h"

bool estPaire(size_t position, const Info* info) {
	return *info % 2 == 0;
}

bool estImpaire(size_t position, const Info* info) {
	return *info % 2 != 0;
}

bool positionEtValeurPaires(size_t position, const Info* info) {
	return *info % 2 == 0 && position % 2 == 0;
}

void afficherStatus(Status status) {
	printf("Status : ");
	switch(status) {
		case OK: printf("OK."); break;
		case MEMOIRE_INSUFFISANTE: printf("Memoire insuffisante.");break;
		case LISTE_VIDE: printf("Liste vide."); break;
		case POSITION_NON_VALIDE: printf("Position non valide.");break;
		default: printf("Status inconnu."); break;
	}
	printf("\n");
}

void afficherEstVide(const Liste* liste) {
	if (estVide(liste))
		printf("liste vide.\n");
	else
		printf("liste non vide.\n");
}

void afficherSontEgal(const Liste* liste1, const Liste* liste2) {
	if (sontEgales(liste1, liste2))
		printf("\nLes listes sont egales.\n");
	else
		printf("\nLes listes sont inegales.\n");
}

void programmeTest() {

	// Création des listes ------------------------------------------------------
	Liste* liste1 = initialiser();
	Liste* liste2 = initialiser();

	printf("Premiere liste : ");
	afficher(liste1, FORWARD);
	printf("Deuxieme liste : ");
	afficher(liste2, FORWARD);


	// Test des fonctions d'insertion -------------------------------------------
	Info info = 0;
	Info info1 = 100;
	Info info2 = 58;
	Info info3 = 200;
	Info info4 = 201;
	Info info5 = 202;

	printf("\nInsertion de 3 elements en tete de la premiere liste.\n");
	printf("Status de la premiere insertion en tete : ");
	afficherStatus(insererEnTete(liste1, &info));
	insererEnTete(liste1, &info1);
	insererEnTete(liste1, &info2);
	afficher(liste1, FORWARD);

	printf("\nInsertion de 3 elements en queue de la premiere liste.\n");
	printf("Status de la premiere insertion en queue : ");
	afficherStatus(insererEnQueue(liste1, &info4));
	insererEnQueue(liste1, &info3);
	insererEnQueue(liste1, &info5);
	afficher(liste1, FORWARD);

	// Test de la fonction d'affichage en sens inverse --------------------------
	printf("\nAffichage en mode BACKWARD de la deuxieme liste.\n");
	insererEnTete(liste2, &info);
	insererEnTete(liste2, &info1);
	insererEnTete(liste2, &info2);
	insererEnQueue(liste2, &info3);
	insererEnQueue(liste2, &info4);
	insererEnQueue(liste2, &info5);
	afficher(liste2, BACKWARD);

	// Test de la fonction d'égalité
	afficherSontEgal(liste1, liste2);

	// Test des fonctions de supression -----------------------------------------
	Info supprimerListe1;
	printf("Status apres suppression en queue : ");
	afficherStatus(supprimerEnQueue(liste1, &supprimerListe1));
	printf("\nElement supprime en queue de la premiere liste: %i\n", supprimerListe1);
	afficher(liste1, FORWARD);

	Info supprimerListe2;
	printf("Status apres suppression en tete :");
	afficherStatus(supprimerEnTete(liste2, &supprimerListe2));
	printf("\nElement supprime en tete de la deuxieme liste: %i\n", supprimerListe2);
	afficher(liste2, FORWARD);

	// Test de la fonction vider ------------------------------------------------
	printf("\nPremiere liste de taille %" PRIu64 ": ", longueur(liste1));
	afficher(liste1, FORWARD);
	printf("Deuxieme liste de taille %" PRIu64 ": ", longueur(liste2));
	afficher(liste2, FORWARD);

	printf("\nVide la premiere liste depuis le debut.\n");
	vider(liste1, 0);
	afficher(liste1, FORWARD);

	printf("Première ");
	afficherEstVide(liste1);

	printf("\nInsertion en queue de 3 donnees dans la deuxieme liste.\n");
	insererEnQueue(liste2, &info);
	insererEnQueue(liste2, &info1);
	insererEnQueue(liste2, &info2);
	printf("Deuxieme liste de taille %" PRIu64 ": ", longueur(liste2));
	afficher(liste2, FORWARD);

	printf("Vider la deuxieme liste depuis la position 3.\n");
	vider(liste2, 3);
	afficher(liste2, FORWARD);

	printf("Deuxième ");
	afficherEstVide(liste2);

	printf("\nPremiere liste : ");
	afficher(liste1, FORWARD);
	printf("Deuxieme liste : ");
	afficher(liste2, FORWARD);

	sontEgales(liste1, liste2);

	Info impaire = 3;
	Info paire = 22;
	insererEnQueue(liste1, &impaire);
	insererEnQueue(liste1, &paire);
	insererEnTete(liste1, &impaire);
	insererEnTete(liste1, &paire);
	printf("\n");
	afficher(liste1, FORWARD);
	printf("Suppression d'element(s) impair(s).\n");
	supprimerSelonCritere(liste1, estImpaire);
	afficher(liste1, FORWARD);


	insererEnQueue(liste2, &impaire);
	insererEnQueue(liste2, &paire);
	insererEnTete(liste2, &impaire);
	insererEnTete(liste2, &paire);
	printf("\n");
	afficher(liste2, FORWARD);
	printf("Suppression d'element(s) pair(s).\n");
	supprimerSelonCritere(liste2, estPaire);
	afficher(liste2, FORWARD);

	printf("\n");
	insererEnTete(liste1, &info1);
	insererEnTete(liste1, &info2);
	insererEnQueue(liste1, &info5);
	insererEnQueue(liste1, &info4);
	afficher(liste1, FORWARD);
	printf("Suppression d'element(s) pairs aux positions paires.\n");
	supprimerSelonCritere(liste1, positionEtValeurPaires);
	afficher(liste1, FORWARD);

   vider(liste1, 0);
   vider(liste2, 0);
	free(liste1);
	liste1 = NULL;
	free(liste2);
	liste2 = NULL;
}
