import java.util.*;
import java.io.*;
public class text{
	static int a=100;
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		while(input.hasNext()){
			int n=input.nextInt();
			System.out.println(n);
		}
		input.close();
	}
}