#include<stdio.h>        //差不多要这些头文件
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<math.h>
using namespace std;

const int maxn=1e5+5;    //点数、边数、询问数
const int maxm=2e5+5;
const int maxq=1e5+5;


int n,cnt;
int head[maxn],nxt[maxm],point[maxm],size;
int vis[maxn],fa[maxn],dep[maxn];
int id[maxn];
int ans[maxq];
char ss[10],t[10];
vector<int>sur[maxn];
map<string,int>M;
int res[1000][1000];

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

void init(){
	memset(ans,-1,sizeof(ans));
	memset(head,-1,sizeof(head));
	size=0;
	M.clear();
	memset(res,-1,sizeof(res));
	cnt=0;
}

void pre(){
	for(int i=1;i<=cnt;++i){
		queue<int>q;
		memset(dep,-1,sizeof(dep));
		for(int k=0;k<sur[i].size();++k){
			int j=sur[i][k];
			q.push(j);
			dep[j]=1;
		}
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int k=head[u];~k;k=nxt[k]){
				int j=point[k];
				if(dep[j]==-1){
					dep[j]=dep[u]+1;
					q.push(j);
				}
			}
		}
		for(int j=1;j<=n;++j){
			res[i][id[j]]=max(res[i][id[j]],dep[j]);
		}
	}
}

int main(){
	int q;
	while(scanf("%d%d",&n,&q)!=EOF){
		init();
		for(int i=1;i<=n;++i){
			scanf("%s",ss);
			string tmp(ss);
			if(!M[tmp]){
				M[tmp]=++cnt;
				sur[cnt].clear();
			}
			sur[cnt].push_back(i);
			id[i]=cnt;
		}
		for(int i=1;i<n;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
		}
		pre();
		for(int i=1;i<=q;++i){        //主函数中的主要部分
			scanf("%s%s",ss,t);
			string tmp1(ss),tmp2(t);
			int k1=M[tmp1],k2=M[tmp2];
			printf("%d\n",res[k1][k2]);
		}
	}
	return 0;
}
