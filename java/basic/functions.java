//pacakge basic

import java.util.Scanner;

public class functions
{
   public static void main(String[] args)
   {
      int         n;
      loop obj = new loop();
      Scanner input = new Scanner(System.in);

      System.out.print("Enter the number: ");
      n = input.nextInt();

      forloop(n);
      obj.forloop1(n);
   }

   private static void forloop(int n)
   {
      int        i;

      for (i = 0; i < n; i++)
      {
         System.out.println("Value of i is "+i);
      }
   }

}

class loop
{
   public void forloop1(int n)
   {
      int        i;

      for (i = 0; i < 2*n; i++)
      {
         System.out.println("Value of i is "+i);
      }
   }
}
