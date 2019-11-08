package assign1;

import java.util.Scanner;

public class account
{
   public static void main(String[] args)
   {
      int      opt;
      double   inter;
      String   name;

      BankAccount obj = new Customer();
      Scanner input = new Scanner(System.in);

      System.out.println("What type of account do u want to open?");
      System.out.println("1) Current Account");
      System.out.println("2) Savings Account");
      System.out.print("Select your option: ");
      opt = input.nextInt();

      if (opt == 1)
      {
         System.out.print("Enter the name of organisation: ");
         name = input.next();
         obj.currentAccount(name);
      }
      else if (opt == 2)
      {
         System.out.print("Enter the name of person: ");
         name = input.next();
         System.out.print("Enter the rate of interest: ");
         inter = input.nextDouble();
         obj.savingsAccount(name, inter);
      }

      System.exit(0);
   }
}

abstract class BankAccount
{
   abstract void currentAccount(String org);
   abstract void savingsAccount(String per, double interest);
}

class Customer extends BankAccount
{
   private double inter;
   private double amt;
   private String panno;

   Scanner input = new Scanner(System.in);

   void currentAccount(String org)
   {
      System.out.print("Enter the Capital of the organisation: ");
      amt = input.nextDouble();

      if (amt > 50000)
      {
         System.out.print("Enter your pan no.: ");
         panno = input.next();
      }
   }

   void savingsAccount(String per, double interest)
   {
      System.out.print("Enter the Deposit amount: ");
      amt = input.nextDouble();

      if (amt > 50000)
      {
         System.out.print("Enter your pan no.: ");
         panno = input.next();
      }

      inter = amt*interest/12;
      System.out.println("Your monthly interest is "+inter);
   }
}
