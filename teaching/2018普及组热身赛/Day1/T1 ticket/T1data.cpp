#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("T1-5.in","w",stdout);
    srand(time(NULL));
    int a = rand()%100000+1;
    int b = rand()%100000+1;
    int c = rand()%100000+1;
    int n = rand()%1000+1;
    int lim = 1000000/n + 1;
    printf("%d %d %d %d\n",a,b,c,n);
    for(int i = 1 ; i <= n ; ++ i){
        printf("%d ",rand()%lim + 1);
    }
    printf("\n");
    return 0;
}
