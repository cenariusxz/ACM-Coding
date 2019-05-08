#include <bits/stdc++.h>
using namespace std;

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    srand(time(NULL));
    for(int T = 9 ; T <= 9 ; ++ T){
    freopen( (string("T1-") + ID[T] + ".in").c_str(),"w",stdout);

    int n = 1000, m = 1000;
    printf("%d %d\n",n,m);
    for(int i = 1 ; i <= n ; ++ i){
        for(int j =1 ; j <= m ; ++ j){
            int p = rand()%52;
            if(p<26)putchar('a'+p);
            else putchar('A'+(p-26));
        }
        putchar('\n');
    }

    }
    return 0;
}
