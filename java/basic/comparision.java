//pacakge basic

import java.util.Scanner;

public class comparision
{
   public static void main(String[] args)
   {
      int      num1, num2;

      Scanner input = new Scanner(System.in);

      System.out.print("Enter a integer: ");
      num1 = input.nextInt();
      System.out.print("Enter a integer: ");
      num2 = input.nextInt();

      if (num1 == num2)
      {
         System.out.println(num1+" is equal to "+num2);
      }
      else
      {
         System.out.println(num1+" is not equal to "+num2);
      }
   }
}
