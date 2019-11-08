import java.util.Scanner;

class BankAcc
{
	int	bal = 0;


	void depositMoney(int amt)
	{
		bal = bal+amt;
		System.out.println( amt + "  Deposited");
	}
	void withdrawMoney(int amt)
	{
		bal = bal-amt;
		System.out.println( amt + "  Withdrawn");
	}
	void displayBalance()
	{
		System.out.println("Balance	: "+bal);
	}
}

class Bank
{
	public static void main(String[] args)
	{
		BankAcc RW89 = new BankAcc();

		RW89.depositMoney(1434);
		RW89.withdrawMoney(434);
		RW89.displayBalance();
		RW89.depositMoney(2000);
		RW89.withdrawMoney(25);
		RW89.depositMoney(674);
		RW89.displayBalance();

	}	
}
