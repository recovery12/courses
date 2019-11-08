#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/********* MAIN STARTS HERE **********/
int main(int argc, char **argv)
{
   int        amt_wd;
   float      cu_bal = 0, fl_bal, tr_charge = 4.50, tr_charge1 = 50.00;

   if (argc != 3)
   {
      fprintf(stderr, "Usage: %s <amount-withdraw> <total-balance>\n", argv[0]);
      exit(1);
   }

   amt_wd = atoi(argv[1]);
   cu_bal = atof(argv[2]);

   if (amt_wd > cu_bal)
   {
      printf("Insufficient Funds/balance.\n");
      exit(3);
   }
   else if (amt_wd == cu_bal)
   {
      printf("Can't withdraw %.2f amount\n", cu_bal);
      printf("Withdrawal possible only upto %.2f\n", cu_bal-(4.50+50.00));
      exit(4);
   }
   else if (amt_wd > cu_bal-(4.50+50.00))
   {
     printf("Can't withdraw %d amount\n", amt_wd);
     printf("Withdrawal possible only upto %.2f\n", cu_bal-(4.50+50.00));
     exit(5);
   }
   
   fl_bal = cu_bal - (float) amt_wd - tr_charge;

   if (fl_bal < 2000)
   {
      printf("Current balance is less than 2000.\n");
      printf("Your transaction is processing.....\n");
      sleep(3);
      fl_bal = fl_bal - tr_charge1;
      printf("The current balance is:- %.2f\n", fl_bal);
      exit(0);
   }

   printf("Your transaction is processing.....\n");
   sleep(3);
   printf("The current balance is:- %.2f\n", fl_bal);

   exit(0);
}
