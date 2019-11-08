//package basic

import java.util.Scanner;

public class converters
{
   public static void main(String[] args)
   {
      int       a;
      float     b;
      char      c;
      Double    d;

      Scanner input = new Scanner(System.in);

      System.out.print("Enter a char: ");
      c = input.next().charAt(0);

      a = Integer.parseInt(args[0]);
      b = Float.parseFloat(args[1]);
      d = Double.parseDouble("5.41236");
      System.out.println(a+" is int and "+c+" float is "+b+" "+d);
   }
}
