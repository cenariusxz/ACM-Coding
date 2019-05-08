#pragma comment(linker, "/STACK:102400000,102400000")
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int head[10005],nxt[200005],point[200005],size=0;
int num[2];
int c[10005],dp[10005];

int max(int a,int b){
	return a>b?a:b;
}

int min(int a,int b){
	return a<b?a:b;
}

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

void dfs(int a,int x){
	c[a]=x;
	num[x]++;
	for(int i=head[a];~i;i=nxt[i]){
		int b=point[i];
		if(c[b]==-1)dfs(b,!x);
	}
}

int main(){
	int T=read();
	while(T--){
		int n=read();
		int m=read();
		memset(head,-1,sizeof(head));
		size=0;
		memset(c,-1,sizeof(c));
		int i,j;
		if(m==0){
			int a=n/2;
			printf("%d\n",a*(n-a));
			continue;
		}
		for(i=1;i<=m;i++){
			int a=read();
			int b=read();
			add(a,b);
		}
		int cnt=0,ans=0,maxx=0;
		memset(dp,-1,sizeof(dp));
		dp[0]=0;
		int k=0;
		for(i=1;i<=n;++i){
			if(c[i]==-1){
				num[0]=num[1]=0;
				dfs(i,1);
				if(num[0]+num[1]==1){
					k++;
					continue;
				}
				for(j=min(n/2,maxx+max(num[0],num[1]));j>=0;--j){
					if(j-num[0]>=0&&dp[j-num[0]]==cnt){
						dp[j]=cnt+1;
						maxx=max(maxx,j);
						ans=max(ans,j);
					}
					if(j-num[1]>=0&&dp[j-num[1]]==cnt){
						dp[j]=cnt+1;
						maxx=max(maxx,j);
						ans=max(ans,j);
					}
				}
				cnt++;
			}
		}
		ans=min(ans+k,n/2);
		int x1=n-ans;
		printf("%d\n",x1*ans-m);
	}
	return 0;
}
