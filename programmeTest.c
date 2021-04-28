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
	printf("Premiere insertion en tete : ");
	afficherStatus(insererEnTete(Liste1, &info));
	insererEnTete(Liste1, &info1);
	insererEnTete(Liste1, &info2);
	afficher(Liste1, FORWARD);

	printf("\nInsertion de 3 elements en queue de la premiere liste.\n");
	insererEnQueue(Liste1, &info3);
	printf("Premiere insertion en queue : ");
	afficherStatus(insererEnQueue(Liste1, &info4));
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
	printf("Status apres suppression en queue :");
	afficherStatus(supprimerEnQueue(Liste1, &supprimerListe1));
	printf("\nElement supprime en queue de la premiere liste: %i\n", supprimerListe1);
	afficher(Liste1, FORWARD);


	Info supprimerListe2;
	printf("Status apres suppression en tete :");
	afficherStatus(supprimerEnTete(Liste2, &supprimerListe2));
	printf("\nElement supprime en tete de la deuxieme liste: %i\n", supprimerListe2);
	afficher(Liste2, FORWARD);

	printf("\n");
	printf("Premiere liste de taille %" PRIu64 ": ", longueur(Liste1));
	afficher(Liste1, FORWARD);
	printf("Deuxieme liste de taille %" PRIu64 ": ", longueur(Liste2));
	afficher(Liste2, FORWARD);

	printf("\nVide la premiere liste depuis le debut.\n");
	vider(Liste1, 0);
	afficher(Liste1, FORWARD);
	if (estVide(Liste1)) printf("Premiere liste vide.\n");
	else printf("Premiere liste non vide.\n");


	printf("\nInsertion en queue de 3 donnees dans la deuxieme liste.\n");
	insererEnQueue(Liste2, &info);
	insererEnQueue(Liste2, &info1);
	insererEnQueue(Liste2, &info2);
	printf("Deuxieme liste de taille %" PRIu64 ": ", longueur(Liste2));
	afficher(Liste2, FORWARD);

	printf("Vider la deuxieme liste depuis la position 3.\n");
	vider(Liste2, 3);
	afficher(Liste2, FORWARD);
	if (estVide(Liste2)) printf("Deuxieme liste vide.");
	else printf("Deuxieme liste non vide.");
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

	printf("\n");
	insererEnTete(Liste1, &info1);
	insererEnTete(Liste1, &info2);
	insererEnQueue(Liste1, &info5);
	insererEnQueue(Liste1, &info4);
	afficher(Liste1, FORWARD);
	printf("Suppression d'element(s) pairs aux positions paires.\n");
	supprimerSelonCritere(Liste1, positionEtValeurPaires);
	afficher(Liste1, FORWARD);

	free(Liste1);
	Liste1 = NULL;
	free(Liste2);
	Liste2 = NULL;
}
