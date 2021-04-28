/*
 -----------------------------------------------------------------------------------
 Nom du fichier : programmeTest.c
 Auteur(s)      : Luca Coduri & Chloé Fontaine & Tania Nunez
 Date creation  : 22.04.2021

 Description    : Ce fichier contient l'implémentation des fonctions du programme
 						de test.

 Remarque(s)    : -

 Compilateur    : Mingw-w64 gcc 8.1.0
 -----------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <assert.h>
#include "programmeTest.h"

bool estPaire(size_t position, const Info *info) {
	return *info % 2 == 0;
}

bool estImpaire(size_t position, const Info *info) {
	return *info % 2 != 0;
}

bool positionEtValeurPaires(size_t position, const Info *info) {
	return *info % 2 == 0 && position % 2 == 0;
}

void afficherStatus(Status status) {
	printf("Status : ");
	switch (status) {
		case OK:
			printf("OK.\n");
			break;
		case MEMOIRE_INSUFFISANTE:
			printf("Memoire insuffisante.\n");
			break;
		case LISTE_VIDE:
			printf("Liste vide.\n");
			break;
		case POSITION_NON_VALIDE:
			printf("Position non valide.\n");
			break;
		default:
			printf("Status inconnu.\n");
			break;
	}
}

void afficherEstVide(const Liste *liste) {
	if (estVide(liste))
		printf("liste vide.\n");
	else
		printf("liste non vide.\n");
}

void afficherSontEgal(const Liste *liste1, const Liste *liste2) {
	if (sontEgales(liste1, liste2))
		printf("\nLes listes sont egales.\n");
	else
		printf("\nLes listes sont inegales.\n");
}

void programmeTest() {

	// Création des listes ------------------------------------------------------
	Liste *liste1 = initialiser();
	Liste *liste2 = initialiser();
	assert(liste1 && liste2);

	printf("Premiere liste : ");
	afficher(liste1, FORWARD);
	printf("Deuxieme liste : ");
	afficher(liste2, FORWARD);


	// Test des fonctions d'insertion -------------------------------------------
	const Info INFO1 = 0;
	const Info INFO2 = 100;
   const Info INFO3 = 58;
   const Info INFO4 = 200;
   const Info INFO5 = 201;
   const Info INFO6 = 202;

	printf("\nInsertion de 3 elements en tete de la premiere liste.\n");
	printf("Status de la premiere insertion en tete : ");
	afficherStatus(insererEnTete(liste1, &INFO1));
	insererEnTete(liste1, &INFO2);
	insererEnTete(liste1, &INFO3);
	afficher(liste1, FORWARD);

	printf("\nInsertion de 3 elements en queue de la premiere liste.\n");
	printf("Status de la premiere insertion en queue : ");
	afficherStatus(insererEnQueue(liste1, &INFO5));
	insererEnQueue(liste1, &INFO4);
	insererEnQueue(liste1, &INFO6);
	afficher(liste1, FORWARD);

	// Test de la fonction d'affichage en sens inverse --------------------------
	printf("\nAffichage en mode BACKWARD de la deuxieme liste :\n");
	insererEnTete(liste2, &INFO1);
	insererEnTete(liste2, &INFO2);
	insererEnTete(liste2, &INFO3);
	insererEnQueue(liste2, &INFO4);
	insererEnQueue(liste2, &INFO5);
	insererEnQueue(liste2, &INFO6);
	afficher(liste2, BACKWARD);

	// Test de la fonction d'égalité
	afficherSontEgal(liste1, liste2);

	// Test des fonctions de suppression -----------------------------------------
	Info supprimerListe1;
	printf("Status apres suppression en queue : ");
	afficherStatus(supprimerEnQueue(liste1, &supprimerListe1));
	printf("\nElement supprime en queue de la premiere liste : %i\n",
			 supprimerListe1);
	afficher(liste1, FORWARD);

	Info supprimerListe2;
	printf("Status apres suppression en tete :");
	afficherStatus(supprimerEnTete(liste2, &supprimerListe2));
	printf("\nElement supprime en tete de la deuxieme liste : %i\n",
			 supprimerListe2);
	afficher(liste2, FORWARD);

	// Test de la fonction vider ------------------------------------------------
	printf("\nPremiere liste de taille %" PRIu64 " : ", longueur(liste1));
	afficher(liste1, FORWARD);
	printf("Deuxieme liste de taille %" PRIu64 " : ", longueur(liste2));
	afficher(liste2, FORWARD);

	printf("\nVide la premiere liste depuis le debut : ");
	vider(liste1, 0);
	afficher(liste1, FORWARD);

	printf("Premiere ");
	afficherEstVide(liste1);

	printf("\nInsertion en queue de 3 donnees dans la deuxieme liste.\n");
	insererEnQueue(liste2, &INFO1);
	insererEnQueue(liste2, &INFO2);
	insererEnQueue(liste2, &INFO3);
	printf("Deuxieme liste de taille %" PRIu64 " : ", longueur(liste2));
	afficher(liste2, FORWARD);

	printf("Vide la deuxieme liste depuis la position 3. : ");
	vider(liste2, 3);
	afficher(liste2, FORWARD);

	printf("Deuxieme ");
	afficherEstVide(liste2);

	printf("\nPremiere liste : ");
	afficher(liste1, FORWARD);
	printf("Deuxieme liste : ");
	afficher(liste2, FORWARD);

	sontEgales(liste1, liste2);

	// Test de la fonction de suppression d'éléments selon un critère ------------

	// Valeurs impaires
	Info impaire = 3;
	Info paire = 22;
	insererEnQueue(liste1, &impaire);
	insererEnQueue(liste1, &paire);
	insererEnTete(liste1, &impaire);
	insererEnTete(liste1, &paire);
	printf("\nListe  avant suppression : ");
	afficher(liste1, FORWARD);
	printf("Suppression d'element(s) impair(s) :\n");
	supprimerSelonCritere(liste1, estImpaire);
	afficher(liste1, FORWARD);

	// Valeurs paires
	insererEnQueue(liste2, &impaire);
	insererEnQueue(liste2, &paire);
	insererEnTete(liste2, &impaire);
	insererEnTete(liste2, &paire);
	printf("\nListe  avant suppression : ");
	afficher(liste2, FORWARD);
	printf("Suppression d'element(s) pair(s) :\n");
	supprimerSelonCritere(liste2, estPaire);
	afficher(liste2, FORWARD);

	// Valeurs paire et positions paires
	insererEnTete(liste1, &INFO2);
	insererEnTete(liste1, &INFO3);
	insererEnQueue(liste1, &INFO6);
	insererEnQueue(liste1, &INFO5);
	printf("\nListe  avant suppression : ");
	afficher(liste1, FORWARD);
	printf("Suppression d'element(s) pairs aux positions paires :\n");
	supprimerSelonCritere(liste1, positionEtValeurPaires);
	afficher(liste1, FORWARD);

	// Suppression des listes ----------------------------------------------------
	vider(liste1, 0);
	free(liste1);
	liste1 = NULL;
	vider(liste2, 0);
	free(liste2);
	liste2 = NULL;
}
