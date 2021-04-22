#include <stdio.h>
#include "listes_dynamiques.h"

int main() {

   Liste* maListe = initialiser();
   Info info = 10;
   Info info1 = 100;
   Info info2 = 58;
   Info info3 = 200;
   Info info4 = 201;
   Info info5 = 202;

   insererEnQueue(maListe, &info3);
   insererEnQueue(maListe, &info4);
   insererEnQueue(maListe, &info5);
   insererEnTete(maListe, &info);
   insererEnTete(maListe, &info1);
   insererEnTete(maListe, &info2);


   afficher(maListe, FORWARD);
   afficher(maListe, BACKWARD);

   return 0;
}
