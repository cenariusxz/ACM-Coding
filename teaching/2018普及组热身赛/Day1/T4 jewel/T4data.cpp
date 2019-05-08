#include <bits/stdc++.h>
using namespace std;

int a[50][50];

int main(){
    freopen("T4-11.in","w",stdout);
    srand(time(NULL));
    int n = 5;
    for(int i = 1 ; i <= n ; ++ i){
        a[i][i] = 0;
        for(int j = i +1 ; j <= n ; ++ j){
            a[i][j] = a[j][i] = rand()%10+ 1;
        }
    }
    printf("%d\n",n);
    for(int i = 1 ; i <= n ; ++ i){
        for(int j = 1 ; j <= n ; ++ j){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
