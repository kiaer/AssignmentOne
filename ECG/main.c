//
//  main.c
//  ECG
//
//  Created by Cebrail Erdogan on 04/09/13.
//  Copyright (c) 2013 Cebrail Erdogan. All rights reserved.
//
#include <stdlib.h>
#include "sensor.h"
#include <stdio.h>
#include "lowPass.h"
#include "highPass.h"
#include "derivative.h"
#include "squared.h"
#include "motionWI.h"
#include "searchPeaks.h"

int main(int argc, const char * argv[])
{
    init();
    for (int i = 0; i < 10000; i++) {
        printf("%i \n",searchPeaks());
    }
//   printf("%i \n",motionWI());
   
    return 0;
}

