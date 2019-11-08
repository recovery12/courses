//pacakge ppt;

import java.util.Currency;

public class currency
{ 
   public static void main(String[] args) 
   {
      int        D1, D2;
      String     cCode1, cCode2;

      Currency c1 = Currency.getInstance("AUD"); //Australian Dollar 
      Currency c2 = Currency.getInstance("JPY");  //Japan Yen 
      Currency c3 = Currency.getInstance("USD");  //Japan Yen 
  
      cCode1 = c1.getCurrencyCode(); 
      cCode2 = c2.getCurrencyCode(); 
      System.out.println("Australian Dollar code : " + cCode1); 
      System.out.println("Japan Yen code : " + cCode2); 
      System.out.println(""); 
  
      D1 = c1.getDefaultFractionDigits(); 
      System.out.println("AUD Fraction digits : " + D1); 
  
      D2 = c2.getDefaultFractionDigits(); 
      System.out.println("JPY fraction digits : " + D2); 
      System.out.println(""); 
  
      System.out.println("AUD Display : "+c1.getDisplayName()); 
      System.out.println("JPY Display : "+c2.getSymbol()); 
      System.out.println(""); 
  
      System.out.println("JPY Symbol : "+c2.getSymbol()); 
      System.out.println("USD Symbol : "+c3.getSymbol()); 
   } 
} 
