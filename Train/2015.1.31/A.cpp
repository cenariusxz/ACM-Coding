#include<stdio.h>
int fa[1001];
void init (int n){
    int i;
    for (i=1;i<=n;i++) fa[i]=i;
    return;
}

int Find(int i){
    if(fa[i]==i){
        return i;
    }
    fa[i]=Find(fa[i]);
    return fa[i];
}

void Union(int x,int y){
    int fx=Find(x),fy=Find(y);
    if(fx!=fy) fa[fx]=fy;
}

int main(){
    int T;
    while(scanf("%d",&T)!=EOF){
        int j;
        for(j=1;j<=T;j++){
            int N,M;
            scanf("%d%d",&N,&M);
            init(N);
            int i,a,b,count=0;
            for (i=1;i<=M;i++){
                scanf("%d%d",&a,&b);
                Union(a,b);
            }
            for(i=1;i<=N;i++){
                if(fa[i]==i) count++;
            }
            printf("%d\n",count);
        }
    }
    return 0;
}
