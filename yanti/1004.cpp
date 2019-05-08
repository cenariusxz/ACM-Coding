#include<stdio.h>
#include<string.h>

const int maxn=1e4+5;

int pre[maxn],nxt[maxn];
int vis[maxn];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(pre,-1,sizeof(pre));
		memset(nxt,-1,sizeof(nxt));
		memset(vis,0,sizeof(vis));
		int n,q;
		scanf("%d%d",&n,&q);
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(i!=1)pre[i]=i-1;
			if(i!=n)nxt[i]=i+1;
		}
		while(q--){
			char s[15];
			int a;
			scanf("%s%d",s,&a);
			if(s[0]=='m'){
				if(vis[a]==0){
					vis[a]=++cnt;
					if(pre[a]!=-1)nxt[pre[a]]=nxt[a];
					if(nxt[a]!=-1)pre[nxt[a]]=pre[a];
					pre[a]=-1;
					nxt[a]=-1;
				}
			}
			else{
				if(vis[a]!=0)printf("%d\n",vis[a]);
				else printf("%d %d\n",pre[a],nxt[a]);
			}
		}
	}
	return 0;
}
