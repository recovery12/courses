/********* DEFINED CONSTANTS *********/
#define MAX        10
#define MAXMEM     32
#define BLOCKSIZE  128

/********* FUNCTION DECLARATION *********/
int arr_len(int proc_com[], int size);
void initialize(int array[], int size);
int put_proc_inwait(int q[], int ind);
void alloc_mem(int q[], int qi, int pm[]);
int dealloc_mem(int pm[], int proc_com[], int ind);
void ext_frag(int pm[]);
void print_status(int pm[], int proc_com[], int q[]);
void print_array(int arr[], int size);  // For tracing or debugging

