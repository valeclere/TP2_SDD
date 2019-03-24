#include "pile.h"
#include "file.h"
#include "truc.h"

int main(){
	
	/*----------------------TESTS du module PILE--------------------------*/
	
	Pile_t * pt_pile = NULL; /* pointeur sur la pile */
	int taille_tab = 10; /* taille de la pile */
	int var=0; /* variable pour stocker la valeur dépilée */
	
	/*scanf("%d", &taille_tab); pas bon pour utiliser valgrind et ddd */
	/* placer les arguments en ligne de commande dans le main()       */
	
	/* initialisation de la pile */
	pt_pile = initPile(taille_tab);
	printf("\n-> PILE initialisée\n");
	affichage_pile_int(pt_pile);
	estVide(pt_pile);
	
	/* on empile 5 valeurs */
	empiler(pt_pile, 12);
	empiler(pt_pile, 23);
	empiler(pt_pile, 44);
	empiler(pt_pile, 75);
	empiler(pt_pile, 6);
	printf("\n-> PILE avec 5 valeurs empilées\n");
	affichage_pile_int(pt_pile);
	estVide(pt_pile);
	
	/* on dépile la dernière valeur rentrée */
	printf("\n-> PILE avec la dernière valeur dépilée\n");
	var = depiler(pt_pile);
	affichage_pile_int(pt_pile);
	printf("valeur dépilée = %d\n", var);
	
	libererPile(pt_pile); /* on libère l'espace mémoire */
	
	
	/*------------------------FIN tests PILE------------------------------*/
	/*--------------------------------------------------------------------*/
	
    int   n=3;
    char  T[]={'a','b','c'};
	
    printf("\n\n-------Tests FILE---------\n\n");
    File_t *pt_file=NULL;
    int mis=0;
    int *err=&mis;
    pt_file=initFile(10);
    enfiler(pt_file, 2, err);
    enfiler(pt_file, 10, err);
    enfiler(pt_file, 239, err);
    enfiler(pt_file, 5089, err);
    printf("\naffichage File initiale\n\n");
    affichageFile(pt_file);
    /**/
    defiler(pt_file, err);
    printf("\naffichage File en partie défilée\n\n");
    affichageFile(pt_file);
    /**/
    enfiler(pt_file, 1111, err);
    enfiler(pt_file, 2222, err);
    printf("\naffichage File re-enfiler\n\n");
    affichageFile(pt_file);

    libererFile(pt_file);
    //    printf("\n\n-------Tests de TRUC-------\n\n");
//    truc(0,n,T);
	return 0;
}
