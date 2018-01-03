import java.io.Serializable;

public class Student implements Serializable{
	String name;
	String id;
	transient double cgpa;
	public Student(String name,String id,double cgpa){
		this.name=name;
		this.id=id;
		this.cgpa=cgpa;
	}
	public void display()
	{
		System.out.println(name+"\n"+id+"\n"+cgpa);
	}

}
