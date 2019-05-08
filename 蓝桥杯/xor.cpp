#include<stdio.h>
#include<string.h>

const int maxn=1e5+5;

int x[maxn];

int main(){
	int T,n,a;
	scanf("%d",&T);
	while(T--){
		memset(x,-1,sizeof(x));
		x[0]=0;
		int res=0,ans=0x3f3f3f3f,l,r;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&a);
			res^=a;
			if(~x[res]){
				if(i-x[res]<ans){
					ans=i-x[res];
					l=x[res]+1;
					r=i;
				}
			}
			x[res]=i;
		}
		if(ans==0x3f3f3f3f)printf("-1\n");
		else printf("%d %d\n",l,r);
	}
	return 0;
}
