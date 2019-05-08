#include<stdio.h>
#include<string.h>
#define min(a,b) (a)<(b)?a:b
#define INF 100001
int T,S,D,dist[1050],v[1050][1050],m,l[1050],r[1050];

void DIJKSTRA(int x){
    int i,j,mi,minj;
    bool visit[1050]={0};
    for(i=1;i<=m;i++)dist[i]=v[x][i];
    visit[x]=1;
    for(i=1;i<m;i++){
        mi=INF;
        for(j=1;j<=m;j++){
            if(!visit[j]&&dist[j]<mi){
                mi=dist[j];
                minj=j;
            }
        }
        if(mi==INF) return;
        visit[minj]=1;
        for(j=0;j<=m;j++){
            if(!visit[j]&&dist[j]>dist[minj]+v[minj][j]){
                dist[j]=dist[minj]+v[minj][j];
            }
        }
    }
}


int main(){
    while(scanf("%d%d%d",&T,&S,&D)!=EOF){
        int q,tm=0xFFFFFFF,i,j;
        for(i=1;i<1050;i++){
            for(j=1;j<1050;j++){
                v[i][j]=INF;
            }
        }
        m=-1;
        for(q=1;q<=T;q++){
            int a,b,va;
            scanf("%d%d%d",&a,&b,&va);
            v[a][b]=v[b][a]=min(va,v[a][b]);
            if(a>m)m=a;
            if(b>m)m=b;
        }
        for(q=1;q<=S;q++)scanf("%d",&l[q]);
        for(q=1;q<=D;q++)scanf("%d",&r[q]);
        for(i=1;i<=S;i++){
            DIJKSTRA(l[i]);
            for(j=1;j<=D;j++){
                if(dist[r[j]]<tm)tm=dist[r[j]];
            }
        }
        printf("%d\n",tm);
    }
    return 0;
}
