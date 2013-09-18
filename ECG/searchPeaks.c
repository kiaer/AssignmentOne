//
//  SearchPeaks.c
//  ECG
//
//  Created by Cebrail Erdogan on 18/09/13.
//  Copyright (c) 2013 Cebrail Erdogan. All rights reserved.
//
#include <stdlib.h>
#include "sensor.h"
#include <stdio.h>
#include "motionWI.h"

    int peaksXn[3];
    int peaksX;
    int countPeaks;

// define
// [0] = Xn+1
// [1] = Xn
// [2] = Xn-1

int searchPeaks(){
    
    peaksX = motionWI();
    
    if ( peaksXn[2] < peaksXn[1] && peaksXn[1] > peaksXn[0]){
        countPeaks++;
        printf("true");
        
    }
    
    peaksXn[2] = peaksXn[1];
    peaksXn[1]= peaksXn[0];
    peaksXn[0]= peaksX;
    
    
    
    return countPeaks;
}