//package basic

import java.util.Scanner;
import java.lang.*;

public class integers
{
   public static void main(String[] args)
   {
      int        n, len;
      int        arr[];           //declare an array
      arr = new int[20];          //allocate memory

      int arr2[] = new int[20];      //Both at a place
      int arr3[] = {0,1,2,3,4,5,6,7,8,9}; //array literal

      len = arr2.length;             //length function
      Scanner input = new Scanner(System.in);
      Integer val1 = new Integer(10);

      System.out.print("Enter a base: ");
      n = input.nextInt();

      Integer val = Integer.valueOf("62", n); //Int obj in base n
      System.out.println("Value is "+val);
      System.out.println("Value is "+val1.valueOf("2345"));
      System.out.println("Value of 22314 in Ox is "+Integer.toHexString(22314));
      System.out.println("53 << 3 "+Integer.rotateLeft(53, 3));
      //System.out.println("54 in float "+"54".floatValue());
      System.out.println("43526 in hash "+Integer.hashCode(43526));
   }
}
