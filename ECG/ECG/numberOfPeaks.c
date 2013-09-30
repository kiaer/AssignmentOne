//
//  numberOfPeaks.c
//  ECG
//
//  Created by Cebrail Erdogan on 28/09/13.
//  Copyright (c) 2013 Cebrail Erdogan. All rights reserved.
//

#include <stdio.h>
#include "motionWI.h"
#include "sensor.h"
#include "main.h"

    int peakXn[3];

/* define
 [0] = Xn+1
 [1] = Xn
 [2] = Xn-1
 */

int peaksCounter = 0;


//    Calculate the amount of peaks, so we can determine the size of our array for all peaks
int numberOfPeaks(){

    for (int i=0; i < 10000; i++){
        if ( (peakXn[2] < peakXn[1]) && (peakXn[1] > peakXn[0]) ){
            peaksCounter++;
            
        }
        peakXn[2] = peakXn[1];
        peakXn[1]= peakXn[0];
        peakXn[0]= motionWI();
    }
    
    
    
    return peaksCounter;
}

void resetNumberOfPeaks(){
    peaksCounter = 0;
}
