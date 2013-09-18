//
//  derivative.c
//  ECG
//
//  Created by Cebrail Erdogan on 14/09/13.
//  Copyright (c) 2013 Cebrail Erdogan. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
#include "sensor.h"
#include "lowPass.h"
#include "highPass.h"


int derYn;
int derXn[4];
int derX;

int derivative(){
    
    derX = highPass();
    
    derYn = ( 2 * derX + derXn[0] - derXn[2] - 2 * derXn[3]) / 8;
    
    derXn[3] = derXn[2];
    derXn[2] = derXn[1];
    derXn[1] = derXn[0];
    derXn[0] = derX;
    
    return derYn;
}