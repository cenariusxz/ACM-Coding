#include<stdio.h>
const int INF=0x3f3f3f3f;

int main(){
	int n,a,b,ans,x,y,i;
	while(scanf("%d%d%d",&n,&a,&b)!=EOF){
		ans=-INF;
		for(i=1;i<=n;++i){
			scanf("%d%d",&x,&y);
			if(a*x+b*y>ans)ans=a*x+b*y;
		}
		printf("%d\n",ans);
	}
	return 0;
}
