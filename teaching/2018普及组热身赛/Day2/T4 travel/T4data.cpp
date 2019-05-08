#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

int M[maxn][maxn];
int a[maxn];

int main(){
    freopen("T4-10.in","w",stdout);
    srand(time(NULL));
    int n = 1000, m = 0;
/*
    //1 3
    for(int i = 2 ; i <= n ; ++ i){
        for(int j = i + 1 ; j <= n ; ++ j){
            M[i][j]= 1;
            m ++;
        }
    }*/
/*
    //2 4 7
    for(int i = 1 ; i < n - 1 ; ++ i)a[i] = i + 1;
    random_shuffle(a+1,a+n-1);
    for(int i = 1 ; i < n - 2 ; ++ i){
        M[ a[i] ][ a[i+1] ] = 1;
        m ++;
    }
    for(int i = 1 ; i <= n ; ++ i){
        if(i == a[1])continue;
        if(!M[ a[1] ][i]){
            M[ a[1] ][i] = 1;
            m ++;
        }
    }*/

    //5 8 9 10
    for(int i = 1 ; i <= n ; ++ i){
        for(int j = i + 1 ; j <= n ; ++ j){
            M[i][j]= rand()%5;
            if(M[i][j]==1)m ++;
            else M[i][j] = 0;
        }
    }

    printf("%d %d\n",n,m);
    for(int i = 1 ; i <= n ; ++ i){
        for(int j = 1 ; j <= n ; ++ j){
            if(M[i][j])printf("%d %d\n",i,j);
        }
    }
    return 0;
}
