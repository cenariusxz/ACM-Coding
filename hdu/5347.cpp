#include<stdio.h>

int a[100]={0,20,21,2,4,3,5,7,6,8,9,1,3,2,4,6,5,7,8};

int main(){
	a[85]=1;
	a[86]=2;
	a[53]=2;
	a[54]=3;
	a[35]=3;
	a[36]=4;
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF){
		if(a[n]>a[m])printf("FIRST BIGGER\n");
		else printf("SECOND BIGGER\n");
	}
	return 0;
}
