
public class InvalidGradeException extends Exception{
	public InvalidGradeException()
	{
		super();
	}
	public InvalidGradeException(double a,double b)
	{
		super("input should be between "+a+" and "+b);
	}
}
