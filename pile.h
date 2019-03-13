#ifndef PILE
#define PILE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //pour avoir le type bool

typedef struct Mastruct_s{
	int val;
}Mastruct_t;


typedef struct Pile_s{
	int taille;
	Mastruct_t nbelt;
	Mastruct_t *deb;	
}Pile_t;

Pile_t* initPile(int taille);

/*
estVide
empiler
depiler
initPile
libererPile
*/

#endif
