#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=2e5+5;
const int maxm=5555*2;

int n,m;
int s;
int head[maxn],point[maxm],nxt[maxn],size;
int ans[maxn];
int vis[maxn];
int v[2][maxn];
int cnt[2];
struct seg{
	int a,b;
	bool operator < (const seg s)const{
		if(a==s.a)return b<s.b;
		return a<s.a;
	}
}ss[maxm];

void init(){
	memset(head,-1,sizeof(head));
	memset(ans,-1,sizeof(ans));
	memset(vis,0,sizeof(vis));
	size=0;
	cnt[0]=cnt[1]=cnt[2]=0;
}

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
}


void solve(){
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		vis[j]++;
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			if(i!=s){
				ans[i]=1;
				v[0][++cnt[0]]=i;
			}
		}
		else v[1][++cnt[1]]=i;
	}
	int res=1;
	int pre=0,now=1;
	while(1){
		++res;
		if(cnt[pre]==0||cnt[now]==0)break;
		for(int i=1;i<=cnt[now];++i)vis[v[now][i]]=0;
		for(int i=1;i<=cnt[pre];++i){
			int p=v[pre][i];
			for(int k=head[p];~k;k=nxt[k]){
				int j=point[k];
				vis[j]++;
			}
		}
		int num=cnt[pre];
		cnt[pre]=0;
		int sz=cnt[now];
		cnt[now]=0;
		for(int i=1;i<=sz;++i){
			int p=v[now][i];
			if(vis[p]==num)v[now][++cnt[now]]=p;
			else{
				v[pre][++cnt[pre]]=p;
				ans[p]=res;
			}
		}
	}
	int c=0;
	for(int i=1;i<=n;++i)if(i!=s){
		printf("%d",ans[i]);
		++c;
		if(c==n-1)printf("\n");
		else printf(" ");
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=m;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			if(a>b)swap(a,b);
			ss[i].a=a;ss[i].b=b;
		}
		sort(ss+1,ss+m+1);
		int cnt=1;
		add(ss[1].a,ss[1].b);
		add(ss[1].b,ss[1].a);
		for(int i=2;i<=m;++i){
			if(ss[i].a!=ss[i-1].a||ss[i].b!=ss[i-1].b){
				add(ss[i].a,ss[i].b);
				add(ss[i].b,ss[i].a);
			}
		}
		
		scanf("%d",&s);
		solve();
	}
	return 0;
}
