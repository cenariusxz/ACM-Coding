#include<stdio.h>
#include<string.h>

int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int solve(int a,int b,int c){
	int ans=0;
	ans+=(a-1)*365+(a-1)/4;
	for(int i=1;i<b;++i)ans+=m[i];
	ans+=c;
	if( (a%400==0) || ((a%100!=0)&&(a%4==0)) ){
		if(b>2)ans++;
	}
	return ans;
}

int main(){
	while(1){
		int year,month,day;
		scanf("%d%d%d",&year,&month,&day);
		int num1=solve(2016,5,30);
		int num2=solve(year,month,day);
		printf("%d\n",num2-num1);
	}
	return 0;
}
