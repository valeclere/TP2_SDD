//
//  file.c
//  TP2
//
//  Created by Pereira Loann on 17/03/2019.
//  Copyright © 2019 Pereira Loann. All rights reserved.
//

#include "file.h"

/* ----FONCTIONS DU MODULE---- */

/* ----------------------------------------------------------------------------------------------------------- */
/*  initFile : créer une structure file au format suivant:                                                     */
/*                                                                                                             */
/*                                                                                                             */
/*  En entrée :                                                                                                */
/*      -taille = entier correspondant à la taille du tableau contenant les éléments                           */
/*                                                                                                             */
/*  En sortie :                                                                                                */
/*      -pt_file = pointeur sur la structure file créée                                                        */
/* ----------------------------------------------------------------------------------------------------------- */

File_t* initFile(int taille)
{
    File_t      * pt_file=NULL;
    element_t   * pt_base=NULL;
    
    pt_file= (File_t*)malloc(sizeof(File_t));
    if (pt_file == NULL)        /* si l'allocation du pointeur de file échoue */
    {
        printf("problème d'allocation de la pile");
        exit(1);                /* sortie immédiate du code en cas de problème d'allocation */
    }
    pt_base=(element_t*)malloc(sizeof(element_t)*taille);
    if (pt_base == NULL)        /* si l'allocation de la file échoue */
    {
        printf("problème d'allocation de la pile");
        exit(1);                /* sortie immédiate du code en cas de problème d'allocation */
    }
    pt_file->base=pt_base;
    pt_file->taille=taille;
    pt_file->deb=&pt_base[taille-1];       /*le pointeur de début pointe sur ce que pointe pt_base càd le dernier élément de la file*/
    pt_file->fin=&pt_base[taille-1];       /*idem pour fin car pour le moment il y a 0 élément*/
    return pt_file;             /*on retourne la file*/
}

/* ----------------------------------------------------------------------------------------------------------- */
/*  enfiler : permet d'ajouter une valeur dans une file                                                        */
/*                                                                                                             */
/*  En entrée :                                                                                                */
/*      -pt_fi: pointeur de file                                                                               */
/*      -val  : élément que l'on veut ajouter                                                                  */
/*      -err  : pointeur d'entier qui permet de gérer l'erreur                                                 */
/* ----------------------------------------------------------------------------------------------------------- */

void enfiler(File_t *pt_fi, element_t val, int *err)
{
    if(pt_fi->nb_elt+1<=pt_fi->taille) /*on vérifie s'il y a assez de place pour ajouter un élément*/
    {
        if(pt_fi->nb_elt>=1) /*on regarde s'il y a au moins un élément dans notre file*/
        {
            (pt_fi->deb)--;/*on recule le pointeur début sur le nouvelle "case" on l'on va l'ajouté*/
        }           /*si on a 0 élément on apas besoin de décaler le pointeur car deb et fin pointeront sur le même unique élément*/
        *(pt_fi->deb)=val;
        pt_fi->nb_elt++; /*on incrément le nombre d'élément que si on a pu l'ajouter*/
        *err=1; /* on met le pointeur d'erreur à 1 pour indiquer que tout c'est bien passé*/
    }
    else
    {
        *err=0;/* on met le pointeur d'erreur à 0 pour indiquer qu'il y a eu un problème*/
    }
}

void defiler(File_t *pt_fi,int* err){
    int i;
    if(pt_fi->nb_elt>0)/*si la file n'est pas vide*/
    {
        if (pt_fi->nb_elt==1) {
            pt_fi->deb=pt_fi->fin;
        }
        else{
            for(i=0;i<pt_fi->nb_elt;i++){
                *((pt_fi->fin)-i)= *((pt_fi->fin)-i-1);
            }
            pt_fi->deb++;
        }
         pt_fi->nb_elt--;
        
    }
    
}

/* ----------------------------------------------------------------------------------------------------------- */
/*  affichageFile : permet d'afficher la file (utile pour les tests et débogage                                */
/*                                                                                                             */
/*  En entrée :                                                                                                */
/*      -pt_fi: pointeur de file                                                                               */
/* ----------------------------------------------------------------------------------------------------------- */

void affichageFile(File_t *pt_fi)
{
    int i;
    if(pt_fi->nb_elt!=0){
        for(i=0;(pt_fi->deb)+i<=pt_fi->fin;i++) {
            printf("Elément n°%d =" FORMAT,pt_fi->nb_elt-i,*((pt_fi->deb)+i));
        }
    }
    else printf("La file est vide ---> RIEN A AFFICHER\n");

}


bool estFileVide(File_t fi)
{
    return fi.base==NULL;
}

void libererFile(File_t * pt_fi)
{
    free(pt_fi->base);
    free(pt_fi);
}
