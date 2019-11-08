//package basic

import java.util.Scanner;

public class whileloop
{
   public static void main(String[] args)
   {
      int    i = 0, n;

      Scanner input = new Scanner(System.in);

      System.out.print("Enter a integer: ");
      n = input.nextInt();

      while (i < n)
      {
         System.out.println(i+" is less than "+n);
         i++;
      }
   }
}
