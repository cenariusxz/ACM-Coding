#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int n,a[maxn];

int main(){
    scanf("%d",&n);
    for(int i =  1 ; i <= n ; ++ i)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int t = 1;
    for(int i = 2 ; i <= n ; ++ i){
        if(a[i] != a[i-1])a[++t] = a[i];
    }
    for(int i = 1 ; i <= t ; ++ i)printf("%d ",a[i]);
    printf("\n");
    return 0;
}
