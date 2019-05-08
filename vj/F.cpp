#include <bits/stdc++.h>
using namespace std;
bool b[10010];

int main()
{
	int t,T,i,n,k;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		memset(b,0,sizeof(b));
		printf("Case #%d:",t);
		scanf("%d%d",&n,&k);
		for(i=1;i<=k;i++){
			printf(" %d",2*i);
			b[2*i]=1;
		}
		for(i=1;i<=n;i++)
			if(!b[i]) printf(" %d",i);
		puts("");
	}
 return 0;
}
