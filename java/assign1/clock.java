import java.util.*;
import java.text.SimpleDateFormat;

class clock
{
	public static void main(String[] args)
	{
		int     c;
		Scanner input = new Scanner(System.in);

		System.out.println("1. Analog Display");
		System.out.println("2. Digital Display");
		System.out.print("Enter	option	: ");
		c = input.nextInt();

		if (c == 1)
		{
			AnalogDisplay obj = new AnalogDisplay();
			obj.displayTime();
		}
		else if (c == 2)
		{
			DigitalDisplay obj = new DigitalDisplay();
			obj.displayTime();
		}
		else
		{
			System.out.println("Invalid option.");
		}
		System.exit(0);
	}
}

interface ClockDisplay
{
	public void displayTime();
}

class AnalogDisplay implements ClockDisplay
{
	public void displayTime()
	{
		int       val;
		String    analog;

		Date d = new Date();
		SimpleDateFormat sdf = new SimpleDateFormat("kk:mm:ss");

		analog = sdf.format(d);
		val = Integer.parseInt(analog.substring(0, 2));

		if (val > 12 && val < 25)
		{
			val = val - 12;
		}

		System.out.println("Time	: " +val+analog.substring(2, analog.length()));

		return ;
	}
}

class DigitalDisplay implements ClockDisplay
{
	public void displayTime()
	{
		Date d = new Date();
		SimpleDateFormat sdf = new SimpleDateFormat("HH:mm:ss");
		System.out.println("Time	: "+sdf.format(d));

		return ;
	}
}
