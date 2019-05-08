#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("T2-6.in","w",stdout);
    srand(time(NULL));
    int n = 1000;
    int k = 10;
    int m = 10;
    printf("%d %d %d\n",n,k,m);
    for(int i = 1 ; i <= n ; ++ i){
        for(int j = 1 ; j <= m ; ++ j){
            printf("%d ",1000000000 - rand()%100);
        }
        printf("\n");
    }
    return 0;
}
