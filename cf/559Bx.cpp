#include<stdio.h>
#include<string.h>

int main(){
	int i;
	freopen("a.txt","w",stdout);
/*	for(i=1;i<=131072;i++){
		if(i%2)printf("a");
		else printf("b");
	}
	printf("\n");
	for(i=1;i<=131072/2;i++)printf("a");
	for(i=1;i<=131072/2;i++)printf("b");
	printf("\n");
*/	for(i=1;i<=131072;i++)printf("b");
	printf("\na");
	for(i=1;i<=131071;i++)printf("b");
	printf("\n");
	return 0;
}
