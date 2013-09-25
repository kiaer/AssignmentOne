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
    
   
    if (THRESHOLD1 < peaksX) {
        
        CalcRR
        
        if (RR_low<RR<RR_high){
            Store peak as Rpeak
            SPKF=0.125+0.875*NPKF
            Store RR in recentRR_OK
            Store RR in recentRR
            RR_AVARAGE2 = avg of RecentRR_OK
            RR_AVARAGE1 = avg of RecentRR
            RR_LOW = 0.9*RR_AVARAGE2
            RR_HIGH = 1.16*RR_AVARAGE2
            RR_MISS = 1.66*RR_AVARAGE2
            THRESHOLD1 = NPKF + 0.25*(SPKF-NPKF)
            THRESHOLD2 = 0.5*THRESHOLD1
        }
        else{
        while (1) {
   
            if (RR>RR_MISS) {
                SearchBackwards through PEAKS and return peak2
                if (peaks2>THRESHOLD2) {
                    break
                }
            }
        }
        Store peak as Rpeak
        SPKF = 0.25*peak+0.75*SPKF
        STORE RR in RecentRR
        RR_AVARAGE1 = avg of RecentRR
        RR_LOW = 0.9*RR_AVARAGE2
        RR_HIGH = 1.16*RR_AVARAGE2
        RR_MISS = 1.66*RR_AVARAGE2
        THRESHOLD1 = NPKF + 0.25*(SPKF-NPKF)
        THRESHOLD2 = 0.5*THRESHOLD1
        
        
    }
    
    NPKF = 0.125 * peaksX + 0.875 * NPKF;
    THRESHOLD1 = NPKF + 0.25*(SPKF-NPKF);
    THRESHOLD2 = 0.5*THRESHOLD1;
    }
    
    
//    Peaks counter
    if ( peaksXn[2] < peaksXn[1] && peaksXn[1] > peaksXn[0]){
    //calculate the threshold
        
        
        
       
    }



    peaksXn[2] = peaksXn[1];
    peaksXn[1]= peaksXn[0];
    peaksXn[0]= peaksX;

    
    return RR_INTERVAL;
}



