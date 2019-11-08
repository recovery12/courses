//package basic

public class output
{
   public static void main(String[] args)
   {
      int      a = 9;

      System.out.println("Welcome to java!"); //println appends "\n" atlast
      System.out.print("Welcome to");   //print doesn't append
      System.out.print(" java!");
      System.out.println("Value of a is "+a);
      prac1();
   }

   public static void prac1()
   {
      String         str = "anurag";
      //printf is used to do formatting similar to c/c++
      System.out.printf("My name is %s", str);
   }
}

