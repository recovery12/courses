// package ppt;

import java.util.Arrays; 
  
public class arrays
{ 
   public static void main(String[] args) 
   {
      int k = 22;
      int intArr[] = { 10, 20, 15, 22, 35 }; 
      int intArr1[] = { 10, 15, 22 };

      Arrays.sort(intArr);
      System.out.println("Integer Array as List: "+Arrays.asList(intArr));
      System.out.println("Sorted Array: "+intArr);
      System.out.println("key found at index= "+Arrays.binarySearch(intArr, k));
      System.out.println("Comparison: "+Arrays.equals(intArr, intArr1));
   } 
} 
