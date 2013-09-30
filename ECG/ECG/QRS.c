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
    double SPKF = 0;
    double NPKF = 0;
    int THRESHOLD1;
    int THRESHOLD2;
    int RR_AVERAGE1;
    int RR_AVERAGE2;
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
    int count1;
    int count2;
    int inter;
    int counter;
    int missCount = 0;
int start = 0;



typedef struct peak {
    int value;
    int index;
    int RR;
}peak;

peak PEAKS[30], RPEAKS[30];


void UpdateRR_AVERAGE1() {
	double ave = 0;
	int k;
	int ValueCount = 0;
	for (k = 0; k < 8; k++) {
		if (RR_INTERVAL[k] != 0) {
			ValueCount++;
		}
        
		ave += RR_INTERVAL[k];
	}
	RR_AVERAGE1 = ave / (ValueCount);
}


void UpdateRR_AVERAGE2() {
	double ave = 0;
	int k;
	int ValueCount = 0;
	for (k = 0; k < 8; k++) {
		if (RR_INTERVAL_OK[k] != 0) {
			ValueCount++;
			ave += RR_INTERVAL_OK[k];
		}
	}
	RR_AVERAGE2 = ave / ValueCount;
}


void PeakSearchBack() {
	int k, i, j;
	for (k = 1; k < 30; k++) {
		if (PEAKS[k].value > THRESHOLD2) {
			for (i = 29; i > 0; i--) {
				RPEAKS[i] = RPEAKS[i - 1];
			}
			RPEAKS[0] = PEAKS[k];
			for (j = k; j > -1; j--) {
				PEAKS[j].RR = PEAKS[j].index - RPEAKS[0].index;
			}
			return;
		}
	}
    
}





int QRS(){
    
    for(int index = 1; index <= 10000; index++){
       
        //Find a peak
        /* define
         [0] = Xn+1
         [1] = Xn
         [2] = Xn-1
         */

        if ( (peakXn[2] < peakXn[1]) && (peakXn[1] > peakXn[0])){

            
            //Store in PEAKS
            for (int i = 29;  i > 0 ; i--) {
                PEAKS[i] = PEAKS[i-1];
            }
        
            PEAKS[0].value = peakXn[1];
            PEAKS[0].index = index;
            
                
            //Storing done
  
            if ( PEAKS[0].value > THRESHOLD1) {
                
                if (start == 0) {
                    PEAKS[0].RR = PEAKS[0].index;
                    RR_LOW = 0.92 * PEAKS[0].RR;
                    RR_HIGH = 1.16 * PEAKS[0].RR;
                    RR_MISS = 1.66 * PEAKS[0].RR;
                    start = 1;
                } else {
                    PEAKS[0].RR = index - RPEAKS[0].index;
                }
                
                if (PEAKS[0].RR < RR_LOW || PEAKS[0].RR > RR_HIGH)
                {
                    missCount++;
                    if(missCount == 5)
                    {
                        printf("5 successive RR-intervals has missed the RR_LOW and RR_HIGH \n");
                    }
                }

                
                
                
                
                    if (  (PEAKS[0].RR > RR_LOW) && (PEAKS[0].RR < RR_HIGH)     ){
                       
                        for (int i = 29; i > 0; i--) {
                            RPEAKS[i] = RPEAKS[i - 1];
                        }
                        RPEAKS[0] = PEAKS[0];
                      
                        printf("%d  \n", RPEAKS[0].value);
                        if(RPEAKS[0].value < 2000){
                            printf("Rpeak value less than 2000!");
                        }
                        SPKF = 0.125* RPEAKS[0].value +0.875*SPKF;
                    
                    
                    
                        //Store RR in recents
                        for (int i = 7; i >0 ; i--){
                            RR_INTERVAL_OK[i]=RR_INTERVAL_OK[i-1];
                            RR_INTERVAL[i] =  RR_INTERVAL[i - 1];
                        }
                    
                        RR_INTERVAL_OK[0]=RPEAKS[0].RR;
                        RR_INTERVAL[0] =RPEAKS[0].RR;
                        UpdateRR_AVERAGE2();
                        UpdateRR_AVERAGE1();
 
                    

                        RR_LOW = 0.92*RR_AVERAGE2;
                        RR_HIGH = 1.16*RR_AVERAGE2;
                        RR_MISS = 1.66*RR_AVERAGE2;
                        THRESHOLD1 = NPKF + 0.25*(SPKF-NPKF);
                        THRESHOLD2 = 0.5*THRESHOLD1;
                    
                    }
                    else if (PEAKS[0].RR > RR_MISS){
                        //SearchBackwards through PEAKS and return peak2
                        PeakSearchBack();
                       
                        printf("%d  \n", RPEAKS[0].value );
                        if(RPEAKS[0].value < 2000){
                            printf("Rpeak value less than 2000!");
                        }
                        
                        for (int j = 7; j > 0; j--) {
                        RR_INTERVAL[j] = RR_INTERVAL[j - 1];
                        }
                        RR_INTERVAL[0] = RPEAKS[0].RR;
                        UpdateRR_AVERAGE1();
                        SPKF = 0.25 * RPEAKS[0].value + 0.75 * SPKF;
                        RR_LOW = 0.92 * RR_AVERAGE1;
                        RR_HIGH = 1.16 * RR_AVERAGE1;
                        RR_MISS = 1.66 * RR_AVERAGE1;
                        THRESHOLD1 = NPKF + 0.25 * (SPKF - NPKF);
                        THRESHOLD2 = 0.5 * THRESHOLD1;
                        
                    }
                
                
                }
                else{
                        NPKF = 0.125 * PEAKS[0].index + 0.875 * NPKF;
                        THRESHOLD1 = NPKF + 0.25 * (SPKF-NPKF);
                        THRESHOLD2 = 0.5 * THRESHOLD1;
                }
                
            
        }
        
        
        peakXn[2] = peakXn[1];
        peakXn[1]= peakXn[0];
        peakXn[0]= motionWI();
        
    }

    
    
    return 0 ;
}

