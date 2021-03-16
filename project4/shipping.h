struct package {
    int id;
    int* order;
    int isFragile;
    int numSteps; /* size of order array */
    char* content;
    struct worker *worker;
    struct package *last;
};

struct worker {
    char* name;
    int id;
    int color;
    struct package *currentPackage;
    int packages_proc;
};


int run_shipping(int arg);

struct package* create_package(int id, char* content);
struct worker* create_worker(int id, char* name);
void print_worker();
void print_package();
void print_results();

