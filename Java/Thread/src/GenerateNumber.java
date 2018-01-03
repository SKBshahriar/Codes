import java.util.Random;

public class GenerateNumber implements Runnable{
	int i;
	public GenerateNumber(int i)
	{
		this.i=i;
	}

	public void run() {
		Random random=new Random();
		for(int j=i;j<i+5;j++)
		{
			Class1.a[j]=random.nextInt(100);
		}
	}
}
