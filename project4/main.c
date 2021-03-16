#include <stdio.h>
#include <stdlib.h>
#include "summer.h"
#include "shipping.h"

int main(int argc, char** argv) {
    int debug = 0;
    int toRun = 0;
    if(argc > 1) { //super *icy* cool *extremely* hidden dev FEATURE
        debug = atoi(argv[1]);
        if(argc > 2) {
            toRun = atoi(argv[2]);
        }
    }
    if(toRun == 2) {
        run_shipping(debug);
    } else if(toRun == 1){  
        run_summer(debug);
    } else {
        run_summer(debug);
        run_shipping(debug);
    }

    return 0;
}

