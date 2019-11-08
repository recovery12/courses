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

class course extends student
{
   private String        coname;
   private int           id;

   course(String val1, String val2, int val3, int val4)
   {
      super(val1, val3);

      this.coname = val2;
      this.id = val4;
   }

   public void displayDetail1()
   {
      super.displayDetail1();

      System.out.println("Course name is "+coname);
      System.out.println("No. of students in course are "+id);
   }
}

public class multiplein
{
   public static void main(String[] args)
   {
      int         age, num, id;

      String      sname, cname, coname;
      Scanner input = new Scanner(System.in);

      System.out.print("Enter student name: ");
      sname = input.next();
      System.out.print("Enter student age: ");
      age = input.nextInt();

      System.out.print("Enter college name: ");
      cname = input.next();
      System.out.print("Enter no. of students: ");
      num = input.nextInt();

      System.out.print("Enter course name: ");
      coname = input.next();
      System.out.print("Enter no. of students in course: ");
      id = input.nextInt();

      college demo = new college(sname, cname, age, num);
      course demo1 = new course(sname, coname, age, id);
      demo.displayDetail1();
      demo1.displayDetail1();

      return ;
   }
}
