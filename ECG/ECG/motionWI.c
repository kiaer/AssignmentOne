//
//  motionWI.c
//  ECG
//
//  Created by Cebrail Erdogan on 14/09/13.
//  Copyright (c) 2013 Cebrail Erdogan. All rights reserved.
//

#include <stdio.h>
#include "squared.h"


int motionXn[30];
int motionX;
int motionXss;
int motionY;




int motionWI() {

    
    motionX = squared();
    
    motionY = ( motionX + motionXn[0] + motionXn[1] + motionXn[2] + motionXn[3] + motionXn[4] + motionXn[5] + motionXn[6] + motionXn[7]
               + motionXn[8] + motionXn[9] + motionXn[10] + motionXn[11] + motionXn[12]+motionXn[13]+motionXn[14]+
               motionXn[15]+motionXn[16]+motionXn[17]+motionXn[18]+motionXn[19]+motionXn[20]+motionXn[21]+motionXn[22]+motionXn[23]
               +motionXn[24]+motionXn[25]+motionXn[26]+motionXn[27]+motionXn[28]+motionXn[29])/30;
    
    
    
    motionXn[29] = motionXn[28];
    motionXn[28] = motionXn[27];
    motionXn[27] = motionXn[26];
    motionXn[26] = motionXn[25];
    motionXn[25] = motionXn[24];
    motionXn[24] = motionXn[23];
    motionXn[23] = motionXn[22];
    motionXn[22] = motionXn[21];
    motionXn[21] = motionXn[20];
    motionXn[20] = motionXn[19];
    motionXn[19] = motionXn[18];
    motionXn[18] = motionXn[17];
    motionXn[17] = motionXn[16];
    motionXn[16] = motionXn[15];
    motionXn[15] = motionXn[14];
    motionXn[14] = motionXn[13];
    motionXn[13] = motionXn[12];
    motionXn[12] = motionXn[11];
    motionXn[11] = motionXn[10];
    motionXn[10] = motionXn[9];
    motionXn[9] = motionXn[8];
    motionXn[8] = motionXn[7];
    motionXn[7] = motionXn[6];
    motionXn[6] = motionXn[5];
    motionXn[5] = motionXn[4];
    motionXn[4] = motionXn[3];
    motionXn[3] = motionXn[2];
    motionXn[2] = motionXn[1];
    motionXn[1] = motionXn[0];
    motionXn[0] = motionX;
    
    
    return motionY ;
    
    
}