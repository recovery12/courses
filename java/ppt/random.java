// package ppt;

import java.util.Random; 

public class random
{ 
   public static void main(String[] args) 
   {
      int  i;
      long seed = 95; 
      byte[] bytes = new byte[10]; 
      Random random = new Random();

      System.out.println(random.nextInt(10)); 
      System.out.println(random.nextBoolean()); 
      System.out.println(random.nextDouble()); 
      System.out.println(random.nextFloat()); 
      System.out.println(random.nextGaussian()); 
      random.nextBytes(bytes); 
      System.out.printf("["); 
      for(i = 0; i< bytes.length; i++) 
      { 
         System.out.printf("%d ", bytes[i]); 
      } 
      System.out.printf("]\n"); 
		
      System.out.println(random.nextLong()); 
      System.out.println(random.nextInt()); 
	
      random.setSeed(seed); 
   } 
}	 

