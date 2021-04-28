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

	Info info = 0;
	Info info1 = 100;
	Info info2 = 58;
	Info info3 = 200;
	Info info4 = 201;
	Info info5 = 202;

	printf("Premiere liste : ");
	afficher(liste1, FORWARD);
	printf("Deuxieme liste : ");
	afficher(liste2, FORWARD);

	// Test des fonctions d'insertion
	printf("\nInsertion de 3 elements en tete de la premiere liste.\n");
	printf("Premiere insertion en tete : ");
	afficherStatus(insererEnTete(liste1, &info));
	insererEnTete(liste1, &info1);
	insererEnTete(liste1, &info2);
	afficher(liste1, FORWARD);

	printf("\nInsertion de 3 elements en queue de la premiere liste.\n");
	insererEnQueue(liste1, &info3);
	printf("Premiere insertion en queue : ");
	afficherStatus(insererEnQueue(liste1, &info4));
	insererEnQueue(liste1, &info5);
	afficher(liste1, FORWARD);

	//
	printf("\nAffichage en mode BACKWARD de la deuxieme liste.\n");
	insererEnTete(liste2, &info);
	insererEnTete(liste2, &info1);
	insererEnTete(liste2, &info2);
	insererEnQueue(liste2, &info3);
	insererEnQueue(liste2, &info4);
	insererEnQueue(liste2, &info5);
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
	insererEnQueue(liste2, &info);
	insererEnQueue(liste2, &info1);
	insererEnQueue(liste2, &info2);
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

	free(liste1);
	liste1 = NULL;
	free(liste2);
	liste2 = NULL;
}
