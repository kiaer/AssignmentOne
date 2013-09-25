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
    int RR_PEAKS[8];
    int RR_PEAKS_HIGH[8];
    int RR_PEAKS[8];
    int peaksX;
    int SPKF;
    int NPKF;
    int THRESHOLD1;
    int THRESHOLD2;
    int RR_AVARAGE1;
    int RR_AVARAGE2;
    int RR_LOW;
    int RR_HIGH;
    int RR_MISS;
    int RR_INTERVAL;
    int Interval;
    int IntervalCounter;


/* define
 [0] = Xn+1
 [1] = Xn
 [2] = Xn-1 
 */

int searchPeaks(){
    
    peaksX = motionWI();
    IntervalCounter++;
    
   
    THRESHOLD1 =  NPKF + 0.25 * (SPKF - NPKF);
    
    
    if (THRESHOLD1 < peaksX) {
        
        
        
        
        
    }
    SPKF = 0.125 * peaksX + 0.875 * SPKF;
    NPKF = 0.125 * peaksX + 0.875 * NPKF;
    
//    Peaks counter
    if ( peaksXn[2] < peaksXn[1] && peaksXn[1] > peaksXn[0]){
    //calculate the threshold
        
        
        
       
    }



    peaksXn[2] = peaksXn[1];
    peaksXn[1]= peaksXn[0];
    peaksXn[0]= peaksX;

    
    return RR_INTERVAL;
}



