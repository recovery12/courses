import java.lang.*;
class Test
{
	public static void main(String args[])
	{
		Integer num =new Integer(4);
		num=null;
		System.gc(); 
	}
	protected void finalize() throws Throwable 
    	{ 
        	System.out.println("Garbage collector called");  
    	}
} 

