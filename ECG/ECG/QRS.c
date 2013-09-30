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



    int RR_PEAKS[8];
    int RR_PEAKS_HIGH[8];
    int SPKF;
    int NPKF;
    int THRESHOLD1;
    int THRESHOLD2;
    int RR_AVARAGE1;
    int RR_AVARAGE2;
    int RR_LOW;
    int RR_HIGH;
    int RR_MISS;
    int RRinterval;
    int RR_INTERVAL_OK[8];
    int RR_INTERVAL[8];
    int RR_INTERVAL_elementsCount;
    int RR_INTERVAL_OK_elementsCount;
    int IntervalCounter;
    int peakXn[3];
    int RRcounterForAVG;
    int peak2;
    int inter;
int counter;
int PEAKS[197];
int Rpeaks[197];


int QRS(){
    

    
    
    
    for(int i = 0; i < 10000; i++){
        IntervalCounter++;
        
        //Find a peak
        /* define
         [0] = Xn+1
         [1] = Xn
         [2] = Xn-1
         */
//        printf("%i \n", XnPeaks[0]);
        if ( (peakXn[2] < peakXn[1]) && (peakXn[1] > peakXn[0])){
            //            printf("%i Peak Found \n", justCounter++);
//          printf("%i         ",counter++);
//           printf("%i < %i, %i > %i \n", peakXn[2], peakXn[1], peakXn[1],peakXn[0]);
//
            
            //Store in PEAKS
            for (int i = 197-1;  i >= 0 ; i--) {
                
                if (i > 0) {
                    PEAKS[i] = PEAKS[i-1];
                }
                else{
                    PEAKS[0] = peakXn[1];
                }
                
            }//Storing done
            
            
            
            
            
            if (peakXn[1] > THRESHOLD1) {
                
                //Calculate RR Interval
                RRinterval = IntervalCounter;
                inter += RRinterval;
             
                IntervalCounter = 0;
                
                if (RR_INTERVAL_OK_elementsCount < 8) {
                    RR_INTERVAL_OK_elementsCount++;
                }
                if (RR_INTERVAL_elementsCount < 8) {
                    RR_INTERVAL_elementsCount++;
                }
                /// -->
                
                
                
 
                if ((RR_LOW < RRinterval) && (RRinterval < RR_HIGH)){

                    
                    //Store peak as Rpeak
                    for (int i = 197 -1;  i >= 0 ; i--) {
                        
                        if (i > 0) {
                            Rpeaks[i] = Rpeaks[i-1];
                        }
                        else{
                            Rpeaks[0] = peakXn[1];
                        }
                        
                    }//Storing done
                    
                    
                    SPKF = 0.125*peakXn[1]+0.875*SPKF;
                    
                    
                    
                    //Store RR in recentRR_OK
                    for (int i = 7; i >=0 ; i--){
                        if ( i > 0){
                            RR_INTERVAL_OK[i]=RR_INTERVAL_OK[i-1];
                            
                        }
                        else {
                            RR_INTERVAL_OK[0]=RRinterval;
                        }
                        
                    }//Storing done
                    
                    
                    //Store RR in recentRR
                    for (int i = 7; i >=0 ; i--){
                        if ( i > 0){
                            RR_INTERVAL[i]=RR_INTERVAL[i-1];
                            
                        }
                        else {
                            RR_INTERVAL[0]=RRinterval;
                        }
                        
                    }//Storing done
                    
                    //RR_AVARAGE2 = avg of RecentRR_OK
                    for (int i = 0; i < 8; i++) {
                        RR_AVARAGE2 += RR_INTERVAL_OK[i];
                    }
                    RR_AVARAGE2 = RR_AVARAGE2/RR_INTERVAL_OK_elementsCount;
                    
                    
                    //RR_AVARAGE1 = avg of RecentRR
                    for (int i = 0; i < 8; i++) {
                        RR_AVARAGE1 += RR_INTERVAL[i];
                    }
                    RR_AVARAGE1 = RR_AVARAGE1/RR_INTERVAL_elementsCount;
                    
                    
                    RR_LOW = 0.92*RR_AVARAGE2;
                    RR_HIGH = 1.16*RR_AVARAGE2;
                    RR_MISS = 1.66*RR_AVARAGE2;
                    THRESHOLD1 = NPKF + 0.25*(SPKF-NPKF);
                    THRESHOLD2 = 0.5*THRESHOLD1;
                    
                }
                else if (RRinterval > RR_MISS){
                    //SearchBackwards through PEAKS and return peak2
                    // --->
                    
                    int k = 1;
                    while ( !(peak2 > THRESHOLD2)) {
                        peak2 = PEAKS[k];
                        k++;
                    }
                    if (peak2 > THRESHOLD2) {
                        //Store peak as Rpeak
                       
                        for (int i = 197 -1;  i >= 0 ; i--) {
                            
                            if (i > 0) {
                                Rpeaks[i] = Rpeaks[i-1];
                            }
                            else{
                                Rpeaks[0] = peakXn[1];
                            }
                            
                        }//Storing done
                        
                        
                        SPKF = 0.25*peakXn[1]+0.75*SPKF;
                        //Store RR in recentRR
                        for (int i = 7; i >=0 ; i--){
                            if ( i > 0){
                                RR_INTERVAL[i]=RR_INTERVAL[i-1];
                                
                            }
                            else {
                                RR_INTERVAL[0]=RRinterval;
                            }
                            
                        }//Storing done
                        
                        //RR_AVARAGE1 = avg of RecentRR
                        
                        for (int i = 0; i < 8; i++) {
                            RR_AVARAGE1 += RR_INTERVAL[i];
                        }
                        RR_AVARAGE1 = RR_AVARAGE1/RR_INTERVAL_elementsCount;
                        
                        RR_LOW = 0.92* RR_AVARAGE1;
                        RR_HIGH = 1.16 * RR_AVARAGE1;
                        RR_MISS = 1.66 * RR_AVARAGE1;
                        THRESHOLD1 = NPKF + 0.25*(SPKF-NPKF);
                        THRESHOLD2 = 0.5 * THRESHOLD1;
                    }
                    
                }
                
                
            }
            else{
                
                NPKF = 0.125 * peakXn[1] + 0.875*NPKF;
                THRESHOLD1 = NPKF + 0.25 * (SPKF-NPKF);
                THRESHOLD2 = 0.5 * THRESHOLD1;
            }
            
        }
        
        
        peakXn[2] = peakXn[1];
        peakXn[1]= peakXn[0];
        peakXn[0]= motionWI();
        
    }
    for (int i=196; i > 0; i--) {
        printf("%i \n", Rpeaks[i]);
    }
    
    return 0 ;
}




