#include<stdio.h>
#include<string.h>

int main(){
	int a[100];
	memset(a,0xc0,sizeof(a));
	printf("%d\n",a[0]*2);
	return 0;
}
