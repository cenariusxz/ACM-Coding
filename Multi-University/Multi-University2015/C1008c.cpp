#include<stdio.h>
#include<string.h>

void build(int o,int l,int r){
	printf("%d %d %d\n",o,l,r);
	if(l==r)return;
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		build(1,0,n);
	}
	return 0;
}
