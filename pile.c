#include "pile.h"


/* ----PRESENTATION DU MODULE---- */

/* ------------------------------------------------------------------------------------------------------------ */
/*  Module Pile : permet de gérer la structure pile pour tout type de variable                                  */
/*                                                                                                              */
/*  Structure :                                                                                                 */
/*  	-pile est la structure contenant les infos sur le tableau (taille, nb d'éléments, pointeur sur le tab)  */
/*  	-tableau est la structure contenant les element_t à empiler ou dépiler                                  */
/*  	-element_t est le type de variables présentes dans le tableau                                           */
/*                                                                                                              */
/*  Fonctions :                                                                                                 */
/*  	-initPile                                                                                               */
/*  	-empiler                                                                                                */
/*  	-depiler                                                                                                */
/*  	-estVide                                                                                                */
/*  	-libererPile                                                                                            */
/* ------------------------------------------------------------------------------------------------------------ */




/* ----FONCTIONS DU MODULE---- */

/* ----------------------------------------------------------------------------------------------------------- */
/*  initPile : créer une structure pile au format suivant:                                                     */
/*                                                                                                             */
/*                                                                                                             */
/*  En entrée :                                                                                                */
/*  	-taille = entier correspondant à la taille du tableau contenant les éléments                           */
/*                                                                                                             */
/*  En sortie :                                                                                                */
/*  	-pt_pile = pointeur sur la structure pile créée                                                        */
/* ----------------------------------------------------------------------------------------------------------- */

Pile_t * initPile(int taille)
{
	Pile_t    * pt_pile = NULL; /* pointeur sur la pile */
	element_t * pt_tab = NULL; /* pointeur sur le tableau */
	
	pt_pile = (Pile_t*)malloc(sizeof(Pile_t)); 
	
	pt_tab = (element_t*)malloc(taille*sizeof(element_t));
	 
	if (pt_pile == NULL) /* si l'allocation de la pile échoue */
	{
		printf("problème d'allocation de la pile");
		exit(1); /* sortie immédiate du code en cas de problème d'allocation */
	}
	
	if (pt_tab == NULL)  /* si l'allocation du tableau échoue */
	{
		printf("problème d'allocation du tableau");
		exit(1);
	}
	
	pt_pile->taille = taille; /* la taille du tableau est placé dans la pile */
	pt_pile->nb_elt = 0; /* mise à zéro du nombre d'éléments présent dans la pile| */
	pt_pile->pt_tab = pt_tab; /* l'adresse du tableau est placé dans la pile */

	
	return pt_pile;
}




/* ---------------------------------------------------------------------- */
/*  empiler : ajouter l'élément d'entrée après le dernier élément rentré  */
/*                                                                        */
/*  Entrée :                                                              */
/*  -pt_pile = pointeur sur la pile                                       */
/*  -element = valeur à empiler dans le tableau                           */
/*                                                                        */
/*  Pas de sortie                                                         */
/* ---------------------------------------------------------------------- */

void empiler(Pile_t * pt_pile, element_t element)
{
	element_t * pt_tab = pt_pile->pt_tab; /* récuperer le tableau dans la fonction ou faire *(pt_pile->pt_tab+i) mais un peu illisible */
	int nb_elt = pt_pile->nb_elt;
	
	*(pt_tab+nb_elt) = element;
	
	pt_pile->nb_elt = nb_elt + 1;
}




/* ------------------------------------------------------------ */
/*  depiler : retirer le dernier élément rentré dans le tableau */
/*                                                              */
/*  Entrée :                                                    */
/*  	-pt_pile = pointeur sur la pile                         */
/*                                                              */
/*  Sortie :                                                    */
/*  	-element = élément retiré                               */
/* ------------------------------------------------------------ */

element_t depiler(Pile_t * pt_pile)
{
	element_t * pt_tab = pt_pile->pt_tab; /* récuperer le tableau dans la fonction ou faire *(pt_pile->pt_tab+i) mais un peu illisible */
	int nb_elt = pt_pile->nb_elt;
	element_t element;
	
	element = *(pt_tab+nb_elt-1);
	*(pt_tab+nb_elt-1) = 0;
	
	pt_pile->nb_elt = nb_elt - 1;
	
	return element;
}




/*  ---------------------------------------------------------------------------------  */
/*  estVide : tester si le tableau de la pile contient des éléments                    */
/*                                                                                     */
/*  Entrée :                                                                           */
/*  -pt_pile = pointeur sur la pile                                                    */
/*                                                                                     */
/*  Sortie :                                                                           */
/*  -vide = booléen qui vaut true(resp. false) si le tableau est vide(resp. non vide)  */
/*  ---------------------------------------------------------------------------------  */

bool estVide(Pile_t * pt_pile)
{
	bool vide = true;  /* variable de type booléenne provenant de la bibliothèque stdbool.h */
	
	if (pt_pile != NULL)
	{
		if (pt_pile->nb_elt != 0)
		{
			vide = false;
		}
	}
	
	printf("la pile est vide == %d\n", vide); // à supprimer pour rendre le rapport
	return vide;
}




/* ---------------------------------- */
/*  libererPile : libérer la mémoire  */
/*                                    */
/*  Entrée :                          */
/*  -pointeur sur la pile             */
/*                                    */
/*  Pas de sortie                     */
/* ---------------------------------- */

void libererPile(Pile_t * pt_pile)
{
	free(pt_pile->pt_tab); /* libérer le tableau */
	free(pt_pile); /* libérer la pile */
}




//extension à supprimer avant de rendre le tp : affichage dans le cas int
void affichage_pile_int(Pile_t * pt_pile)
{
	int i=0;
	element_t * pt_tab = pt_pile->pt_tab; /* récuperer le tableau dans la fonction ou faire *(pt_pile->pt_tab+i) mais un peu illisible */
	int taille = pt_pile->taille;
	
	for (i=0;i<taille;i++)
	{
		printf("%d\n", *(pt_tab+i));
	}
}







/* ----FIN DU MODULE---- */
