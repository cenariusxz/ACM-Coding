#include<bits/stdc++.h>
using namespace std;
const int maxm=15;    //最大点数
const int INF=0x3f3f3f3f;

struct edge{        //边：起点、终点、容量、流量、单位费用
    int from,to,c,f,cost;
    edge(int a,int b,int m,int n,int p):from(a),to(b),c(m),f(n),cost(p){}
};

int aabs(int a){
    return a>=0?a:-a;
}

int m,s,t;
vector<edge>e;
vector<int>g[maxm];
int dis[maxm],a[maxm],p[maxm];
bool vis[maxm];

void init(){        //初始化函数
    for(int i=0;i<=14;i++)g[i].clear();
    e.clear();
}

void add(int a,int b,int c,int v){    //加边函数
	//printf("%d -> %d: %d %d\n", a, b, c, v);
    e.push_back(edge(a,b,c,0,v));
    e.push_back(edge(b,a,0,0,-v));
    m=e.size();
    g[a].push_back(m-2);
    g[b].push_back(m-1);
}

bool spfa(int& flow,int& cost){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    queue<int>q;
    q.push(s);
    vis[s]=1;
    dis[s]=0;
    p[s]=0;
    a[s]=INF;
    while(!q.empty()){
        int u=q.front();q.pop();
        vis[u]=0;
        for(int i=0;i<g[u].size();i++){
            edge tmp=e[g[u][i]];
            if(dis[tmp.to]>dis[u]+tmp.cost&&tmp.c>tmp.f){
                dis[tmp.to]=dis[u]+tmp.cost;
                p[tmp.to]=g[u][i];
                a[tmp.to]=min(a[u],tmp.c-tmp.f);
                if(!vis[tmp.to]){
                    q.push(tmp.to);
                    vis[tmp.to]=1;
                }
            }
        }
    }
    if(dis[t]==INF)return 0;
    flow+=a[t];
    cost+=dis[t]*a[t];
    int u=t;
    while(u!=s){
        e[p[u]].f+=a[t];
        e[p[u]^1].f-=a[t];
        u=e[p[u]].from;
    }
    return 1;
}

int MF(int S,int T){
    s=S; t=T;
    int flow=0,cost=0;
    while(spfa(flow,cost));
    return cost;
}

map<string, int>num;
string ss[15] = {"", "", "", "", "012", "021", "102", "120", "201", "210"};

void solve(){
	//printf("aaaa\n");
	int n, a, b, c;
	scanf("%d%d%d%d", &n, &a, &b, &c);
	init();
	num.clear();
	add(0, 1, a, 0);
	add(0, 2, b, 0);
	add(0, 3, c, 0);
	for(int i = 4 ; i <= 9 ; ++ i){
		string s = ss[i];
		add(s[0] - '0' + 1, i, INF, -3);
		add(s[1] - '0' + 1, i, INF, -2);
		add(s[2] - '0' + 1, i, INF, -1);
	}
	char s[5];
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%s", s);
		num[string(s)]++;

		// add(3 + i, 3 + n + 1, 1, 0);
	}
	for(int i = 4 ; i <= 9 ; ++ i){
		add(i, 10, num[ss[i]], 0);
	}
	printf("%d\n", -MF(0, 10));
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--)solve();
	return 0;
}
