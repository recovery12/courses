//pacakge basic

import java.util.Scanner;

abstract class shape
{
   abstract double area(double b, double h);
   abstract double perimeter(double b, double h);
}

class triangle extends shape
{
   private double       b, h;

   double area(double b, double h)
   {
      return 0.5*b*h;
   }

   double perimeter(double b, double h)
   {
      return 2*(b+h);
   }
}

class rectangle extends shape
{
   private double       l, w;

   double area(double l, double w)
   {
      return l*w;
   }

   double perimeter(double l, double w)
   {
      return 2*(l+w);
   }
}

public class abstracts
{
   public static void main(String[] args)
   {
      double          area, peri;
      Scanner input = new Scanner(System.in);

      triangle obj1 = new triangle();
      rectangle obj2 = new rectangle();

      area = obj1.area(2, 3);
      peri = obj2.perimeter(4, 5);

      System.out.println("area is "+area);
      System.out.println("Perimeter is "+peri);

      return ;
   }
}
