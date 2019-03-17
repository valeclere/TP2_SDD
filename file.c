//
//  file.c
//  TP2
//
//  Created by Pereira Loann on 17/03/2019.
//  Copyright © 2019 Pereira Loann. All rights reserved.
//

#include "file.h"

File_t* initFile(int taille)
{
    File_t      * pt_File=NULL;
    element_t   * pt_deb=NULL;
    element_t   * pt_fin=NULL;
    element_t   * pt_base=NULL;
    pt_File= (File_t*)malloc(sizeof(File_t));
    //pas fini
    return pt_File;
}

bool estFileVide(File_t fi)
{
    return fi.base==NULL;
}

void libererFile(File_t fi)
{

}
