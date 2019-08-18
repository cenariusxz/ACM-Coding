#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 30011;
const int inf = (1<<30);
int n;
int total,ecnt;
int U,VV;
int a[MAXN];
int id[MAXN],pre[MAXN];
int top[MAXN],siz[MAXN],zhongerzi[MAXN],father[MAXN],deep[MAXN];
int next[MAXN*2],to[MAXN*2],first[MAXN];
char ch[8];

struct node{
    int l,r;
    int _max;int _sum;
}jump[MAXN*4];

void link(int x,int y){ next[++ecnt]=first[x]; first[x]=ecnt; to[ecnt]=y; }

void build(int root,int l,int r){
    jump[root].l=l;jump[root].r=r;
    if(jump[root].l==jump[root].r) {
        jump[root]._sum=jump[root]._max=a[ pre[l] ];
        return ;
    }
    int lc=root*2,rc=root*2+1;
    int mid=l+(r-l)/2;
    build(lc,l,mid); build(rc,mid+1,r);
    jump[root]._sum=jump[lc]._sum+jump[rc]._sum;
    jump[root]._max=max(jump[lc]._max,jump[rc]._max);
}

void dfs1(int u,int fa){
    siz[u]=1;
    for(int i=first[u];i;i=next[i]) {
        int v=to[i];
        if(v!=fa) {
            father[v]=u;
            deep[v]=deep[u]+1;
            dfs1(v,u);
            siz[u]+=siz[v];
            if(siz[v]>siz[ zhongerzi[u] ]) zhongerzi[u]=v;
        }
    }
}

void dfs2(int u,int fa){
    id[u]=++total; pre[total]=u;
    if(zhongerzi[u]) top[zhongerzi[u]]=top[u],dfs2(zhongerzi[u],u);
    for(int i=first[u];i;i=next[i]) {
        int v=to[i];
        if(v==fa || v==zhongerzi[u]) continue;
        top[v]=v;
        dfs2(v,u);
    }
}

int query_sum(int root,int x,int y){
    if(jump[root].l>=x && jump[root].r<=y) return jump[root]._sum;
    int da=0;
    int mid=jump[root].l+(jump[root].r-jump[root].l)/2;
    int lc=root*2,rc=root*2+1;
    if(x<=mid) da+=query_sum(lc,x,y);
    if(y>mid) da+=query_sum(rc,x,y);
    return da;
}


int query_max(int root,int x,int y){
    if(jump[root].l>=x && jump[root].r<=y) return jump[root]._max;
    int da=-inf;
    int mid=jump[root].l+(jump[root].r-jump[root].l)/2;
    int lc=root*2,rc=root*2+1;
    if(x<=mid) da=max(da,query_max(lc,x,y));
    if(y>mid) da=max(da,query_max(rc,x,y));
    return da;
}

int find_max(int x,int y){
    int f1=top[x],f2=top[y];
    int daan=-inf;
    while(f1!=f2){
            if(deep[f1]<deep[f2]) swap(f1,f2),swap(x,y);
            daan=max(daan,query_max(1,id[f1],id[x]));
            x=father[f1];
            f1=top[x];
    }
    if(deep[x]<deep[y]) swap(x,y);
    daan=max(daan,query_max(1,id[y],id[x]));
    return daan;
}

int find_sum(int x,int y){
    int f1=top[x],f2=top[y];
    int daan=0;
    while(f1!=f2){
          if(deep[f1]<deep[f2]) swap(f1,f2),swap(x,y);
          daan+=query_sum(1,id[f1],id[x]);
          x=father[f1]; f1=top[x];
    }
    if(deep[x]<deep[y]) swap(x,y);
    daan+=query_sum(1,id[y],id[x]);
    return daan;
}

void update(int root,int o,int add){
    if(jump[root].l==jump[root].r){
        jump[root]._sum+=add;
        jump[root]._max+=add;return ;
    }
    int lc=root*2,rc=root*2+1;
    int mid=jump[root].l+(jump[root].r-jump[root].l)/2;
    if(o<=mid) update(lc,o,add); else update(rc,o,add);
    jump[root]._sum=jump[lc]._sum+jump[rc]._sum;
    jump[root]._max=max(jump[lc]._max,jump[rc]._max);
}

int main(){
  scanf("%d",&n);
  int x,y;
  for(int i=1;i<n;i++){
  	scanf("%d%d",&x,&y);
      next[++ecnt]=first[x]; first[x]=ecnt; to[ecnt]=y; 
      next[++ecnt]=first[y]; first[y]=ecnt; to[ecnt]=x; 
   }

  deep[1]=1;  dfs1(1,0);
  top[1]=1;  dfs2(1,0);

  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  build(1,1,n);
  int Q;
  scanf("%d",&Q);

  for(int i=1;i<=Q;i++){
      scanf("%s",ch);
      if(ch[1]=='M'){
      	scanf("%d%d",&x,&y);
          printf("%d\n",find_max(x,y));
      }
      else if(ch[1]=='S'){
          scanf("%d%d",&x,&y);
          printf("%d\n",find_sum(x,y));
      }
      else{
          scanf("%d%d",&U,&VV);
          update(1,id[U],VV-a[U]);a[U]=VV;
      }
   }
  return 0;
}
