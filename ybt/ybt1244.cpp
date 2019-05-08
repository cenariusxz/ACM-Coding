#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int n,a[maxn],m;
map<int,int>M;

int main(){
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
    for(int i = 1 ; i <= n ; ++ i)M[a[i]] = 1;
    scanf("%d",&m);
    sort(a+1,a+1+n);
    for(int i = 1 ; i <= n ; ++ i){
        if(M[m-a[i]]){
            printf("%d %d\n",a[i],m-a[i]);
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
