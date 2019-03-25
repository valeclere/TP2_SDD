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

#define FORMAT_ELT "%d\n"
typedef int element_t; /* type de variables présentes dans le tableau, ici on considère des int */

typedef struct file{
    int taille;
    int nb_elt;
    int  deb;
    int  fin;
    element_t * base;
} File_t;


File_t* initFile(int taille);
void enfiler(File_t *pt_fi, element_t val, int *err);
element_t  defiler(File_t *pt_fi,int* err);
bool estFileVide(File_t fi);
void libererFile(File_t * pt_fi);
void affichageFile(File_t *pt_fi);
#endif /* file_h */
