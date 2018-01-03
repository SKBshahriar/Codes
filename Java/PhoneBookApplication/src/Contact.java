
public class Contact {
	String name;
	String number;
	static int n;
	public void display()
	{
		System.out.println("Name: "+name+", Phone: "+number);
	}
	public void updateNumber(String num)
	{
		number=num;
	}
	public Contact(String name,String number) {
		this.name=name;
		this.number=number;
		n++;
	}
}
