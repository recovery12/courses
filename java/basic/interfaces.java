//pacakge basic

import java.util.Scanner;

interface sample
{
   double compute_pay(int hours, double rate);
   //int multiply(int num1, int num2);
}

class person implements sample
{
   private double       wage;

   public double compute_pay(int hours, double rate)
   {
      wage = hours*rate;
      return wage;
   }
}

public class interfaces
{
   public static void main(String[] args)
   {
      int         h;
      double      r;

      Scanner input = new Scanner(System.in);
      person obj = new person();

      System.out.print("Enter the no. of hours: ");
      h = input.nextInt();

      System.out.print("Enter the rate: ");
      r = input.nextDouble();

      System.out.println("Wage is "+obj.compute_pay(h, r));

      return ;
   }
}
