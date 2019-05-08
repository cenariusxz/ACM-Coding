#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int v[20001];

void init(){
	int i;
	for(i=1;i<=18300;i++)v[i]=3*i*(i-1)+1;
}

int main(){
	int T;
	init();
	for(int i=21;i<=50;i++)printf("%d %d\n",i,v[i]);
	scanf("%d",&T);
	while(T--){
		int n;
			
	}
	return 0;
}
