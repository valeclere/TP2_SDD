#include "pile.h"
#include "file.h"
#include "truc.h"

int main(){
	
	/*----------------------TESTS du module PILE--------------------------*/
	
	printf("\n\n-------Tests PILE---------\n\n");
	
	Pile_t * pt_pile = NULL; /* pointeur sur la pile */
	int taille_tab = 10; /* taille de la pile */
	Pile_t   * pt_pileVide=NULL;
    Pile_t   * pt_pilePleine=NULL;
	
	
	element_t var=0; /* variable pour stocker la valeur dépilée */
	
	
	int        mistake=0;
	int      * err=&mistake;
	/*-------------DEROULEMENT TYPE DES FONCTIONS DE PILE-----------*/

    /* initialisation de la pile */
    pt_pile = initPile(taille_tab);
    printf("\n-> PILE initialisée\n");
    affichagePile(pt_pile);
    printf("\nla pile est vide == %d\n", estVide(pt_pile)); /* estVide retourne 1 car la pile est vide */

    /* on empile 5 valeurs */
    empiler(pt_pile, 12, err);
    empiler(pt_pile, 23, err);
    empiler(pt_pile, 44, err);
    empiler(pt_pile, 75, err);
    empiler(pt_pile, 6, err); /* dernière valeur empilée */
    printf("\n-> PILE avec 5 valeurs empilées\n");
    affichagePile(pt_pile);
    printf("\nla pile est vide == %d\n", estVide(pt_pile)); /* estVide retourne 0 car la pile n'est pas vide */

    /* on dépile la dernière valeur rentrée */
    printf("\n-> PILE avec la dernière valeur dépilée\n");
    var = depiler(pt_pile, err);
    affichagePile(pt_pile);
    printf("\nvaleur dépilée = %d\n", var);

    
    /*réinitialisation*/
    pt_pile=NULL;
	*err=0;
	var=0;
	/*-------------------------------------------------------*/
    /*                  Initialisation de la pile            */
    /*  Le but est d'avoir une pile vide prête à être utilisée*/
    /*-------------------------------------------------------*/
        /*Cas n°1: Cas de base*/
            pt_pile=initPile(10); /*on indique que la pile sera composé de 10 éléments*/
            pt_pilePleine=initPile(1);/*pile pleine qui servira pour le reste des exemples*/
        /*Cas n°2: Cas où le nombre d'élément est 0*/
            pt_pileVide=initPile(0); /* pas d'erreur mais la pile ne peut acceuillir d'élément*/
    
    /*-------------------------------------------------------*/
    /*       Ajouter une valeur dans la pile (ENFILER)       */
    /*          Le but est de pouvoir ajouter une valeur     */
    /*                     dans notre pile                   */
    /*-------------------------------------------------------*/
     printf("\n\n-----||  TESTS de la fonction empiler(Pile_t * pt_pile, element_t element)  ||------ \n\n");
        /*Cas n°1: Ajout d'un élément de type element_t (ici un int) dans une file sans élement*/
            printf("Affichage CAS 1: ajout d'un élément dans la file\n\n");
            empiler(pt_pilePleine, 2, err); /*Ici on empile dans la pile pointé par pt_pilePleine pour la rendre pleine*/
            if(!(*err))
            {
                printf("Problème lors de l'ajout de l'élément\n");
            }
            else affichagePile(pt_pilePleine);/*Pas de problème on affiche la pile*/
            empiler(pt_pile, 1000, err);/*idem pour la pile de 1O éléments qui sert pour la suite des tests*/
            printf("*---------------------------------------------*\n");
        /*Cas n°2: Cas où l'on donne une pile pleine*/
            printf("Affichage CAS 2: ajout d'un élément dans la pile PLEINE\n\n");
            empiler(pt_pilePleine, 10, err);
            if(!(*err))/*si on a la valeur pointé par err qui vaut 0 alors on a une erreur*/
            {
                    printf("Problème lors de l'ajout de l'élément\n");
            }
            else affichagePile(pt_pilePleine);
            printf("*---------------------------------------------*\n");
        /*Cas n°3: Cas de base où l'on ajout un élément dans une pile partiellement remplie*/
            printf("Affichage CAS 3: ajout d'un élément dans la pile partiellement remplie\n\n");
            empiler(pt_pile, 2000, err);
            if(!(*err))/*si on a la valeur pointé par err qui vaut 0 alors on a une erreur*/
            {
                printf("Problème lors de l'ajout de l'élément\n");
            }
            else affichagePile(pt_pile);
            printf("*---------------------------------------------*\n");
            empiler(pt_pile, 3000, err);/*on enfile d'autres éléments pour la suite des tests*/
            empiler(pt_pile, 4000, err);
            
    /*-------------------------------------------------------*/
    /*       Enlever une valeur dans la pile (DEPILER)       */
    /*          Le but est de pouvoir enlever une valeur     */
    /*                     dans notre pile                   */
    /*-------------------------------------------------------*/
      printf("\n\n-----||  TESTS de la fonction depiler(Pile_t *pt_pile,int* err);  ||------ \n\n");
    
        /*Cas n°1 de base: Suppression d'un élément de type element_t (ici un int) dans une pile*/
            printf("Affichage CAS 1: Suppression d'un élément dans la pile partielement remplie\n\n");
            var = depiler(pt_pile, err);
            if((*err))/*si on a la valeur pointé par err qui vaut 1 alors on a pas eu d'erreur*/
            {
                affichagePile(pt_pile);
                printf("\nValeur dépilé = %d\n",var);
            }
            else printf("Problème lors de la suppression de l'élément\n");
            printf("*---------------------------------------------*\n");
            var=0; /*réinitialisation de var*/
    
        /*Cas n°2 : Suppression d'un élément de type element_t (ici un int) dans une pile VIDE*/
            printf("Affichage CAS 2: Suppression d'un élément dans la pile VIDE\n\n");
            var = depiler(pt_pileVide, err);
            if((*err))/*si on a la valeur pointé par err qui vaut 1 alors on a pas eu d'erreur*/
            {
                affichagePile(pt_pilePleine);
                printf("\nValeur dépilé = %d\n",var);
            }
            else printf("Problème lors de la suppression de l'élément\n");
            printf("*---------------------------------------------*\n");
    
        /*Cas n°3 : Suppression d'un élément de type element_t (ici un int) dans une pile PLEINE*/
            printf("Affichage CAS 3: Suppression d'un élément dans la pile PLEINE\n\n");
            var = depiler(pt_pilePleine, err);
            if((*err))/*si on a la valeur pointé par err qui vaut 1 alors on a pas eu d'erreur*/
            {
                affichagePile(pt_pilePleine);
                printf("\nValeur dépilé = %d\n",var);
            }
            else printf("Problème lors de la suppression de l'élément\n");
            printf("*---------------------------------------------*\n");
            var=0; /*réinitialisation de var*/
            empiler(pt_pilePleine, 2, err); /*on rend de nouveau la pile pleine pour le reste des tests*/
    
    /*-------------------------------------------------------*/
    /*            test de la fonction estVide            */
    /*          permet de savoir si une pile est vide        */
    /*-------------------------------------------------------*/
    printf("\n\n-----||  TESTS de la fonction estVide(Pile_t * pt_pile)  ||------ \n\n");
        /*Cas n°1: Sur une pile pas vide*/
            printf("\nAffichage CAS 1: test sur une pile NON vide\n\n");
            if(estVide(pt_pilePleine)){
                printf("La pile dans pt_pilePleine est vide (PROBLEME) :(\n");
            }
            else
            {
                printf("La pile dans pt_pilePleine  n'est pas vide (ouf) :) \n");
            }
        /*Cas n°2: Sur une pile vide*/
            printf("\nAffichage CAS 2: test sur une pile VIDE\n\n");
            if(estVide(pt_pileVide)){
                printf("La pile dans pt_pileVide est vide (ouf) :) \n");
            }
            else
            {
                printf("La pile dans pt_pileVide  n'est pas vide (PROBLEME) :( \n");
            }

			
		libererPile(pt_pile); /* on libère l'espace mémoire */
		libererPile(pt_pileVide); /* on libère l'espace mémoire */
		libererPile(pt_pilePleine); /* on libère l'espace mémoire */





	/*----------------------FIN TESTS PILE--------------------------*/









    /*-----------------------------TESTS FILE-----------------------------*/
    printf("\n\n-------Tests FILE---------\n\n");
    File_t   * pt_file=NULL;
    File_t   * pt_fileVide=NULL;
    File_t   * pt_filePleine=NULL;
    int        mis=0;
    element_t  val=0;
    err=&mis;
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
