import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args){
		Scanner input=new Scanner(System.in);
		int goal=(int)(Math.random()*100);
		int now=0;
		while(true){
			System.out.println("请输入您的猜想（0~100）");
			now=input.nextInt();
			if(now<goal)System.out.println("猜想过小！");
			else if(now>goal)System.out.println("猜想过大！");
			if(now==goal){
				System.out.println("猜中了！");
				break;
			}
		}
		input.close();
	}
}