//package basic

import java.util.Scanner;

public class arthimetic
{
   public static void main(String[] args)
   {
      int    num1, num2, sum, var;

      Scanner input = new Scanner(System.in);

      System.out.print("Enter a integer: ");
      num1 = input.nextInt();
      System.out.print("Enter a integer: ");
      num2 = input.nextInt();

      sum = num1 + num2;
      var = num1 * num2;

      System.out.printf("Addition is %d\n", sum);
      System.out.println("Subtraction is "+(num1-num2));
      System.out.printf("Multiplication is %d\n", var);
      System.out.println("Division is "+(num1/num2));
   }
} 
