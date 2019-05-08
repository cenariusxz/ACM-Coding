#include<stdio.h>
#include<string.h>

int a[10005];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(a,0,sizeof(a));
		int i,maxx=0,p=0;
		for(i=1;i<=n;i++){
			int b;
			scanf("%d",&b);
			a[b]++;
			if(a[b]>maxx){
				maxx=a[b];
				p=b;
			}
		}
		if(maxx>n-maxx)printf("%d\n",p);
		else printf("-1\n");
	}
	return 0;
}
