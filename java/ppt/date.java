// package ppt;

import java.util.Date; 
  
public class date
{
   public static void main(String[] args) 
   {
      int           c;
      boolean       a, b;

      Date d1 = new Date(); 
      System.out.println("Current date is " + d1); 
      Date d2 = new Date(2323223232L); 
      System.out.println("Date represention is "+ d2 );

      //Date d2 = new Date(2000, 11, 21); 
      Date d3 = new Date(2010, 1, 3); 
  
      a = d3.after(d1); 
      System.out.println("Date d3 comes after " + "date d2: " + a); 
  
      b = d3.before(d1); 
      System.out.println("Date d3 comes before "+ "date d2: " + b); 
  
      c = d1.compareTo(d1); 
      System.out.println(c); 
  
      System.out.println("Miliseconds from Jan 1 "+"1970 to date d1 is " + d1.getTime()); 
  
      System.out.println("Before setting "+d1); 
      d2.setTime(204587433443L); 
      System.out.println("After setting "+d1);
   }
}
