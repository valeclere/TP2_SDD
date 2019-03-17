#ifndef PILE
#define PILE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> /* pour avoir le type bool */


typedef int element_t; /* type de variables présentes dans le tableau, ici on considère des int */

typedef struct Pile_s{
	int taille;
	int nb_elt;
	element_t * pt_tab;
}Pile_t;

Pile_t * initPile(int taille);
void empiler(Pile_t * pt_pile, element_t element);
element_t depiler(Pile_t * pt_pile);
bool estVide(Pile_t * pt_pile); /* attention suppr l'affichage pour rapport */
void libererPile(Pile_t * pt_pile);
void affichage_pile_int(Pile_t * pt_pile); /* afficher pour tester, à supprimer pour rendre le projet */


#endif
