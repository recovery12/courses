import java.util.*;
	
public class stringconstantpool {
	public static void main(String[] args) {
		String s = "prasad";
		String s2 = "prasad";
 
		System.out.println(s.equals(s2));
		System.out.println(s == s2);
	}
}
