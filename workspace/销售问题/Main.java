import java.util.*;

public class Main{
	public static void main(String[] args){
		int goal=30000-5000;
		int ans=0;
		if(5000*0.08>=goal){
			ans=(int)(goal/0.08);
			if(ans*0.08<goal)ans++;
		}
		else if(5000*0.08+5000*0.1>=goal){
			ans=(int)((goal-5000*0.08)/0.1)+5000;
			if(5000*0.08+(ans-5000)*0.1<goal)ans++;
		}
		else{
			ans=(int)((goal-5000*0.08-5000*0.1)/0.12)+10000;
			if(5000*0.08+5000*0.1+(ans-10000)*0.12<goal)ans++;
		}
		System.out.println("最小销售量："+ans);
	}
}