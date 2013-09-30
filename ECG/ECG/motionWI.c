//
//  motionWI.c
//  ECG
//
//  Created by Cebrail Erdogan on 14/09/13.
//  Copyright (c) 2013 Cebrail Erdogan. All rights reserved.
//

#include <stdio.h>
#include "squared.h"
#include "lowPass.h"
#include "highPass.h"
#include "derivative.h"
#include "squared.h"

int motionXn[30];
int motionX;
int motionY;




int motionWI() {

    
    motionX = squared();
    
    motionY = (  motionXn[0] + motionXn[1] + motionXn[2] + motionXn[3] + motionXn[4] + motionXn[5] + motionXn[6] + motionXn[7]
               + motionXn[8] + motionXn[9] + motionXn[10] + motionXn[11] + motionXn[12]+motionXn[13]+motionXn[14]+
               motionXn[15]+motionXn[16]+motionXn[17]+motionXn[18]+motionXn[19]+motionXn[20]+motionXn[21]+motionXn[22]+motionXn[23]
               +motionXn[24]+motionXn[25]+motionXn[26]+motionXn[27]+motionXn[28]+motionXn[29])/30;
    
    
    
    
    for (int i = sizeof(motionXn) / sizeof(int) -1;  i >= 0 ; i--) {
        if (i > 0) {
            motionXn[i] = motionXn[i-1];
        }
        else{
            motionXn[0] = motionX;
        }
    }
    

    return motionY ;
    
    
}
void resetMotionWindow(){
    for (int i=0; i < sizeof(motionXn); i++) {
        motionXn[i] = 0;
    }
    motionY = 0;
    motionX = 0;
}





