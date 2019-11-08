/********** FUNCTION DECLARATION *********/
enum boolean {FALSE, TRUE};

int read_data(FILE *fp1, int set_A[], char filename1[]);
int print_data(int set_A[], int NA);

void uni(int set_A[], int NA, int set_B[], int NB, int set_C[]);
void intersec(int set_A[], int NA, int set_B[], int NB, int set_C[]);
int member_ship(int set_A[], int NA, int sval);
int subset(int set_A[], int NA, int set_B[], int NB, int set_C[]);
void diff(int set_A[], int NA, int set_B[], int NB, int set_C[]);
 
/********* DEFINED CONSTANTS *********/
#define   MAX        20

