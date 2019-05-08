#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int num[100004];

int main(){
	int b,s;
	int cnt=0;
	while(scanf("%d%d",&b,&s)!=EOF&&(b||s)){
		for(int i=1;i<=b;++i)scanf("%d",&num[i]);
		sort(num+1,num+b+1);
		int a;
		for(int i=1;i<=s;++i)scanf("%d",&a);
		printf("Case %d: ",++cnt);
		if(b<=s)printf("0\n");
		else{
			printf("%d %d\n",b-s,num[1]);
		}
	}
	return 0;
}
