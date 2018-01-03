package Practice;
import java.awt.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;

import Pkg.*;
public class MainClass {

	public static void main(String[] args) {
		LinkedList<Integer>linkedlist=new LinkedList<Integer>();
		linkedlist.add(1);linkedlist.add(9);linkedlist.add(7);
		linkedlist.add(8);linkedlist.add(5);linkedlist.add(6);
		linkedlist.addLast(11);linkedlist.addFirst(80);
		linkedlist.sort(null);
		
		
		ArrayList<Student>arrayList=new ArrayList<Student>();
		arrayList.add(new Student("abc", 3.33, 23));
		arrayList.add(new Student("hug", 3.01, 21));
		arrayList.add(new Student("kjo", 3.11, 25));
		arrayList.add(new Student("bcd", 3.38, 22));
		arrayList.add(new Student("zxy", 3.23, 20));
	}
	public final static synchronized void print()
	{
		System.out.println("sakib");
	}
	public final static synchronized void print(int s)
	{
		System.out.println("sakib "+s);
	}
}
