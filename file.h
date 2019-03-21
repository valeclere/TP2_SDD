//
//  file.h
//  TP2
//
//  Created by Pereira Loann on 17/03/2019.
//  Copyright © 2019 Pereira Loann. All rights reserved.
//

#ifndef file_h
#define file_h
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef int element_t;

typedef struct file{
    int taille;
    int nb_elt;
    element_t * deb;
    element_t * fin;
    element_t * base;
} File_t;


File_t* initFile(int taille);
void enfiler(File_t *pt_fi, element_t val, int *err);
void defiler(File_t *pt_fi,int* err);
bool estFileVide(File_t fi);
void libererFile(File_t * pt_fi);
void affichageFile(File_t *pt_fi);
#endif /* file_h */
