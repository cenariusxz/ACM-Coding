#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

const int maxn=2e4+5;
const int maxm=4e4+5;

int n;
map<int,int>m1;
map<pair<int,int>,int>m2;
int cnt1,cnt2;
int r[maxn],s[maxn],t[maxn];
int head[maxm],point[maxm],nxt[maxm],size;
int vis[maxm];
int match[maxm];

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

void init(){
	cnt1=cnt2=0;
	m1.clear();
	m2.clear();
	size=0;
	memset(head,-1,sizeof(head));
	memset(match,-1,sizeof(match));
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;

	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

int dfs(int s){
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		if(!vis[j]){
			vis[j]=1;
			if(match[j]==-1||dfs(match[j])){
				match[j]=s;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&r[i],&s[i],&t[i]);
			int g=gcd(s[i],t[i]);
			s[i]/=g;
			t[i]/=g;
			if(!m1[r[i]])m1[r[i]]=++cnt1;
			if(!m2[make_pair(t[i],s[i])])m2[make_pair(t[i],s[i])]=++cnt2;
		}
		for(int i=1;i<=n;++i){
			add(m1[r[i]],cnt1+m2[make_pair(t[i],s[i])]);
		}

		int ans=0;
		for(int i=1;i<=cnt1;++i){
			memset(vis,0,sizeof(vis));
			if(dfs(i))ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
