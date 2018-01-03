package Pkg;
import java.util.Scanner;

public class MainClass {
	
	public static InvalidGradeException ige=new InvalidGradeException(0, 12);
	public int sakib;
	
	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		int a=scan.nextInt();
		if(a<0 || a>10)
			try {
				throw new InvalidGradeException(0,10);
			} catch (InvalidGradeException e) {
				System.out.println(e.getMessage());
			}
		/*Scanner scan=new Scanner(System.in);
		try {
			int a = 1;
			int b = 42 / a;
			System.out.println("a = " + a);
			try { 
				if(a==1) 
					a = a/(a-a); 
				if(a==2) {
					int c[] = { 1 };
					c[42] = 99; 
				}
			} catch(ArrayIndexOutOfBoundsException e) {
				System.out.println("Array index out-of-bounds: " + e);
			}
		} catch(ArithmeticException e) {
			System.out.println("Divide by 0: " + e);
			e.printStackTrace();
		}
		System.out.println("sakib");
		try {
			System.out.println(rett(5));
		} catch (Exception e) {
			System.out.println(e);
		}
		boolean is=false;
		while(!is)
		{
			try {
				System.out.println("Enter a number");
				int n=scan.nextInt();
				is=true;
			} catch (Exception e) {
				System.out.println("Enter a valid number");
				scan.nextLine();
			}
		}*/
	}
	
	
}


