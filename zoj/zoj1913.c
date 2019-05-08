#include<stdio.h>

int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF&&(a!=0||b!=0)){
		int c=1,t;
		if(a>b){
			t=a;
			a=b;
			b=t;
		}
		bool f=0;
		while(a!=0){
			if(c==1&&a==b){
				f=1;
				break;
			}
			if(b-a>=a){
				if(c%2)f=1;
				else f=0;
				break;
			}
			b-=a;
			if(a>b){
				t=a;
				a=b;
				b=t;
			}
			c++;
		}
		if(f) printf("Stan wins\n");
		else printf("Ollie wins\n");
	}
	return 0;
}
