//
//  main.c
//  AssignmentOne
//
//  Created by Christian Kiær on 12/09/13.
//  Copyright (c) 2013 Christian Kiær. All rights reserved.
//

#include <stdio.h>
#include "Sensor.h"
#include "main.h"

int main(int argc, const char * argv[])
{
    initialisation();
//    int j = 0;
//    for (int i = 0; i < 1000; i++) {
//        j = getNextData();
//        printf("J is: %i \n", j);
//    }
    return 0;
}

int initialisation(){
    
    // initialize sensor
    initSensor();
    
    // initialize 3 first datapoints
//    int j = 0;
//    for (int i = 0; i < 3; i++) {
//        j = getNextData();
//        printf("ECG reading: %i \n", j);
//        
//    }
    
    return 0;
    
}

int lowPassFilter(int inputData){
    
    int xLow = 0;
    
    return xLow;
}


