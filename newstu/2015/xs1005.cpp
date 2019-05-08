#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int vis[100005];

int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
		if(n==1){
			printf("YES\n");
			continue;
		}
		if(k>=n){
			int B=k/(n-1);
			int A=k%(n-1);
			if(k%(n-1))B++;
			else A=n-1;
			if(B%2)k=A;
			else k=n-A-1;
		}
		if(k==0){
			printf("NO\n");
			continue;
		}
		memset(vis,0,sizeof(vis));
		vis[1%k]=1;
		int pre=1;
		while(1){
			int b=(n-pre)/k;
			int a=pre+b*k;
			if(a==n)break;
			pre=2*n-k-a;
			if(!vis[pre%k])vis[pre%k]=1;
			else break;
			b=(pre-1)/k;
			a=pre-b*k;
			pre=k-(a-1)+1;
			if(!vis[pre%k])vis[pre%k]=1;
			else break;	
		}
		bool f=1;
		for(int i=0;i<k;++i){
			if(!vis[i]){f=0;break;}
		}
		if(f)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
