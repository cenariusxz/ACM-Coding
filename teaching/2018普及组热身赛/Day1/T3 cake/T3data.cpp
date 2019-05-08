#include <bits/stdc++.h>
using namespace std;
int L = 800000000;
int M = 1000000000;
int Left = M - L;

int main(){
    freopen("T3-10.in","w",stdout);
    srand(time(NULL));
    int n = rand()%5 + 4996;
    printf("%d\n",n);
    for(int i = 1 ; i <= n ; ++ i){
        int num = 0;
        int ti = M / 10000;
        for(int j = 1 ; j <= ti ; ++ j)num += rand() % 10000;
        printf("%d ",num);
    }
    printf("\n");
    for(int i = 1 ; i <= n ; ++ i)printf("%d ",M - rand() % Left);
    printf("\n");
    return 0;
}
