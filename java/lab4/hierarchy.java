// package program;

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

class course extends student
{
   private String       coname;
   private int          id;

   course(String val1, int val2, String val3, int val4)
   {
      super(val3, val4);

      this.coname = val1;
      this.id = val2;
   }

   public void displayDetail1()
   {
      super.displayDetail1();

      System.out.println("Course name is "+coname);
      System.out.println("Course id is "+id);
   }
}

class sports extends student
{
   private String        spname;
   private int           spid;

   sports(String val1, String val2, int val3, int val4)
   {
      super(val1, val3);

      this.spname = val2;
      this.spid = val4;
   }

   public void displayDetail1()
   {
      super.displayDetail1();

      System.out.println("Sport name is "+spname);
      System.out.println("Sport id "+spid);
   }
}

class college extends course
{
   private String        cname;
   private int           num;

   college(String val1, String val2, int val3, int val4, String val5, int val6)
   {
      super(val1, val3, val5, val6);

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

public class hierarchy
{
   public static void main(String[] args)
   {
      int         age, num, id, spid;

      String      sname, cname, coname, spname;
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
      System.out.print("Enter course id: ");
      id = input.nextInt();

      System.out.print("Enter sports name: ");
      spname = input.next();
      System.out.print("Enter sports id: ");
      spid = input.nextInt();

      college demo = new college(coname, cname, id, num, sname, age);
      sports demo1 = new sports(sname, spname, age, spid);
      demo.displayDetail1();
      demo1.displayDetail1();

      return ;
   }
}
