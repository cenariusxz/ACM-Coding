#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;
int cnt;
int a[50005];
int fa[50005],last[50005],dp[50005];

int find(int x){
	if(fa[x]==-1)return x;
	return fa[x]=find(fa[x]);
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,b=1;
		memset(fa,-1,sizeof(fa));
		a[cnt=0]=0;
		map<int,int>m;
		m.clear();
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]!=a[cnt]){
				a[++cnt]=a[i];
				if(!m[a[i]])m[a[i]]=b++;
			}
		}
		memset(last,-1,sizeof(last));
		for(i=1;i<=cnt;i++)a[i]=m[a[i]];
	/*	for(i=1;i<=cnt;i++)printf("%d ",a[i]);
		printf("\n");*/
		dp[0]=0;
		for(i=1;i<=cnt;i++){
			dp[i]=i;
			if(last[a[i]]!=-1){
				int x=find(last[a[i]]),y=find(last[a[i]]-1);
				if(x!=y)fa[x]=y;
			}
			printf("%d:\n",i);
			for(int k=1;k<=cnt;k++)printf("%d ",find(last[a[k]]));
			printf("\n");
			last[a[i]]=i;
			int num=0;
			for(int j=i;j>0;j=find(j-1)){
				num++;
				if(num*num>=dp[i])break;
				int nxt=find(j-1);
				dp[i]=min(dp[i],dp[nxt]+num*num);
			}
		}
		printf("%d\n",dp[cnt]);
	}
	return 0;
}
