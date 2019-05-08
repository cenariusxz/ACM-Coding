#include<stdio.h>
#include<string.h>

char s[2];
int wh,wd,bh,bd;
long long wa,ba;

int main(){
	while(scanf("%s",s)!=EOF){
		scanf("%d%I64d%d%d%I64d%d",&wh,&wa,&wd,&bh,&ba,&bd);
		long long num1=wa-bd,num2=ba-wd;
		bool f=0;
		if(num1<=0)f=0;
		else if(num2<=0)f=1;
		else{
			int ans1=bh/num1;
			if(bh%num1)ans1++;
			int ans2=wh/num2;
			if(wh%num2)ans2++;
			if(s[0]=='W'){
				if(ans2>=ans1)f=1;
				else f=0;
			}
			else{
				if(ans2>ans1)f=1;
				else f=0;
			}
		}
		if(f)printf("Warrior wins\n");
		else printf("Warrior loses\n");
	}
	return 0;
}
