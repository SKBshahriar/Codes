package Sychronization;

public class BankAccount {
	int total;
	String name;
	public BankAccount(int total,String name)
	{
		this.name=name;
		this.total=total;
	}
	public void diposit(int a)
	{
		total+=a;
	}
	public void withdraw(int a)
	{
		total-=a;
	}
	public void balance()
	{
		System.out.println("your final balance is "+total);
	}
}
