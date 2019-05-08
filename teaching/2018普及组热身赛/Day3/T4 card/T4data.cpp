#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};
int a[maxn];
int main(){
    srand(time(NULL));
//    for(int T = 5 ; T <= 7 ; ++ T){
//    freopen( (string("T4-") + ID[T] + ".in").c_str(),"w",stdout);
    freopen("T2-Test.in","w",stdout);
    int n = 5;
    printf("%d\n",n);
    for(int i = 1 ; i <= n ; ++ i)a[i] = rand()%10+1;
    a[1] = rand()%3+1;
    for(int i = 1 ; i <= n ; ++ i)printf("%d ",a[i]);      //a
    printf("\n");

//    }
    return 0;
}
