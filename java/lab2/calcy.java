// package program

import java.util.Scanner;

public class calcy
{
   public static void main(String[] args)
   {
      int           option;
      double        a, b, c;

      Scanner input = new Scanner(System.in);
      CalculatorEngine work = new CalculatorEngine();

      option = work.displayMenu();

      switch (option)
      {
         case 1:
                System.out.print("Enter first value: ");
                a = input.nextDouble();
                System.out.print("Enter second value: ");
                b = input.nextDouble();
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
                System.out.print("Enter first value: ");
                a = input.nextDouble();
                System.out.print("Enter second value: ");
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
                System.out.print("Enter first value: ");
                a = input.nextDouble();
                System.out.print("Enter second value: ");
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
      if (b == 0)
      {
         System.out.println("division with zero is not possible.");
         return 0;
      }

      return a/b;
   }

   public  static double mod(double a, double b)
   {
      return a%b;
   }

   public  static double pow(double a, double b)
   {
      return Math.pow(a, b);
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

