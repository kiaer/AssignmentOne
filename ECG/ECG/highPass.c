//
//  highPass.c
//  ECG
//
//  Created by Cebrail Erdogan on 14/09/13.
//  Copyright (c) 2013 Cebrail Erdogan. All rights reserved.
//

#include <stdlib.h>
#include "sensor.h"
#include "lowPass.h"
#include <stdio.h>

int Xn[40];
int Yn_1;
int dataPoint, y;



int highPass(){

    
    
    
    dataPoint = lowPass();
    y =  Yn_1 - (dataPoint/32) + (Xn[15] - Xn[16]) + (Xn[31]/32);
    Yn_1 = y;
    
    /* Xn datapoints */
  
    Xn[31] = Xn[30];
    Xn[30] = Xn[29];
    Xn[29] = Xn[28];
    Xn[28] = Xn[27];
    Xn[27] = Xn[26];
    Xn[26] = Xn[25];
    Xn[25] = Xn[24];
    Xn[24] = Xn[23];
    Xn[23] = Xn[22];
    Xn[22] = Xn[21];
    Xn[21] = Xn[20];
    Xn[20] = Xn[19];
    Xn[19] = Xn[18];
    Xn[18] = Xn[17];
    Xn[17] = Xn[16];
    Xn[16] = Xn[15];
    Xn[15] = Xn[14];
    Xn[14] = Xn[13];
    Xn[13] = Xn[12];
    Xn[12] = Xn[11];
    Xn[11] = Xn[10];
    Xn[10] = Xn[9];
    Xn[9] = Xn[8];
    Xn[8] = Xn[7];
    Xn[7] = Xn[6];
    Xn[6] = Xn[5];
    Xn[5] = Xn[4];
    Xn[4] = Xn[3];
    Xn[3] = Xn[2];
    Xn[2] = Xn[1];
    Xn[1] = Xn[0];
    Xn[0] = dataPoint;
    
    return y;
}

void resetHighPass(){
    for (int i = 0; i < sizeof(Xn); i++) {
        Xn[i] = 0;
    }
    dataPoint= 0;
    Yn_1 = 0;
}

