#pragma comment(linker, "/STACK:102400000,102400000")
#include<stdio.h>
#include<string.h>
typedef long long ll;
const int MAXN=100010;
const int MAXM=300010;
const int MAXL=20;

int T,N,M;
int first[MAXN],ecnt;
int vis[MAXN];
int ans1,ans2;
short fa[MAXL][MAXN],dep[MAXN];

struct edge{
    int v,nxt;
}e[MAXM<<1];

inline void add(int a,int b){
    e[ecnt].nxt=first[a];
    e[ecnt].v=b;
    first[a]=ecnt++;
}

int Lca(int a,int b){
    if(dep[a]>dep[b]){
		int t=a;
		a=b;
		b=t;
	}
    for(int k=0;k<MAXL;k++){
        if((dep[b]-dep[a])>>k&1)
            b=fa[k][b];
    }
    if(a==b)return a;
    for(int k=MAXL-1;k>=0;k--){
        if(fa[k][a]!=fa[k][b]){
            a=fa[k][a];
            b=fa[k][b];
        }
    }
    return fa[0][a];
}

void Check(int a,int b){
    int lca=Lca(a,b);
    int len=dep[a]-2*dep[lca]+dep[b]+1;
    if(len%2)ans1++;
    else ans2++;
}

void Dfs1(int p,int pre,int d){
    vis[p]=1;
    fa[0][p]=pre;
    dep[p]=d;
    for(int i=first[p];~i;i=e[i].nxt){
        int v=e[i].v;
        if(v==pre||vis[v])continue;
        Dfs1(v,p,d+1);
    }
}

void Init(){
    memset(fa,-1,sizeof(fa));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=N;i++){
        if(!vis[i])Dfs1(i,0,1);
    }
    for(int k=0;k+1<MAXL;k++){
        for(int i=1;i<=N;i++){
            if(fa[k][i]<0)fa[k+1][i]=-1;
            else fa[k+1][i]=fa[k][fa[k][i]];
        }
    }
}


void Dfs(int p,int pre){
    if(ans1&&ans2)return;
    int tans=ans1;
    vis[p]=1;
    for(int i=first[p];~i;i=e[i].nxt){
        int v=e[i].v;
        if(v==pre)continue;
        if(vis[v])Check(p,v);
        else Dfs(v,p);
    }
    if(ans1-tans>=4){
        ans2++;
    }
}

int main(){
    int a,b;
    scanf("%d",&T);
    for(int q=1;q<=T;q++){
        scanf("%d%d",&N,&M);
        memset(first,-1,sizeof(first));
        ecnt=0;
        for(int i=1;i<=M;i++){
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        Init();
        memset(vis,0,sizeof(vis));
        ans1=ans2=0;
        for(int i=1;i<=N;i++){
            if(!vis[i])Dfs(i,0);
        }
        if(ans1)printf("YES\n");
        else printf("NO\n");
        if(ans2)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
