//
//  main.c
//  ECG
//
//  Created by Cebrail Erdogan on 04/09/13.
//  Copyright (c) 2013 Cebrail Erdogan. All rights reserved.
//
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include "sensor.h"
#include "lowPass.h"
#include "highPass.h"
#include "derivative.h"
#include "squared.h"
#include "motionWI.h"
#include "QRS.h"

clock_t begin, end;
double CPU_time_used;

void reset(void)
{
    
    resetLowPass();
    resetHighPass();
    resetDerivative();
    resetSquared();
    resetMotionWindow();

}

int main(int argc, const char * argv[])
{
    
    begin=clock();
    init();
    QRS();
    end = clock();  
    
    CPU_time_used = (double)(end - begin) / CLOCKS_PER_SEC;
    
//    printf("LPF Elapsed time: %fs\n", time_spent_lpf );
//    printf("HPF Elapsed time: %fs\n", time_spent_hpf);
//    printf("DER Elapsed time: %fs\n", time_spent_der);
//    printf("MWI Elapsed time: %fs\n", time_spent_mwi);
    printf("Total runtime of program: %fs", CPU_time_used);
    return 0;
    
}


    


