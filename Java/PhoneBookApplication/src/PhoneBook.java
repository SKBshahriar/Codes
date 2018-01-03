import java.util.Scanner;

public class PhoneBook {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		Contact[] c=new Contact[10];
		while(true)
		{
			System.out.println("Enter 1 to display the records");
			System.out.println("Enter 2 to add new phone number");
			System.out.println("Enter 3 to update phone number");
			System.out.println("Enter 4 to exit the system");
			int ans=in.nextInt();
			if(ans==1)
			{
				for(int i=0;i<Contact.n;i++)
					c[i].display();
			}
			else if(ans==2)
			{
				if(Contact.n<10)
				{
					System.out.println("Enter name and number");
					in.nextLine();
					String name=in.nextLine();
					String number=in.nextLine();
					c[Contact.n]=new Contact(name, number);
				}
				else
					System.out.println("Phonebook memory is full");
			}
			else if(ans==3)
			{
				in.nextLine();
				System.out.println("Enter Name");
				String name=in.nextLine();
				int i;
				for(i=0;i<Contact.n;i++)
				{
					if(c[i].name.equals(name))
					{
						System.out.println("Enter Number");
						String number=in.nextLine();
						c[i].number=number;
						break;
					}
				}
				if(i==Contact.n)
					System.out.println("Contact not found");
			}
			else {
				break;
			}
					
		}
	}

}
