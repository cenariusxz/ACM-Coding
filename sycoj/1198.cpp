#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int INF = 0x3f3f3f3f;

struct node{
    int dis1,dis2;
    bool operator < (const node a)const{
        return dis1 > a.dis1;
    }
}nd[maxn];

int main(){
    int x1,y1,x2,y2;
    while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)!=EOF){
        int n;
        scanf("%d",&n);
        for(int i = 1 ; i <= n ; ++ i){
            int x,y;
            scanf("%d%d",&x,&y);
            nd[i].dis1 = (x-x1)*(x-x1) + (y-y1)*(y-y1);
            nd[i].dis2 = (x-x2)*(x-x2) + (y-y2)*(y-y2);
        }
        sort(nd+1,nd+n+1);
        int ans = INF;
        nd[0].dis2 = 0;nd[n+1].dis1 = 0;
        int tmp = 0;
        for(int i = 0 ; i <= n ; ++ i){
            tmp = max(tmp,nd[i].dis2);
            ans = min(ans,tmp+nd[i+1].dis1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
