#include<stdio.h>
#include<string.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
const int MAXM=50000;

int num[MAXM+5],ma[MAXM+5],mi[MAXM+5],a1,a2;

int lowbit(int x){return x&(-x);}

void init(int n){
	for(int i=1;i<=n;i++){
		ma[i]=mi[i]=num[i];
		for(int j=1;j<lowbit(i);j<<=1){
			ma[i]=max(ma[i],ma[i-j]);
			mi[i]=min(mi[i],mi[i-j]);
		}
	}
}

void query(int l,int r){
	a1=a2=num[r];
	while(1){
		a1=max(a1,num[r]);
		a2=min(a2,num[r]);
		if(l==r)break;
		for(r-=1;r-l>=lowbit(r);r-=lowbit(r)){
			a1=max(a1,ma[r]);
			a2=min(a2,mi[r]);
		}
	}
}

int main(){
	int n,q;
	while(scanf("%d%d",&n,&q)!=EOF){
		int i;
		for(i=1;i<=n;i++)scanf("%d",&num[i]);
		init(n);
		int a,b;
		for(i=1;i<=q;i++){
			scanf("%d%d",&a,&b);
			a1=-1,a2=0x3f3f3f3f;
			query(a,b);
			printf("%d\n",a1-a2);
		}
	}
	return 0;
}
