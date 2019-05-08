#include<stdio.h>
int fa[1001];
void init(int n){
    int i;
    for(i=1;i<=n;i++) fa[i]=i;
}

int Find(int x){
    if (fa[x]==x) return x;
    else fa[x]=Find(fa[x]);
    return fa[x];
}

void Union(int x,int y){
    int fx=Find(x),fy=Find(y);
    if(fx!=fy) fa[fx]=fy;
}

int main(){
    int T;
    while(scanf("%d",&T)!=EOF){
        int i;
        for(i=1;i<=T;i++){
            int N,M,count=0;
            scanf("%d%d",&N,&M);
            init(N);
            int j;
            for(j=1;j<=M;j++){
                int a,b;
                scanf("%d%d",&a,&b);
                Union(a,b);
            }
            for(j=1;j<=N;j++){
                if (Find(j)==j) count++;
            }
            printf("%d\n",count);
        }
    }
}
