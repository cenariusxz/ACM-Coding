#include<stdio.h>
#include<string.h>
const int INF=0x3F3F3F3F;

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		int a,b;
		int ans=INF;
		int i;
		for(i=1;i<=m;i++){
			scanf("%d%d",&a,&b);
			int tmp;
			if((n/a)*a==n)tmp=(n/a)*b;
			else tmp=((n/a)+1)*b;
			if(tmp<ans)ans=tmp;
		}
		printf("%d\n",ans);
	}
	return 0;
}
