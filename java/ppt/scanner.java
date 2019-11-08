// package ppt;

import java.util.Scanner;

public class scanner
{ 
   public static void main(String[] args) 
   { 
      Scanner sc = new Scanner(System.in);
      System.out.print("Enter your name: ");
      String name = sc.nextLine(); 
      System.out.print("Enter your gender: ");
      char gender = sc.next().charAt(0);
      System.out.print("Enter your age: ");
      int age = sc.nextInt(); 
      System.out.print("Enter your mobile no.: ");
      long mobileNo = sc.nextLong(); 
      System.out.print("Enter you cgpa: ");
      double cgpa = sc.nextDouble(); 

      System.out.println("Name: "+name);
      System.out.println("Gender: "+gender);
      System.out.println("Age: "+age);
      System.out.println("Mobile Number: "+mobileNo); 
      System.out.println("CGPA: "+cgpa); 
   }
}

