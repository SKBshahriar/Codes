import java.util.Random;
public class Class1 {
	static int[] a=new int[15];
	public static void main(String[] args) {
		Thread t1=new Thread(new GenerateNumber(0));
		Thread t2=new Thread(new GenerateNumber(5));
		Thread t3=new Thread(new GenerateNumber(10));
		t1.start();
		t2.start();
		t3.start();
		try {
			t1.join();
			t2.join();
			t3.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		int sum=0;
		for(int i=0;i<15;i++)
			sum=sum+a[i];
		System.out.println(sum);
	}
}
