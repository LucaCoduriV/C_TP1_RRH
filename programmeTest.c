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

void programmeTest() {
	Liste* liste1 = initialiser();
	Liste* liste2 = initialiser();

	const Info INFO1 = 0;
   const Info INFO2 = 100;
   const Info INFO3 = 58;
   const Info INFO4 = 200;
   const Info INFO5 = 201;
   const Info INFO6 = 202;
   const Info IMPAIRE = 3;
   const Info PAIRE = 22;

	printf("Premiere liste : ");
	afficher(liste1, FORWARD);
	printf("Deuxieme liste : ");
	afficher(liste2, FORWARD);

	// Test des fonctions d'insertion
	printf("\nInsertion de 3 elements en tete de la premiere liste.\n");
	printf("Premiere insertion en tete : ");
	afficherStatus(insererEnTete(liste1, &INFO1));
	insererEnTete(liste1, &INFO2);
	insererEnTete(liste1, &INFO3);
	afficher(liste1, FORWARD);

	printf("\nInsertion de 3 elements en queue de la premiere liste.\n");
	insererEnQueue(liste1, &INFO4);
	printf("Premiere insertion en queue : ");
	afficherStatus(insererEnQueue(liste1, &INFO5));
	insererEnQueue(liste1, &INFO6);
	afficher(liste1, FORWARD);

	//
	printf("\nAffichage en mode BACKWARD de la deuxieme liste.\n");
	insererEnTete(liste2, &INFO1);
	insererEnTete(liste2, &INFO2);
	insererEnTete(liste2, &INFO3);
	insererEnQueue(liste2, &INFO4);
	insererEnQueue(liste2, &INFO5);
	insererEnQueue(liste2, &INFO6);
	afficher(liste2, BACKWARD);

	printf("\n");
	if (sontEgales(liste1, liste2)) printf("Les listes sont egales.\n");
	else printf("Les listes sont inegales.\n");

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

	printf("\n");
	printf("Premiere liste de taille %" PRIu64 ": ", longueur(liste1));
	afficher(liste1, FORWARD);
	printf("Deuxieme liste de taille %" PRIu64 ": ", longueur(liste2));
	afficher(liste2, FORWARD);

	printf("\nVide la premiere liste depuis le debut.\n");
	vider(liste1, 0);
	afficher(liste1, FORWARD);
	if (estVide(liste1)) printf("Premiere liste vide.\n");
	else printf("Premiere liste non vide.\n");


	printf("\nInsertion en queue de 3 donnees dans la deuxieme liste.\n");
	insererEnQueue(liste2, &INFO1);
	insererEnQueue(liste2, &INFO2);
	insererEnQueue(liste2, &INFO3);
	printf("Deuxieme liste de taille %" PRIu64 ": ", longueur(liste2));
	afficher(liste2, FORWARD);

	printf("Vider la deuxieme liste depuis la position 3.\n");
	vider(liste2, 3);
	afficher(liste2, FORWARD);
	if (estVide(liste2)) printf("Deuxieme liste vide.");
	else printf("Deuxieme liste non vide.");
	printf("\n");

	printf("Premiere liste : ");
	afficher(liste1, FORWARD);
	printf("Deuxieme liste : ");
	afficher(liste2, FORWARD);


	if (sontEgales(liste1, liste2)) printf("Les listes sont égales.\n");
	else printf("Les listes sont inegales.\n");


	insererEnQueue(liste1, &IMPAIRE);
	insererEnQueue(liste1, &PAIRE);
	insererEnTete(liste1, &IMPAIRE);
	insererEnTete(liste1, &PAIRE);
	printf("\n");
	afficher(liste1, FORWARD);
	printf("Suppression d'element(s) impair(s).\n");
	supprimerSelonCritere(liste1, estImpaire);
	afficher(liste1, FORWARD);


	insererEnQueue(liste2, &IMPAIRE);
	insererEnQueue(liste2, &PAIRE);
	insererEnTete(liste2, &IMPAIRE);
	insererEnTete(liste2, &PAIRE);
	printf("\n");
	afficher(liste2, FORWARD);
	printf("Suppression d'element(s) pair(s).\n");
	supprimerSelonCritere(liste2, estPaire);
	afficher(liste2, FORWARD);

	printf("\n");
	insererEnTete(liste1, &INFO2);
	insererEnTete(liste1, &INFO3);
	insererEnQueue(liste1, &INFO6);
	insererEnQueue(liste1, &INFO5);
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
