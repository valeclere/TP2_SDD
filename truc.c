//
//  truc.c
//  TP2
//
//  Created by Pereira Loann on 17/03/2019.
//  Copyright © 2019 Pereira Loann. All rights reserved.
//

#include "truc.h"
#include "pile.h"

/* --------------------------------------------------------------------------------------- */
/*  truc_rec : fonction récursive qui affiche toutes les permutations de la liste envoyée  */
/*                                                                                         */
/*  En entrée :                                                                            */
/*  	-i = indice à partir duquel on commence les permutations                           */
/*  	-n = taille de la liste                                                            */
/*  	-T[] = liste contenant des truc_t (int, float, char,..)                            */
/*                                                                                         */
/*  Pas de sortie                                                                          */
/* --------------------------------------------------------------------------------------- */

void truc_rec(int i, int n, truc_t T[])
{
    int       j;
    int       temp;
    printf("Appel de TRUC avec i=%d et n=%d et ",i,n);
    affichageT(T, n);
    if(i==n)
    {
		 printf("\n");
        for(j=0;j<n;j++)
        {
            printf(FORMAT_TRUC,T[j]);
        }
        printf("\n");
    }
    else
    {
        printf("\n");
        for(int tmp=i;tmp>=1;tmp--)printf("\t");
        for(j=i;j<n;j++)
        {
            temp=T[i];
            T[i]=T[j];
            T[j]=temp;
            printf("i+1=%d",i+1);
            printf("\n\t");
            for(int tmp=i;tmp!=0;tmp--)printf("\t");
            truc_rec(i+1,n,T);
            temp=T[i];
            T[i]=T[j];
            T[j]=temp;
        }
    }
}

void affichageT(truc_t *T, int taille)
{
    int i;
    for(i=0;i<taille;i++)
        printf(" | T[%d]="FORMAT_TRUC,i,T[i]);
}

/* ------------------------------------------------------------- */
/*  echange : fonction qui échange deux valeurs dans la liste    */
/*                                                               */
/*  En entrée :                                                  */
/*  	-i,j = indices des valeurs à échanger                    */
/*  	-T[] = liste contenant des truc_t (int, float, char,..)  */
/*                                                               */
/*  Pas de sortie                                                */
/* ------------------------------------------------------------- */

void echange(truc_t T[], int i, int j)
{
	truc_t tmp;
	tmp = T[i];
	T[i] = T[j];
	T[j] = tmp;
}


/* --------------------------------------------------------------------------------------- */
/*  truc_ite : fonction itérative qui affiche toutes les permutations de la liste envoyée  */
/*                                                                                         */
/*  En entrée :                                                                            */
/*  	-i = indice à partir duquel on commence les permutations                           */
/*  	-n = taille de la liste                                                            */
/*  	-T[] = liste contenant des truc_t (int, float, char,..)                            */
/*                                                                                         */
/*  Pas de sortie                                                                          */
/* --------------------------------------------------------------------------------------- */

void truc_ite(int i, int n, truc_t T[])
{
	int j=0;
	Pile_t * pt_pile = NULL; 
	int taille_tab = 10; 
	pt_pile = initPile(taille_tab);
	bool fin = false;
	
	do
	{
		if (j<n)
		{
			echange(T, i, j);
			empiler(pt_pile, j);
			i++;
			j=i;
		}
	
		else
		{
			if (i==n)
			{
				for (j=0; j<n; j++)
				{
					printf(" %c", T[j]);
				}
				printf("\n");
			}
			
			if (!estVide(pt_pile))
			{
				j = depiler(pt_pile);
				i--;
				echange(T, i, j);
				j++;
			}
			
			else
			{
				fin = true;
			}
		}
	} while(!fin);
	
	libererPile(pt_pile);
}
			
			
