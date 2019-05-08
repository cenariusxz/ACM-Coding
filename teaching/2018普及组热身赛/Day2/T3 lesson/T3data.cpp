#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn];

int main(){
    freopen("T3-1.in","w",stdout);
    srand(time(NULL));
    int n = rand()%5 + 100 - 4, k = 10;
    printf("%d %d\n",n,k);
    a[n-1] = a[n] = k;
    for(int i = 1 ; i < k ; ++ i)a[i] = i;
    for(int i = k ; i < n - 1; ++ i)a[i] = rand()%(k-2) + 2;
    for(int i = 1 ; i <= n ; ++ i)printf("%d ",a[i]);
    printf("\n");
    return 0;
}
