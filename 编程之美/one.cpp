#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x*=10;
		x+=(c-'0');
		c=getchar();
	}
	return x;
}

char s1[20],s2[20];

int main(){
	int t;
	while(scanf("%d",&t)!=EOF){
		int m1,y1,m2,y2,d1,d2;
		for(int q=1;q<=t;q++){
			scanf("%s",s1);
			d1=read();
			y1=read();
			scanf("%s",s2);
			d2=read();
			y2=read();
			if(s1[0]=='J'){
				if(s1[1]=='a')m1=1;
				else if(s1[2]=='n')m1=6;
				else if(s1[2]=='l')m1=7;
				
			}
			else if(s1[0]=='F')m1=2;
			else if(s1[0]=='M'){
				if(s1[2]=='r')m1=3;
				else if(s1[2]=='y')m1=5;
			}
			else if(s1[0]=='A'){
				if(s1[1]=='p')m1=4;
				else if(s1[1]=='u')m1=8;
			}
			else if(s1[0]=='S')m1=9;
			else if(s1[0]=='O')m1=10;
			else if(s1[0]=='N')m1=11;
			else if(s1[0]=='D')m1=12;
			if(s2[0]=='J'){
				if(s2[1]=='a')m2=1;
				else if(s2[2]=='n')m2=6;
				else if(s2[2]=='l')m2=3;
			}
			else if(s2[0]=='F')m2=2;
			else if(s2[0]=='M'){
				if(s2[2]=='r')m2=3;
				else if(s2[2]=='y')m2=5;
			}
			else if(s2[0]=='A'){
				if(s2[1]=='p')m2=4;
				else if(s2[1]=='u')m2=8;
			}
			else if(s2[0]=='S')m2=9;
			else if(s2[0]=='O')m2=10;
			else if(s2[0]=='N')m2=11;
			else if(s2[0]=='D')m2=12;
			int ans1=0,ans2=0;
			y1--;
			y2--;
			ans1+=(y1/4-y1/100+y1/400);
			ans2+=(y2/4-y2/100+y2/400);
			y1++;
			y2++;
			if((!(y1%4)&&(y1%100))||(!(y1%400))){
				if(m1>2){
					ans1++;
				}
			}
			if((!(y2%4)&&(y2%100))||(!(y2%400))){
				if(m2>2||(m2==2&&d2==29)){
					ans2++;
				}
			}
			printf("Case #%d: %d\n",q,ans2-ans1);
		}
	}
	return 0;
}
