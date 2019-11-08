//package basic

import java.util.Scanner;

public class input
{
   public static void main(String[] args)
   {
      int      number;
      float    num2;
      Double   num3;

      Scanner input = new Scanner(System.in);

      System.out.print("Enter an integer: ");
      number = input.nextInt();
      System.out.println("You entered " + number);

      System.out.print("Enter a float: ");
      num2 = input.nextFloat();
      System.out.println("You entered " + num2);

      System.out.print("Enter a double: ");
      num3 = input.nextDouble();
      System.out.print("You entered "+ num3);

      System.out.print("Enter a char: ");
      char a = input.next().charAt(1);
      System.out.println("You entered: "+a);
   }
}
