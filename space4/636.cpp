#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

int head[maxn],point[maxm<<1],nxt[maxm<<1],val[maxm<<1],size;
int n, m, w, dis[maxn],vis[maxn],t[maxn];

void init(){
    memset(head,-1,sizeof(head));
    size=0;
}

void add(int a,int b,int v){
    point[size]=b;
    val[size]=v;
    nxt[size]=head[a];
    head[a]=size++;
}

bool spfa(int s){
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    memset(t, 0, sizeof(t));
    queue<int>q;
    vis[s]=1;
    dis[s]=0;
    t[s] ++;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];~i;i=nxt[i]){
            int j=point[i];
            if(dis[j]>dis[u]+val[i]){
                dis[j]=dis[u]+val[i];
                if(!vis[j]){
                	t[j] ++;
                	if(t[j] > n)return 1;
                    q.push(j);
                    vis[j]=1;
                }
            }
        }
    }
    return 0;
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		init();
		scanf("%d%d%d", &n, &m, &w);
		for(int i = 1 ; i <= m ; ++ i){
			int a, b, v;
			scanf("%d%d%d", &a, &b, &v);
			add(a, b, v);
			add(b, a, v);
		}
		for(int i = 1 ; i <= w ; ++ i){
			int a, b, v;
			scanf("%d%d%d", &a, &b, &v);
			add(a, b, -v);
		}
		if(spfa(1))printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

