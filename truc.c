//
//  truc.c
//  TP2
//
//  Created by Pereira Loann on 17/03/2019.
//  Copyright © 2019 Pereira Loann. All rights reserved.
//

/*  |  */

#include "truc.h"
#include "pile.h"


/*  truc|  */

void truc_rec(int i, int n, truc_t T[])
{
    int       j;
    int       temp;
    if(i==n)
    {
        for(j=0;j<n;j++)
        {
            printf("T[%d]=" FORMAT_TRUC,j,T[j]);
        }
         printf("----------------\n");
    }
    else
    {
        for(j=i;j<n;j++)
        {
            temp=T[i];
            T[i]=T[j];
            T[j]=temp;
            truc_rec(i+1,n,T);
            temp=T[i];
            T[i]=T[j];
            T[j]=temp;
        }
    }
}


/*  |  */

void echange(truc_t T[], int i, int j)
{
	truc_t tmp;
	tmp = T[i];
	T[i] = T[j];
	T[j] = tmp;
}


/*  |  */

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
			
			
