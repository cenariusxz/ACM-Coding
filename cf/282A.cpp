#include<stdio.h>
#include<string.h>

char a[10];

int main(){
	int n;
	scanf("%d",&n);
	int i,x=0;
	for(i=1;i<=n;i++){
		scanf("%s",a);
		if(a[1]=='+')x++;
		else if(a[1]=='-')x--;
	}
	printf("%d\n",x);
	return 0;
}
