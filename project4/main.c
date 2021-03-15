#include <stdio.h>
#include <stdlib.h>
#include "summer.h"
#include "shipping.h"

int main(int argc, char** argv) {
    int debug = 0;
    if(argc == 2) { //super *icy* cool *extremely* hidden dev FEATURE
        debug = atoi(argv[1]);
    }
    // run_summer(debug);
    run_shipping();

    return 0;
}

