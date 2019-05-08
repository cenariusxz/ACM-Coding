#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	if(n==13){
		printf("Yes\n2 3\n2 8\n8 10\n10 11\n8 9\n4 9\n9 13\n12 13\n1 12\n4 5\n5 7\n6 7\n");
	}
	else if(n<=14){
		printf("No\n");
	}
	else if(n==16){
		printf("Yes\n1 9\n2 3\n3 9\n10 11\n9 10\n8 9\n8 13\n12 13\n5 12\n4 5\n7 12\n6 7\n12 15\n14 15\n15 16\n");
	}
	else{
		printf("Yes\n");
		for(int i=1;i<n;++i)printf("%d %d\n",i,i+1);
	}
	return 0;
}
