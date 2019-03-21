#include "pile.h"
#include "file.h"
#include "truc.h"
int main(){
	Pile_t * pt_pile = NULL;
	int taille_tab = 20;
	
	int var=0;
    int   n=3;
    char  T[]={'a','b','c'};
	
	/*scanf("%d", &taille_tab); pas bon pour utiliser valgrind et ddd */
	/* placer les arguments en ligne de commande dans le main()       */
	
	pt_pile = initPile(taille_tab);
	
	estVide(pt_pile);
	
	empiler(pt_pile, 22);
	empiler(pt_pile, 23);
	empiler(pt_pile, 24);
	empiler(pt_pile, 25);
	empiler(pt_pile, 26);
	
	affichage_pile_int(pt_pile);
	estVide(pt_pile);
	
	var = depiler(pt_pile);
	printf("\nvariable dépilé = %d\n", var);
	
	libererPile(pt_pile);
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
