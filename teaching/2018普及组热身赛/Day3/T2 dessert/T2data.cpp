#include <bits/stdc++.h>
using namespace std;

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    srand(time(NULL));
//    for(int T = 8 ; T <= 10 ; ++ T){
//    freopen( (string("T2-") + ID[T] + ".in").c_str(),"w",stdout);
    freopen("T2-Test.in","w",stdout);
    int n = 5;
    printf("%d\n",n);
    for(int i = 1 ; i <= n ; ++ i)printf("%d ",rand()%10+1);
    printf("\n");
    for(int i = 1 ; i <= n ; ++ i)printf("%d ",rand()%10+1);
    printf("\n");

//    }
    return 0;
}
