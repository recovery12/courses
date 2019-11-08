//pacakge basic

public class strings
{
   public static void main(String[] args)
   {
      int       n;
      char      ch[] = {'a','n','u','r','a','g','.','p','e','d','d','i'};
      String s = new String(ch); //Is equal to String s = "anurag";

      System.out.println(s);
      System.out.println(s.substring(1,7));
      System.out.printf("%c ", s.charAt(8));
      System.out.println(s.concat("1998@gmail.com"));
      System.out.print(s.contains("ag.pedd"));
      System.out.println(s.endsWith("ddi"));
      System.out.println(s.startsWith("anuhya"));
      System.out.println(s.indexOf("p"));
      System.out.println(s.join(".", "anurag", "peddi1998@gmail", "com"));
      System.out.print("     anurag     ".trim());
      System.out.println(s.replaceAll("a", "g"));
   }
}
