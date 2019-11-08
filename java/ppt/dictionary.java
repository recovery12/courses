//package ppt;

import java.util.*;
import java.util.Dictionary;

public class dictionary
{ 
   public static void main(String[] args)  
   { 

      Dictionary java = new Hashtable(); 

      java.put("123", "Code"); 
      java.put("456", "Program"); 

      for (Enumeration i = java.elements(); i.hasMoreElements();) 
      { 
         System.out.println("Value in Dictionary : " + i.nextElement()); 
      } 

      System.out.println("\nValue at key = 6 : " + java.get("6")); 
      System.out.println("Value at key = 456 : " + java.get("123")); 
      System.out.println("There is no key-value pair : " +java.isEmpty()+"\n"); 

      for (Enumeration k = java.keys(); k.hasMoreElements();) 
      { 
         System.out.println("Keys in Dictionary : " + k.nextElement()); 
      } 

      System.out.println("\nRemove : " + java.remove("123")); 
      System.out.println("Check the value of removed key : " + java.get("123"));
      System.out.println("\nSize of Dictionary : " + java.size()); 

   } 
} 

