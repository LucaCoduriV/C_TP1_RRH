#include <stdio.h>
#include "listes_dynamiques.h"
#include <stdlib.h>

bool estPaire(size_t position, const Info* info) {
	return *info % 2 == 0;
}

bool estImpaire(size_t position, const Info* info) {
	return *info % 2 != 0;
}

bool aPositionImpaire(size_t position, const Info* info) {
	return position % 2 != 0;
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
   Info info6 = 0;


   insererEnTete(maListe, &info);
   insererEnTete(maListe, &info1);
   insererEnTete(maListe, &info2);
   insererEnQueue(maListe, &info3);
   insererEnQueue(maListe, &info4);
   insererEnQueue(maListe, &info5);


   insererEnTete(maListe2, &info);
   insererEnTete(maListe2, &info1);
   insererEnTete(maListe2, &info2);
   insererEnQueue(maListe2, &info3);
   insererEnQueue(maListe2, &info4);
   insererEnQueue(maListe2, &info5);







	supprimerSelonCritere(maListe, aPositionImpaire);

	afficher(maListe, FORWARD);

	printf("%i\n", info6);
   printf("%i", sontEgales(maListe, maListe2));
   vider(maListe, 1);
   free(maListe);
   return 0;
}
