//
//  truc.c
//  TP2
//
//  Created by Pereira Loann on 17/03/2019.
//  Copyright © 2019 Pereira Loann. All rights reserved.
//

#include "truc.h"

void truc(int i, int n, truc_t T[])
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
            truc(i+1,n,T);
            temp=T[i];
            T[i]=T[j];
            T[j]=temp;
        }
    }
}
