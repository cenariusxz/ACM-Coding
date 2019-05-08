#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

const int maxn=505;
const int maxm=2005;

int id[maxn],head[maxn];
int point[maxm],nxt[maxm],size;
int n,m,t;
int vis[maxn];
int ans[15];
int num[4];
bool ff=0;
vector<int>v;

void init(){
	memset(id,0,sizeof(id));
	memset(head,-1,sizeof(head));
	size=0;
	memset(ans,-1,sizeof(ans));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	id[b]++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
	id[a]++;
}

void Dfs(int s){
	vis[s]=1;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(!vis[j])Dfs(j);
	}
}

void dfs1(int s){
	vis[s]=1;
	t++;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(!vis[j])dfs1(j);
	}
}

void dfs2(int s){
	vis[s]=1;
	t++;
	if(id[s]==1)ff=1;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(!vis[j])dfs2(j);
	}
}

void dfs3(int s){
	vis[s]=1;
	t++;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(!vis[j])dfs3(j);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		scanf("%d%d",&n,&m);
		init();
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		printf("Case %d: ",q);
		memset(vis,0,sizeof(vis));
		Dfs(1);
		bool f=0;
		for(int i=1;i<=n;++i){
			if(!vis[i])f=1;
		}
		if(f){
			printf("0\n");
			if(q!=T)printf("\n");
			continue;
		}
		v.clear();
		int id1=0;
		for(int i=1;i<=n&&!f;++i){
			if(id[i]>3)f=1;
			if(id[i]==3)v.push_back(i);
			if(id[i]==1)id1++;
		}
		if(f){
			printf("0\n");
			if(q!=T)printf("\n");
			continue;
		}
		if(v.size()>2){
			printf("0\n");
			if(q!=T)printf("\n");
			continue;
		}
		else if(v.size()==0){
			if(id1==0){
				if(!(n%6))ans[0]=(n-6)/6;
			}
			if(id1==2){
				if(!((n-3)%2)){
					ans[1]=(n-3)/2;
				}
				if(!((n-6)%5)){
					ans[2]=(n-6)/5;
					ans[5]=(n-6)/5;
				}
				if(!((n-4)%3)){
					ans[7]=(n-4)/3;
				}
			}
		}
		else if(v.size()==1&&id1==3){
			memset(vis,0,sizeof(vis));
			int s=v[0];
			vis[s]=1;
			int cnt=0;
			for(int i=head[s];~i;i=nxt[i]){
				int j=point[i];
				if(!vis[j]){
					t=0;
					dfs1(j);
					num[++cnt]=t;
				}
			}
			if(cnt==3){
				sort(num+1,num+cnt+1);
				if(num[2]==num[3]){
					int d=num[1]-1;
					if(num[2]==2*d+2){
						ans[3]=d;
					}
				}
				else if(num[1]==num[2]){
					int d=num[1]-1;
					if(num[3]==2*d+2){
						ans[4]=d;
					}
				}
				else f=1;
			}
			else f=1;
		}
		else if(v.size()==1&&id1==1){
			memset(vis,0,sizeof(vis));
			int s=v[0];
			vis[s]=1;
			for(int i=head[s];~i;i=nxt[i]){
				int j=point[i];
				if(!vis[j]){
					t=0;
					ff=0;
					dfs2(j);
					if(ff)num[1]=t;
					else num[2]=t;
				}
			}
			int d=(num[1]-2)/2;
			if(num[1]==2*d+2&&num[2]==4*d+3){
				ans[6]=d;
				ans[9]=d;
			}
			else f=1;
		}
		else if(v.size()==2&&id1==0){
			memset(vis,0,sizeof(vis));
			int s=v[0];
			vis[s]=1;
			vis[v[1]]=1;
			int cnt=0;
			for(int i=head[s];~i;i=nxt[i]){
				int j=point[i];
				if(!vis[j]){
					t=0;
					dfs3(j);
					num[++cnt]=t;
				}
			}
			if(cnt==3){
				sort(num+1,num+cnt+1);
				int d=num[1];
				if(num[2]==3*d+2&&num[3]==3*d+2){
					ans[8]=d;
				}
				else f=1;
			}
			else f=1;
		}
		else f=1;
		if(f){
			printf("0\n");
			if(q!=T)printf("\n");
			continue;
		}
		else{
			int res=0;
			for(int i=0;i<=9;++i){
				if(ans[i]!=-1)res++;
			}
			printf("%d\n",res);
			for(int i=0;i<=9;++i){
				if(ans[i]!=-1)printf("%d %d\n",i,ans[i]);
			}
			if(q!=T)printf("\n");
		}
	}
	return 0;
}
