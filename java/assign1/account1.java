package assign1;

import java.util.Scanner;

public class account1
{
   public static void main(String[] args)
   {
      int      opt;
      Scanner input = new Scanner(System.in);

      System.out.println("What type of account do u want to open?");
      System.out.println("1) Current Account");
      System.out.println("2) Savings Account");
      System.out.print("Select your option: ");
      opt = input.nextInt();

      if (opt == 1)
      {
         CurrentAccount obj = new CurrentAccount();
         obj.createAccount();
      }
      else if (opt == 2)
      {
         SavingsAccount obj = new SavingsAccount();
         obj.createAccount();
         obj.calculateInterest();
      }

      System.exit(0);
   }
}

abstract class BankAccount
{
   String   name;

   abstract void createAccount();
}

/*class Customer
{
   boolean           type;
   List<BankAccount> bank;

   Customer(List<BankAccount> bank, boolean val1)
   {
      this.bank = bank;
      this.type = val1
   }

}*/

class CurrentAccount extends BankAccount
{
   private double      amt;
   private String      name, panno, bnkname;
   Scanner input = new Scanner(System.in);

   public void createAccount()
   {
      System.out.print("Enter the Name of the bank: ");
      bnkname = input.next();
      super.name = bnkname;

      System.out.print("Enter the Name of the organisation: ");
      name = input.next();

      System.out.print("Enter the Capital of the organisation: ");
      amt = input.nextDouble();

      if (amt > 50000)
      {
         System.out.print("Enter your pan no.: ");
         panno = input.next();
      }
   }
}

class SavingsAccount extends BankAccount
{
   private double      amt, inter;
   private String      name, panno, bnkname;
   final double        INTER = 0.78;
   Scanner input = new Scanner(System.in);

   public void createAccount()
   {
      System.out.print("Enter the Name of the bank: ");
      bnkname = input.next();
      super.name = bnkname;

      System.out.print("Enter the your name: ");
      name = input.next();

      System.out.print("Enter the Deposit amount: ");
      amt = input.nextDouble();

      if (amt > 50000)
      {
         System.out.print("Enter your pan no.: ");
         panno = input.next();
      }
   }

   public void calculateInterest()
   {
      inter = amt*INTER/12;
      System.out.println("Your monthly interest is "+inter);
   }
}
