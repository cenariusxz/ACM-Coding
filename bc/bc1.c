#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct p{
	int a,l,t;
}a[200];

bool cmp(p a1,p a2){
	if(a1.a==a2.a&&a1.t==a2.t) return a1.l<a2.l;
	if(a1.a==a2.a) return a1.t<a2.t;
	return a1.a>a2.a;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int q,i;
		for(q=0;q<n;q++){
			int b,c;
			scanf("%d%d",&b,&c);
			a[q].l=q;a[q].a=b-c;a[q].t=c;
		}
		int j,t;
		sort(a,a+n,cmp);
		for(i=0;i<n;i++){
			printf("%d",a[i].l);
			if(i==n-1)printf("\n");
			else printf(" ");
		}
	}
	return 0;
}
