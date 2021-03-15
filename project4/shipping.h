struct package {
    int id;
    int* order;
    int isFragile;
    int numSteps; /* size of order array */
    char* content;
    struct package *last;
};

struct worker {
    char* name;
    int id;
    int color;
    struct package *currentPackage;
};


int run_shipping();

struct package* create_package(int id, char* content);
struct worker* create_worker(int id, int team, char* name);
void print_worker();
void print_package();

