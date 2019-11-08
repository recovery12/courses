//pacakge basic

import java.util.Scanner;

public class forloop
{
   public static void main(String[] args)
   {
      int         i, n;

      Scanner input = new Scanner(System.in);

      System.out.print("Enter the value of n: ");
      n = input.nextInt();

      for (i = 0; i < n; i++)
      {
         System.out.println(i+" is less than "+n);
      }

      //Infinte loop
      //for (;;);

   }
}
