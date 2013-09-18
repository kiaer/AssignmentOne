//
//  Sensor.c
//  AssignmentOne
//
//  Created by Christian Kiær on 12/09/13.
//  Copyright (c) 2013 Christian Kiær. All rights reserved.
//

#include <stdio.h>


static const char filename[] = "/users/christiankiaer/Downloads/ECG.txt";
FILE *file;

int getNextData(){
    
    int i1;
    fscanf(file,"%i",&i1);
    return i1;
    
}

int initSensor(){
    
    file = fopen ( filename, "r" );
    return 0;
}