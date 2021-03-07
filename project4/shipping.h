
enum steps{Weighing, Barcoding, Xraying, Jostiling};



struct package {
    int id;
    int* order;
    int isFragile;
    int numSteps; /* size of order array */
    int currentStep;
    int isQueued;
    struct package *last;
} package;

struct worker {
    char* name;
    int team;
    char* color;
    struct package currentPackage;
} worker;


int run_shipping();

struct package create_package();
struct worker create_worker();

