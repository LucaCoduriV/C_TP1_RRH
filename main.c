#include <stdio.h>
#include "listes_dynamiques.h"

int main() {

   Liste* maListe = initialiser();
   Info info = 10;
   Info info1 = 100;
   Info info2 = 58;
   Info info3 = 200;

   insererEnTete(maListe, &info);
   insererEnTete(maListe, &info1);
   insererEnTete(maListe, &info2);
   insererEnQueue(maListe, &info3);
   insererEnQueue(maListe, &info3);
   insererEnQueue(maListe, &info3);
   afficher(maListe, BACKWARD);
   return 0;
}
