//
//  truc.h
//  TP2
//
//  Created by Pereira Loann on 17/03/2019.
//  Copyright © 2019 Pereira Loann. All rights reserved.
//

#ifndef truc_h
#define truc_h

#include <stdio.h>

#define FORMAT_TRUC "%c\n"
typedef char truc_t;

void truc_rec(int i, int n, truc_t T[]);
void echange(truc_t T[], int i, int j);
void truc_ite(int i, int n, truc_t T[]);

#endif /* truc_h */
