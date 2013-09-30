//
//  lowPass.c
//  ECG
//
//  Created by Cebrail Erdogan on 11/09/13.
//  Copyright (c) 2013 Cebrail Erdogan. All rights reserved.
//

#include <stdlib.h>
#include "sensor.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int LPYn[2];
int LPXn[12];
int x, y;
clock_t end, start;
double time_spent_lpf;

int lowPass(){
    
//    start = clock();
    
    x = getNextData();

    int y = ( x - 2 * LPXn[5] + LPXn[11])/32  + 2 * LPYn[0] - LPYn[1];
    LPYn[1] = LPYn[0];
    LPYn[0] = y;
   
    /* Xn */
    LPXn[11] = LPXn[10];
    LPXn[10] = LPXn[9];
    LPXn[9] = LPXn[8];
    LPXn[8] = LPXn[7];
    LPXn[7] = LPXn[6];
    LPXn[6] = LPXn[5];
    LPXn[5] = LPXn[4];
    LPXn[4] = LPXn[3];
    LPXn[3] = LPXn[2];
    LPXn[2] = LPXn[1];
    LPXn[1] = LPXn[0];
    LPXn[0] = x;
    
//    end = clock();
//    time_spent_lpf += (double)(end - start) / CLOCKS_PER_SEC;
    
    return y;
}

void resetLowPass(){
    for (int i = 0; i < sizeof(LPXn); i++) {
        LPXn[i] = 0;
    }
    LPYn[1] = 0;
    LPYn[0] = 0;
    x = 0; y = 0;

}

