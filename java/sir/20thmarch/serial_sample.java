import java.io.*;
class SerialSample implements Serializable
{
	void method()
	{
		System.out.println("method in SerialSample");
	}
}
class Test
{
	public static void main(String args[])
	{
		SerialSample ss = new SerialSample(); 
        	String filename = "sample.ser";  
        try
        {    
            FileOutputStream file = new FileOutputStream(filename); 
            ObjectOutputStream out = new ObjectOutputStream(file); 
            out.writeObject(ss); 
            out.close(); 
            file.close();
	    System.out.println("object is serialized");
        }   
        catch(IOException ex) 
        {  
		    System.out.println("Exception occurred"); 
        } 
	SerialSample ss1;
        try
        {     
            FileInputStream file = new FileInputStream(filename); 
            ObjectInputStream in = new ObjectInputStream(file);  
            ss1 = (SerialSample)in.readObject();  
            in.close(); 
            file.close();
            System.out.println("Object has been deserialized ");
	    ss1.method(); 
        }
	catch(IOException ex) 
        { 
            System.out.println("Exception is occurred"); 
        }
	catch(ClassNotFoundException e)
	{
		System.out.println("Exception occurred");
	}  
	}
}
