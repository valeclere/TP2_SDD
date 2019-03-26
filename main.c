#include "pile.h"
#include "file.h"
#include "truc.h"

int main(){
	
	/*----------------------TESTS du module PILE--------------------------*/
	
	printf("\n\n-------Tests PILE---------\n\n");
	
	Pile_t * pt_pile = NULL; /* pointeur sur la pile */
	int taille_tab = 10; /* taille de la pile */
	int var=0; /* variable pour stocker la valeur dépilée */
	
    /*scanf("%d", &taille_tab); pas bon pour utiliser valgrind et ddd */
    /* placer les arguments en ligne de commande dans le main()       */

    /* initialisation de la pile */
    pt_pile = initPile(taille_tab);
    printf("\n-> PILE initialisée\n");
    affichagePile(pt_pile);
    printf("\nla pile est vide == %d\n", estVide(pt_pile)); /* estVide retourne 1 car la pile est vide */

    /* on empile 5 valeurs */
    empiler(pt_pile, 12);
    empiler(pt_pile, 23);
    empiler(pt_pile, 44);
    empiler(pt_pile, 75);
    empiler(pt_pile, 6); /* dernière valeur empilée */
    printf("\n-> PILE avec 5 valeurs empilées\n");
    affichagePile(pt_pile);
    printf("\nla pile est vide == %d\n", estVide(pt_pile)); /* estVide retourne 0 car la pile n'est pas vide */

    /* on dépile la dernière valeur rentrée */
    printf("\n-> PILE avec la dernière valeur dépilée\n");
    var = depiler(pt_pile);
    affichagePile(pt_pile);
    printf("\nvaleur dépilée = %d\n", var);

    libererPile(pt_pile); /* on libère l'espace mémoire */


    /*-----------------------------TESTS FILE-----------------------------*/
    printf("\n\n-------Tests FILE---------\n\n");
    File_t   * pt_file=NULL;
    File_t   * pt_fileVide=NULL;
    File_t   * pt_filePleine=NULL;
    int        mis=0;
    element_t  val=0;
    int      * err=&mis;
    /*-------------------------------------------------------*/
    /*                  Initialisation de la file            */
    /*  Le but est d'avoir une file vide prête à être utilisée*/
    /*-------------------------------------------------------*/
        /*Cas n°1: Cas de base*/
            pt_file=initFile(10); /*on indique que la file sera composé de 10 éléments*/
            pt_filePleine=initFile(1);/*file pleine qui servira pour le reste des exemples*/
        /*Cas n°2: Cas où le nombre d'élément est 0*/
            pt_fileVide=initFile(0); /* pas d'erreur mais la file ne peut acceuillir d'élément*/
    
    /*-------------------------------------------------------*/
    /*       Ajouter une valeur dans la file (ENFILER)       */
    /*          Le but est de pouvoir ajouter une valeur     */
    /*                     dans notre file                   */
    /*-------------------------------------------------------*/
     printf("\n\n-----||  TESTS de la fonction enfiler(File_t *pt_fi, element_t val, int *err);  ||------ \n\n");
        /*Cas n°1: Ajout d'un élément de type element_t (ici un int) dans une file sans élement*/
            printf("Affichage CAS 1: ajout d'un élément dans la file\n\n");
            enfiler(pt_filePleine, 2, err); /*Ici on enfile dans la file pointé par pt_filePleine pour la rendre pleine*/
            if(!(*err))
            {
                printf("Problème lors de l'ajout de l'élément\n");
            }
            else affichageFile(pt_filePleine);/*Pas de problème on affiche la file*/
            enfiler(pt_file, 1000, err);/*idem pour la file de 1O éléments qui sert pour la suite des tests*/
            printf("*---------------------------------------------*\n");
        /*Cas n°2: Cas où l'on donne une file pleine*/
            printf("Affichage CAS 2: ajout d'un élément dans la file PLEINE\n\n");
            enfiler(pt_filePleine, 10, err);
            if(!(*err))/*si on a la valeur pointé par err qui vaut 0 alors on a une erreur*/
            {
                    printf("Problème lors de l'ajout de l'élément\n");
            }
            else affichageFile(pt_filePleine);
            printf("*---------------------------------------------*\n");
        /*Cas n°3: Cas de base où l'on ajout un élément dans une file partielement remplie*/
            printf("Affichage CAS 3: ajout d'un élément dans la file partielement remplie\n\n");
            enfiler(pt_file, 2000, err);
            if(!(*err))/*si on a la valeur pointé par err qui vaut 0 alors on a une erreur*/
            {
                printf("Problème lors de l'ajout de l'élément\n");
            }
            else affichageFile(pt_file);
            printf("*---------------------------------------------*\n");
            enfiler(pt_file, 3000, err);/*on enfile d'autres éléments pour la suite des tests*/
            enfiler(pt_file, 4000, err);
    /*-------------------------------------------------------*/
    /*       Enlever une valeur dans la file (DEFILER)       */
    /*          Le but est de pouvoir enlever une valeur     */
    /*                     dans notre file                   */
    /*-------------------------------------------------------*/
      printf("\n\n-----||  TESTS de la fonction defiler(File_t *pt_fi,int* err);  ||------ \n\n");
    
        /*Cas n°1 de base: Suppression d'un élément de type element_t (ici un int) dans une file*/
            printf("Affichage CAS 1: Suppression d'un élément dans la file partielement remplie\n\n");
            val = defiler(pt_file, err);
            if((*err))/*si on a la valeur pointé par err qui vaut 1 alors on a pas eu d'erreur*/
            {
                affichageFile(pt_file);
                printf("\nValeur défilé = %d\n",val);
            }
            else printf("Problème lors de la suppression de l'élément\n");
            printf("*---------------------------------------------*\n");
            val=0; /*réinitialisation de val*/
    
        /*Cas n°2 : Suppression d'un élément de type element_t (ici un int) dans une file VIDE*/
            printf("Affichage CAS 2: Suppression d'un élément dans la file VIDE\n\n");
            val = defiler(pt_fileVide, err);
            if((*err))/*si on a la valeur pointé par err qui vaut 1 alors on a pas eu d'erreur*/
            {
                affichageFile(pt_filePleine);
                printf("\nValeur défilé = %d\n",val);
            }
            else printf("Problème lors de la suppression de l'élément\n");
            printf("*---------------------------------------------*\n");
    
        /*Cas n°3 : Suppression d'un élément de type element_t (ici un int) dans une file PLEINE*/
            printf("Affichage CAS 3: Suppression d'un élément dans la file PLEINE\n\n");
            val = defiler(pt_filePleine, err);
            if((*err))/*si on a la valeur pointé par err qui vaut 1 alors on a pas eu d'erreur*/
            {
                affichageFile(pt_filePleine);
                printf("\nValeur défilé = %d\n",val);
            }
            else printf("Problème lors de la suppression de l'élément\n");
            printf("*---------------------------------------------*\n");
            val=0; /*réinitialisation de val*/
            enfiler(pt_filePleine, 2, err); /*on rend de nouveau le file pleine pour le reste des tests*/
    
    /*-------------------------------------------------------*/
    /*            test de la fonction estFileVide            */
    /*          permet de savoir si une file est vide        */
    /*-------------------------------------------------------*/
    printf("\n\n-----||  TESTS de la fonction estFileVide(File_t fi)  ||------ \n\n");
        /*Cas n°1: Sur une file pas vide*/
            printf("\nAffichage CAS 1: test sur une file NON vide\n\n");
            if(estFileVide(*pt_filePleine)){
                printf("La file *pt_filePleine est vide (PROBLEME) :(\n");
            }
            else
            {
                printf("La file *pt_filePleine  n'est pas vide (ouf) :) \n");
            }
        /*Cas n°2: Sur une file vide*/
            printf("\nAffichage CAS 2: test sur une file VIDE\n\n");
            if(estFileVide(*pt_fileVide)){
                printf("La file *pt_fileVide est vide (ouf) :) \n");
            }
            else
            {
                printf("La file *pt_fileVide  n'est pas vide (PROBLEME) :( \n");
            }
    /*---------------------FIN des TESTS de FILE--------------------*/
    /*-------------DEROULEMENT TYPE DES FONCTIONS DE FILE-----------*/
    printf("\n-------------DEROULEMENT TYPE DES FONCTIONS DE FILE-----------\n\n");
    printf("\nAffichage File initiale\n\n");
    affichageFile(pt_file);
    val = defiler(pt_file, err);
    printf("\nValeur défilé = %d\n",val);
    printf("\nAffichage File en partie défilée\n\n");
    affichageFile(pt_file);

    enfiler(pt_file, 1111, err);
    enfiler(pt_file, 2222, err);
    printf("\naffichage File re-enfiler\n\n");
    affichageFile(pt_file);

    libererFile(pt_file);
    libererFile(pt_filePleine);
    libererFile(pt_fileVide);
    
     /*----------fonction TRUC---------------------*/
    
    int     n  =3;
    truc_t  T[]={'a','b','c'};

    printf("\n\n-------Tests de TRUC RECURSIVE-------\n\n");
    truc_rec(0,n,T);
    printf("\n\n------------AVEC TRACE-----------\n\n");
    truc_recTrace(0,n,T);
    printf("\n\n-------Tests de TRUC récursive avec n=2-------\n\n");
    truc_rec(0,2,T);
    printf("\n\n-------Tests de TRUC récursive avec n=1-------\n\n");
    truc_rec(0,1,T);
    
    printf("\n-------|||Tests de TRUC ITERATIVE|||-------");
    printf("\n\n-------Tests de TRUC itérative avec n=3-------\n\n");
    truc_ite(0, n,T);
    printf("\n");
    printf("\n-------Tests de TRUC itérative avec n=2-------\n\n");
    truc_ite(0, 2,T);
    printf("\n-------Tests de TRUC itérative avec n=1-------\n\n");
    truc_ite(0, 1,T);
    printf("\n-------Tests de TRUC itérative avec n=0-------\n\n");
    truc_ite(0, 0,T);
	
	return 0;
}
