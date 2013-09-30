#include <stdio.h>
#include <stdlib.h>
#include "sensor.h"

<<<<<<< HEAD
static const char filename[] = "/Users/christiankiaer/Documents/Embedded Systems/AssignmentOne/ECG/ECG/ECG.txt";
=======
static const char filename[] = "/Users/jonathanbecktor/Downloads/ECG10800K.txt";
>>>>>>> 791dac3cf6c4ca957fe3e4300225b7da569b6a56
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