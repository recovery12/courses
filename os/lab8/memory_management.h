/********* DEFINED CONSTANTS *********/
#define   FNAME           25
#define   MAXCHAR         20
#define   LLIMIT          512
#define   MAXFRAMES       1024
#define   ULIMIT          4096
#define   PAGESIZE        4096
#define   MEMFULL         -1
#define   TERMINATED      0
#define   CONTINUE        1
#define   INFILE          2
#define   OUTFILE         3
#define   GLOBAL          4
#define   LOCAL           5

/********* DATA-STRUCTURE DEFINITION *********/
typedef struct PHY_MEM
{
   int        pid;
   int        pgnum;
} memory;

typedef struct FIRSTFRAME
{
   bool       first;
   int        firstframe;
   int        cur_frame;
} firstframe;

/********* GLOBAL VARIABLES *********/
Queue         proc_queue;
memory        phy_mem[MAXFRAMES];
FILE          *file_desp[MAXFRAMES];

/********* FUNCTION DECLARATION *********/
void swap(int *a, int *b);
int no_of_digits(int num);
void shuffle_q(int arr[], int size);
void initialize_ready_q(int np);
int rand_range(int lower, int upper);
int sim_process(int m, int s, FILE *fp);
void make_process(int pid, int m, int s);
int mem_mapper(FILE *ifp, FILE *ofp, int pid);
bool in_memory(int pid, int index, int addr, FILE *ofp);
int page_fifo_global();
int page_fifo_local(int pid);
void display_frametable();
void filename(char *fname, int pid, int param);