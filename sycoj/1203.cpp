#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long ll;
const int maxn = 2e5 + 5;
const double INF = 1e60;
const int mod = 1e9 + 7;
const double eps = 1e-8;

struct node{
    int a,b;
    bool operator < (const node x)const{
        return a < x.a;	
    }
    node(){}
    node(int _a, int _b):a(_a),b(_b){} 
}nd[maxn];

int p;
int cnt = 0;
int t;

int main(){
    scanf("%d%d%d",&p,&nd[0].a,&nd[0].b);
    int a,b;
    while(scanf("%d%d",&a,&b)){
        if(a == -1 && b == -1)break;
        nd[++cnt] = node(a,b);
    }
    sort(nd+1,nd+cnt+1);
    scanf("%d",&t);
    double Left = -INF, Right = INF;
    int n = cnt;
    for(int i = 1 ; i <= n ; ++ i){
        int delta = (nd[i-1].b - nd[i].b) / (nd[i].a - nd[i-1].a);
        for(ll j = nd[i-1].a + 1 ; j < nd[i].a ; ++ j){
            nd[++cnt] = node(j, nd[i-1].b - delta * (j - nd[i-1].a));
        }
    }
    for(ll j = nd[n].a + 1 ; j <= 200000 ; ++ j){
        nd[++cnt] = node(j, nd[n].b - t * (j - nd[n].a));	
    }
    sort(nd+1,nd+cnt+1);
    for(int i = 0 ; i <= cnt ; ++ i){
        if(nd[i].a == p){
            p = i;
            break;	
        }
    }
    for(int i = 0 ; i <= cnt ; ++ i){
        if(i == p)continue;
        if(nd[i].b <= 0)break;
        double s = ((nd[p].a-nd[0].a)*nd[p].b - (nd[i].a - nd[0].a)*nd[i].b)*1.0 / (nd[i].b - nd[p].b);
//		if(nd[i].a < 40)printf("%d %d %lf\n",nd[i].a,nd[i].b,s);
        if(nd[i].b - nd[p].b > 0)Right = min(Right, s);
        else Left = max(Left, s);
    }
    if(Left > Right)printf("NO SOLUTION\n");
    else{
        //printf("%lld %lld\n",Left,Right);
        if(Left > 0)printf("%.0lf\n",ceil(Left));
        else if(Right < 0)printf("%.0lf\n",floor(Right));
        else printf("0\n"); 
    }
    return 0;
}
