//pacakge basic

import java.util.Scanner;

public class breaks
{
   public static void main(String[] args)
   {
      int       i, j, n;

      Scanner input = new Scanner(System.in);

      System.out.print("Enter a +ve integer: ");
      n = input.nextInt();

      for (i = 0; i < n; i++)
      {
         if (i == 3)
         {
            break;  //Simply a break statement
         }
      }


      first:
      for (i = 0; i < n; i++)
      {
         second:
         for (j = 0; j < 5; j++)
         {
            System.out.printf("i = %d and j = %d\n", i, j);
            if (i == 2)
            {
               break first;
            }
         }
      }
   }
}
