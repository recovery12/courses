// package program;

import java.util.Scanner;

public class calcy
{
   public static void main(String[] args)
   {
      int           option;
      String        e, f;
      double        a, b, c;

      Scanner input = new Scanner(System.in);
      CalculatorEngine work = new CalculatorEngine();

      option = work.displayMenu();

      switch (option)
      {
         case 1:
                System.out.print("Enter first value: ");
                e = input.next();
                System.out.print("Enter second value: ");
                f = input.next();
                try
                {
                   a = Double.parseDouble(e);
                   b = Double.parseDouble(f);
                }
                catch(NumberFormatException E)
                {
                   System.out.println("Cant convert str to double");
                   return ;
                }
                c = work.add(a, b);
                break;
         case 2:
                System.out.print("Enter first value: ");
                a = input.nextDouble();
                System.out.print("Enter second value: ");
                b = input.nextDouble();
                c = work.sub(a, b);
                break;
         case 3:
                System.out.print("Enter first value: ");
                a = input.nextDouble();
                System.out.print("Enter second value: ");
                b = input.nextDouble();
                c = work.mul(a, b);
                break;
         case 4:
                System.out.print("Enter Dividend: ");
                a = input.nextDouble();
                System.out.print("Enter Divisor: ");
                b = input.nextDouble();
                c = work.div(a, b);
                break;
         case 5:
                System.out.print("Enter first value: ");
                a = input.nextDouble();
                System.out.print("Enter second value: ");
                b = input.nextDouble();
                c = work.mod(a, b);
                break;
         case 6:
                System.out.print("Enter Base: ");
                a = input.nextDouble();
                System.out.print("Enter Index: ");
                b = input.nextDouble();
                c = work.pow(a, b);
                break;
         case 7:
                System.out.print("Enter first value: ");
                a = input.nextDouble();
                c = work.sqrt(a);
                break;
         default:
                return ;
      }

      work.displayValue(c);
      return ;
   }
}

class CalculatorEngine
{   
   public static int displayMenu()
   {
      int        opt;
      Scanner input = new Scanner(System.in);

      System.out.println("************** OPERATIONS **********************");
      System.out.println("1) Addition");
      System.out.println("2) Subtraction");
      System.out.println("3) Multiplication");
      System.out.println("4) Division");
      System.out.println("5) Modulus");
      System.out.println("6) Exponential");
      System.out.println("7) Square root");
      System.out.println("8) Exit\n");

      System.out.println("Select your option:-  ");
      opt = input.nextInt();

      return opt;
   }

   public static double add(double a, double b)
   {
      return a+b;
   }

   public static double sub(double a, double b)
   {
      return a-b;
   }

   public  static double mul(double a, double b)
   {
      return a*b;
   }

   public  static double div(double a, double b)
   {
      int        c = 0;
      try
      {
         c = (int)a/(int)b;
      }
      catch (ArithmeticException E)
      {
         System.out.println("Cannot divide by zero and exception is "+E);
      }
         return c;
   }

   public  static double mod(double a, double b)
   {
      int        c = 0;
      try
      {  
         c = (int)a%(int)b;
      }
      catch (ArithmeticException E)
      {  
         System.out.println("Cannot find mod zero and exception is "+E);
      }
         return c;
   }

   public  static double pow(double a, double b)
   {
      int       c = 0;

      try
      {
         c = (int)Math.pow((int)a, (int)b);
         return c;
      }
      catch (Exception E)
      {
         System.out.println("Cannot raise zero to the power -ve");
      }
      return c;
   }

   public  static double sqrt(double a)
   {
      double     y = 1, x = a, err = Math.pow(0.1, 3);
      
      while (x-y > err)
      {
         x = (x+y)/2;
         y = a/x;
      }

      return x;
   }

   public static void displayValue(double c)
   {
      System.out.println("The computed value from the operation is "+c);
      return ;
   }
}

