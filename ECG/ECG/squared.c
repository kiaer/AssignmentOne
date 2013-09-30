//
//  squared.c
//  ECG
//
//  Created by Cebrail Erdogan on 14/09/13.
//  Copyright (c) 2013 Cebrail Erdogan. All rights reserved.
//

#include <stdio.h>
#include "derivative.h"
#include <stdlib.h>

int root;

int squared()
{
    root = derivative();
    return root * root;
}

void resetSquared(){
    root = 0;
}