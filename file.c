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
        free(pt_file);
        exit(1);                /* sortie immédiate du code en cas de problème d'allocation */
    }
    pt_file->base=pt_base;
    pt_file->taille=taille;
    pt_file->nb_elt=0;
    pt_file->deb=0;
    pt_file->fin=0;
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
    if(pt_fi->nb_elt<pt_fi->taille)/*on vérifie si la file peut acceuillir un élément supplémentaire*/
    {
        pt_fi->base[pt_fi->fin]=val; /*on place val à l'indice fin de base*/
        pt_fi->fin=(pt_fi->fin+1) % pt_fi->taille; /*on incrémente fin de 1 tout en appliquant le modulo taille*/
                                                   /*car si l'on arrive en fin de tableau au revient au début*/
        pt_fi->nb_elt++;                           /*on incrémente le nombre d'élément*/
        *err=1;
    }

}
/* ----------------------------------------------------------------------------------------------------------- */
/*  defiler : permet d'enlever (défiler) une valeur dans une file                                              */
/*                                                                                                             */
/*  En entrée :                                                                                                */
/*      -pt_fi: pointeur de file                                                                               */
/*      -err  : pointeur d'entier qui permet de gérer l'erreur                                                 */
/* En sortie :                                                                                                 */
/*      -val : correspond à l'élément que l'on défile                                                          */
/* ----------------------------------------------------------------------------------------------------------- */


element_t  defiler(File_t *pt_fi, int* err)
{

    element_t   valDefile = 0; /* variable acceuillant la valeur que l'on défile*/
    *err=0;                    /*car si jamais si n'est pas vérifié alors err restera à 0 et indiquera qu'il y a eu un problème*/
    if(!estFileVide(*pt_fi))   /* on vérifie si la file n'est pas vide, pour qu'on est bien au moins un élément à défiler*/
    {
        valDefile = pt_fi->base[pt_fi->deb];    /* on récupère l'élément ce situant à l'indice début de base*/
        pt_fi->deb=(pt_fi->deb+1)%pt_fi->taille; /*on incrémente deb de 1 tout en appliquant le modulo taille*/
                                                 /*car si l'on arrive en fin de tableau au revient au début*/
        pt_fi->nb_elt--;                         /*on décrémente le nombre d'élément*/
        *err=1;                                 /*on indique que le traitement c'est bien passé en passant la valeur pointé par err à 1*/
    }
    return valDefile; /*on retourne la valeur défilée*/
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
        for(i=pt_fi->deb;i-pt_fi->deb<pt_fi->nb_elt;i++)/*on affiche que les éléments présents entre l'indice deb et fin de base*/
        {
            printf("Emplacement n°%d =" FORMAT_ELT,i+1,pt_fi->base[i]);
        }
    }
    else printf("La file est vide ---> RIEN A AFFICHER\n"); /*si la file est vide*/
}

/* ----------------------------------------------------------------------------------------------------------- */
/*  affichageFile : permet d'afficher la file (utile pour les tests et débogage                                */
/*                                                                                                             */
/*  En entrée :                                                                                                */
/*      -pt_fi: pointeur de file                                                                               */
/* ----------------------------------------------------------------------------------------------------------- */
bool estFileVide(File_t fi)
{
    return fi.base==NULL||fi.nb_elt==0;
}

/* ----------------------------------------------------------------------------------------------------------- */
/*  libererFile : permet de libérer en mémoire l'intégralité de la file                                        */
/*                                                                                                             */
/*  En entrée :                                                                                                */
/*      -pt_fi: pointeur de file                                                                               */
/* ----------------------------------------------------------------------------------------------------------- */

void libererFile(File_t * pt_fi)
{
    free(pt_fi->base);  /*on libère le "tableau" des éléments constituant la file*/
    free(pt_fi);        /*on libère la pointeur sur file*/
}
