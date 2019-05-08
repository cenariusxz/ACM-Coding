#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("T1-5.in","w",stdout);
    srand(time(NULL));
    int n = 10;
    printf("%d\n",n);
    for(int i = 1 ; i <= n ; ++ i){
        int len = rand()%5 + 96;
        for(int j = 1 ; j <= len ; ++ j)printf("%c",rand()%26+'a');
        printf("\n");
    }
    return 0;
}
