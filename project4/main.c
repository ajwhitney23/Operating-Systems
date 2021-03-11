#include <stdio.h>
#include <stdlib.h>
#include "summer.h"
#include "shipping.h"

int main(int argc, char** argv) {
    int debug = 0;
    if(argc == 2) {
        debug = 1;
    }
    run_summer(debug);
    // run_shipping();

    return 0;
}

