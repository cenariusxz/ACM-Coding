#include<stdio.h>
#include<string.h>

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int sum=a+b+c;
	if(sum%2)printf("Impossible\n");
	else{
		int a1=sum/2-c;
		int a2=sum/2-a;
		int a3=sum/2-b;
		if(a1+a2==0||a2+a3==0||a3+a1==0||a1<0||a2<0||a3<0){
			printf("Impossible\n");
		}
		else printf("%d %d %d\n",a1,a2,a3);
	}
	return 0;
}
