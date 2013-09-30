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
#include <time.h>
#include <unistd.h>

int derYn;
int derXn[4];
int derX;
clock_t end, start;
double time_spent_der;

int derivative(){
    
//    start = clock();
    derX = highPass();
    
    derYn = ( 2 * derX + derXn[0] - derXn[2] - 2 * derXn[3]) / 8;
    
    derXn[3] = derXn[2];
    derXn[2] = derXn[1];
    derXn[1] = derXn[0];
    derXn[0] = derX;
//    end = clock();
//    time_spent_der += (double)(end - start) / CLOCKS_PER_SEC;
    return derYn;
    
    
}

void resetDerivative(){
    for (int i = 0; i < sizeof(derXn); i++) {
        derXn[i] = 0;
    }
    derYn = 0;
    derX = 0;
    
}