#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

char s[maxn][maxn];
int vis1[200],vis2[200];
int n,m;

int check1(){
    memset(vis1,0,sizeof(vis1));
    for(int i = 1 ;  i <= n/2 ; ++ i){
        for(int j = 1 ; j <= m ; ++ j){
            vis1[ s[i][j] ] ++ ;
        }
    }
    char Max11 = 0, Max12 = 0;
    for(int i = 1 ; i <= 52 ; ++ i){
        if(vis1[i] > vis1[Max11]){Max12 = Max11; Max11 = i;}
        else if(vis1[i] > vis1[Max12])Max12 = i;
    }
    memset(vis2,0,sizeof(vis2));
    for(int i = n/2+1 ;  i <= n ; ++ i){
        for(int j = 1 ; j <= m ; ++ j){
            vis2[ s[i][j] ] ++ ;
        }
    }
    char Max21 = 0, Max22 = 0;
    for(int i = 1 ; i <= 52 ; ++ i){
        if(vis2[i] > vis2[Max21]){Max22 = Max21; Max21 = i;}
        else if(vis2[i] > vis2[Max22])Max22 = i;
    }
    if(Max11 != Max21)return n*m - vis1[Max11] - vis2[Max21];
    else return n*m - max(vis1[Max11] + vis2[Max22], vis1[Max12] + vis2[Max21]);
}

int check2(){
    memset(vis1,0,sizeof(vis1));
    for(int i = 1 ;  i <= n ; ++ i){
        for(int j = 1 ; j <= m/2 ; ++ j){
            vis1[ s[i][j] ] ++ ;
        }
    }
    char Max11 = 0, Max12 = 0;
    for(int i = 1 ; i <= 52 ; ++ i){
        if(vis1[i] > vis1[Max11]){Max12 = Max11; Max11 = i;}
        else if(vis1[i] > vis1[Max12])Max12 = i;
    }
    memset(vis2,0,sizeof(vis2));
    for(int i = 1 ;  i <= n ; ++ i){
        for(int j = m/2+1 ; j <= m ; ++ j){
            vis2[ s[i][j] ] ++ ;
        }
    }
    char Max21 = 0, Max22 = 0;
    for(int i = 1 ; i <= 52 ; ++ i){
        if(vis2[i] > vis2[Max21]){Max22 = Max21; Max21 = i;}
        else if(vis2[i] > vis2[Max22])Max22 = i;
    }
    if(Max11 != Max21)return n*m - vis1[Max11] - vis2[Max21];
    else return n*m - max(vis1[Max11] + vis2[Max22], vis1[Max12] + vis2[Max21]);
}

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 1 ; T <= 10 ; ++ T){
    freopen( (string("T1-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T1-") + ID[T] + ".out").c_str() ,"w",stdout);

    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; ++ i)scanf("%s",s[i]+1);
    for(int i = 1 ; i <= n ; ++ i){
        for(int j =1  ; j <= m ; ++ j){
            if(s[i][j] >= 'a' && s[i][j] <= 'z')s[i][j] = s[i][j] - 'a' + 1;
            else s[i][j] = s[i][j] - 'A' + 1 + 26;
        }
    }
    int ans = n*m;
    if(!(n&1))ans = min(ans, check1());
    if(!(m&1))ans = min(ans,check2());
    printf("%d\n",ans);

    }
    return 0;
}
