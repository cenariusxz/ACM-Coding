#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxm=1005;

int head[maxm],point[maxm<<1],nxt[maxm<<1],size;
bool vis[maxm];
int v[maxm<<1];
int e[maxm];

void add(int a,int b){
	point[size]=b;
	v[size]=0;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	v[size]=0;
	nxt[size]=head[b];
	head[b]=size++;
	e[a]++;
	e[b]++;
}

void dfs(int s){
	vis[s]=1;
	for(int i=head[s];~i;i=nxt[i]){
		if(v[i])continue;
		if(!vis[point[i]])dfs(point[i]);
	}
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int c=0;
		memset(e,0,sizeof(e));
		memset(head,-1,sizeof(head));
		size=0;
		for(int i=1;i<=n;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			if(a==b)c++;
			else add(a,b);
		}
		if(n==1){printf("YES\n");continue;}
		if(c){
			if(c==1){
				bool f=1;
				int cnt1=0,p1;
				for(int i=1;i<=n&&f;++i){
					if(e[i]==1){
						cnt1++;
						p1=i;
						if(cnt1>2)f=0;
					}
					else if(e[i]>2||e[i]==0)f=0;
				}
				if(f){
					memset(vis,0,sizeof(vis));
					dfs(p1);
					for(int j=1;j<=n;++j){
						if(!vis[j]){f=0;break;}
					}
				}
				if(f)printf("YES\n");
				else printf("NO\n");
			}
			else printf("NO\n");
			continue;
		}
		bool f=1;
		int cnt1=0,p1,cnt3=0,p31,p32;
		for(int i=1;i<=n&&f;++i){
			if(e[i]==1){
				cnt1++;
				p1=i;
				if(cnt1>2)f=0;
			}
			else if(e[i]==3){
				cnt3++;
				if(cnt3==1)p31=i;
				else if(cnt3==2)p32=i;
				else f=0;
			}
			else if(e[i]>3||e[i]==0)f=0;
		}
		if(f==0)printf("NO\n");
		else{
			if(cnt1==0&&cnt3==0){
				memset(vis,0,sizeof(vis));
				dfs(1);
				for(int j=1;j<=n;++j){
					if(!vis[j]){f=0;break;}
				}
			}
			else if(cnt3==1){
				for(int i=head[p31];~i;i=nxt[i]){
					v[i]=v[i^1]=1;
					memset(vis,0,sizeof(vis));
					dfs(p1);
					bool ff=0;
					f=1;
					for(int j=1;j<=n;++j){
						if(!vis[j]){f=0;break;}
					}
					if(f==1)break;
					v[i]=v[i^1]=0;
				}
			}
			else if(cnt3==2){
				memset(vis,0,sizeof(vis));
				int i;
				for(i=head[p31];~i;i=nxt[i]){
					if(point[i]==p32){
						v[i]=v[i^1]=1;
						break;
					}
				}
				if(i==-1)f=0;
				else{
					dfs(p1);
					for(int j=1;j<=n;++j){
						if(!vis[j]){f=0;break;}
					}
				}
			}
			if(f)printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
