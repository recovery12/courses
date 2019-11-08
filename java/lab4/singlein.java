// package program

import java.util.Scanner;

class student
{
   private String       sname;
   private int          age;

   student(String val1, int val2)
   {
      this.sname = val1;
      this.age = val2;
   }

   public void displayDetail1()
   {
      System.out.println("Student name is "+sname);
      System.out.println("Student age is "+age);
   }
}

class college extends student
{
   private String        cname;
   private int           num;

   college(String val1, String val2, int val3, int val4)
   {
      super(val1, val3);

      this.cname = val2;
      this.num = val4;
   }

   public void displayDetail1()
   {
      super.displayDetail1();

      System.out.println("College name is "+cname);
      System.out.println("No. of students is "+num);
   }
}

public class singlein
{
   public static void main(String[] args)
   {
      int         age, num;

      String      sname, cname;
      Scanner input = new Scanner(System.in);

      System.out.print("Enter student name: ");
      sname = input.next();
      System.out.print("Enter student age: ");
      age = input.nextInt();

      System.out.print("Enter college name: ");
      cname = input.next();
      System.out.print("Enter no. of students: ");
      num = input.nextInt();

      college demo = new college(sname, cname, age, num);
      demo.displayDetail1();

      return ;
   }
}
