import java.io.*;
public class MainClass {

	public static void main(String[] args) {
//		FileOutputStream fos=null;
//		ObjectOutputStream oos=null;
		FileInputStream fis=null;
		ObjectInputStream ois=null;
		Student student=new Student("Sakib", "011143138", 3.33);
		try {
			fis=new FileInputStream("E:\\s.txt");
			ois=new ObjectInputStream(fis);
//			oos.writeObject(student);
			Object a=ois.readObject();
			Student s=(Student)a;
			s.display();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}

		finally {
			try {
				fis.close();
				ois.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
