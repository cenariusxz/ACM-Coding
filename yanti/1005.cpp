#include<stdio.h>

int main(){
	int T,n,c1,c2;
	scanf("%d",&T);
	while(T--){
		c1=0,c2=0;
		scanf("%d",&n);
		while(n--){
			int a;
			scanf("%d",&a);
			if(a==50)c1++;
			else c2++;
		}
		if(c1>=c2)printf("%d\n",c1+c2);
		else printf("%d\n",c1*2);
	}
	return 0;
}
