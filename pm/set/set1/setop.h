/********* FUNCTION DECLARATION *********/
enum boolean {FALSE, TRUE};

int read_data(FILE *fp1, int set_A[]);
int print_data(int set_A[], int NA);

void do_union(int set_A[], int NA, int set_B[], int NB, int set_C[], FILE *fp1, char filename1[], FILE *fp2, char filename2[]);
void do_intersec(int set_A[], int NA, int set_B[], int NB, int set_C[], FILE *fp1, char filename1[], FILE *fp2, char filename2[]);
void do_membership(int set_A[], int NA, int sval, FILE *fp1, char filename1[]);
void do_subset(int set_A[], int NA, int set_B[], int NB, int set_C[], FILE *fp1, char filename1[], FILE *fp2, char filename2[]);
void do_diff(int set_A[], int NA, int set_B[], int NB, int set_C[], FILE *fp1, char filename1[], FILE *fp2, char filename2[]);


void uni(int set_A[], int NA, int set_B[], int NB, int set_C[]);
void intersec(int set_A[], int NA, int set_B[], int NB, int set_C[]);
int member_ship(int set_A[], int NA, int sval);
int subset(int set_A[], int NA, int set_B[], int NB, int set_C[]);
void diff(int set_A[], int NA, int set_B[], int NB, int set_C[]);
 
/********* DEFINED CONSTANTS *********/
#define   MAX        20

