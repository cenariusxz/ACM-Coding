#include<stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		printf("Case %d: ",q);
		if(a<=20&&b<=20&&c<=20)printf("good\n");
		else printf("bad\n");
	}
}
