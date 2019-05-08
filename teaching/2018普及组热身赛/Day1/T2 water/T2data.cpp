#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("T2-10.in","w",stdout);
    srand(time(NULL));
    int n = rand()%5 + 996;
    int m = rand()%5 + 996;
    int k = rand()%5 + 96;
    printf("%d %d %d\n",n,m,k);
    for(int i = 1 ; i <= k ; ++ i){
        printf("%d %d\n",rand()%n + 1,rand()%m + 1);
    }
    return 0;
}
