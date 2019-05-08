#include<stdio.h>
#include<string.h>
typedef long long ll;

ll ans[105];

int main(){
	int n,k;
	int count=0;
	while(scanf("%d%d",&n,&k)!=EOF){
		memset(ans,0,sizeof(ans));
		count++;
		if(n>100||n<1)printf("%d:n:%d\n",count,n);
		if(k>10||k<1)printf("%d:k:%d\n",count,k);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=k;++j){
				int a,b;
				scanf("%d:%d",&a,&b);
				if(a<0||a>4||b<0||b>59)printf("%d:%d:%d\n",count,a,b);
				ans[i]+=a*60+b;
			}
			for(int j=1;j<=k;++j){
				int c;
				scanf("%d",&c);
				if(c<1||c>200)printf("%d:%d\n",count,c);
				ans[i]+=(c-1)*20;
			}
		}
		for(int i=1;i<=n;++i)if(ans[i]>2147483647ll)printf("%dWA\n",count);
	}
	printf("%d\n",count);
	return 0;
}
