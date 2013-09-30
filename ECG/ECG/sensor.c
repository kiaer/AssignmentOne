#include <stdio.h>
#include <stdlib.h>
#include "sensor.h"

static const char filename[] = "/Users/christiankiaer/Documents/Embedded Systems/AssignmentOne/ECG/ECG/ECG.txt";
FILE *file;
int next;

void init(){
    file =  fopen ( filename, "r" );
}

void close(){
    fclose(file);
    
}


int getNextData(){
    
    fscanf(file, "%i",&next);
    
	return next;
}