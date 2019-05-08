#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

char s[maxn][maxn];
int n,m;

int check1(){
    int ans = n*m;
    for(int col1 = 1 ; col1 <= 52 ; ++ col1){
        for(int col2 = 1 ; col2 <= 52 ; ++ col2){
            if(col1 == col2)continue;
            int tmp = 0;
            for(int i = 1 ; i <= n/2 ; ++ i){
                for(int j = 1 ; j <= m ; ++ j){
                    if(s[i][j] != col1)tmp ++;
                }
            }
            for(int i = n/2 + 1 ; i <= n ; ++ i){
                for(int j = 1 ; j <= m ; ++ j){
                    if(s[i][j] != col2)tmp ++;
                }
            }
            if(tmp < ans)ans = tmp;
        }
    }
    return ans;
}

int check2(){
    int ans = n*m;
    for(int col1 = 1 ; col1 <= 52 ; ++ col1){
        for(int col2 = 1 ; col2 <= 52 ; ++ col2){
            if(col1 == col2)continue;
            int tmp = 0;
            for(int i = 1 ; i <= n ; ++ i){
                for(int j = 1 ; j <= m/2 ; ++ j){
                    if(s[i][j] != col1)tmp ++;
                }
            }
            for(int i = 1 ; i <= n ; ++ i){
                for(int j = m/2+1 ; j <= m ; ++ j){
                    if(s[i][j] != col2)tmp ++;
                }
            }
            if(tmp < ans)ans = tmp;
        }
    }
    return ans;
}

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 10 ; T <= 10 ; ++ T){
    freopen( (string("T1-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T1-") + ID[T] + "-s.out").c_str() ,"w",stdout);

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
