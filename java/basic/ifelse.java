//package basic

import java.util.Scanner;

public class ifelse
{
   public static void main(String[] args)
   {
      int      num;

      Scanner input = new Scanner(System.in);

      System.out.print("Enter a number: ");
      num = input.nextInt();

      if (num > 50)
      {
         System.out.println(num + " is greater than 50");
      }
      else if (num == 0)
      {
         System.out.println(num + " is ZER0");
      }
      else
      {
         System.out.println(num + " is less than 50");
      }
   }
}
