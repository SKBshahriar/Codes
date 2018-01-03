
public class TempClass extends Thread {

	int a;
	String b;
	public void run() {
		print();	
	}
	public void print()
	{
		for(int i=0;i<100;i++)
		{
			System.out.println("Thread1: "+i);
			try {
				sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
