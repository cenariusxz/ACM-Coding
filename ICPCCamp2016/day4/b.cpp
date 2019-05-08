#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
typedef long long ll;

const int maxn=35;
const int maxm=250<<1;

int ma[maxn][maxn];
int head[maxn],nxt[maxm],point[maxm],size;
int id[maxn]i,c;
int num1[maxn],num2[maxn];
int vis[maxn];
int col[maxn];
vector<int>v[2];
vector<int>s[30];
int cou[30];

void init(){
	size=0;
	memset(head,-1,sizeof(head));
	memset(col,-1,sizeof(col));
	memset(id,0,sizeof(id));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	id[a]++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
	id[b]++;
}

void dfs1(int s,int c){
	col[s]=c;
	v[c].push_back(s);
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(col[j]==-1)dfs1(j,!c);
	}
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	init();
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	ll ans=1;
	for(int s=1;s<=n;++s){
		if(col[s]==-1){
			v[0].clear();
			v[1].clear();
			dfs1(s,1);
			if(!v[0].size)continue;
			if(v[0].size<v[1].size)c=0;
			else c=1;
			//c 是少的
			int cnt=0;
			for(int i=0;i<v[c].size();++i){
				num1[v[c][i]]=++cnt;
				num2[cnt]=v[c][i];
			}
			for(int i=0;i<v[!c].size();++i){
				num1[v[!c][i]]=++cnt;
				num2[cnt]=v[!c][i];
			}
			int d1=v[c].size(),d2=v[!c].size();
			for(int i=0;i<1<<d1;++i){
				memset(vis,0,sizeof(vis));
				for(int j=1;j<=d1;++j){
					if(i&(1<<(j-1))){
						vis[j]=1;
					}
					else if(id[num2[j]]==1){
						int k=point[head[num2[j]]];
						vis[k]=1;
					}
				}
				for(int j=d1+1;j<=d1+d2;++j){
					if(vis[j])continue;
					int num=num2[j];
					bool f=1;
					for(int k=head[num];~k;k=nxt[k]){
						int p=point[k];
						if(vis[p]){
							f=0;
							break;
						}
					}
					if(f)vis[j]=1;
				}
				for(int j=1;j<=d1;++j){
					if(!vis[j]){
						int num=num2[j];
						bool f=1;
						for(int k=head[num];~k;k=nxt[k]){
							int p=point[k];

						}
					}
				}
			}
		}
	}
	return 0;
}
