#include <bits/stdc++.h>
using namespace std;

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int a[1005],b[1005],c[1005];

int main(){
    srand(time(NULL));
//    for(int T = 7 ; T <= 10 ; ++ T){
//    freopen( (string("T3-") + ID[T] + ".in").c_str(),"w",stdout);
    freopen("T2-Test.in","w",stdout);
    int n = 5;
    printf("%d\n",n);
    for(int i = 1 ; i <= n ; ++ i){
        while(1){
            a[i] = rand()%10 + 1;
            b[i] = - (rand()%10 + 1);
            c[i] = rand()%10 + 1;
            if(4*a[i]*c[i] - b[i]*b[i]>0)break;
        }
    }
    for(int i = 1 ; i <= n ; ++ i)printf("%d ",0);      //a
    printf("\n");
    for(int i = 1 ; i <= n ; ++ i)printf("%d ",rand()%10+1);      //b
    printf("\n");
    for(int i = 1 ; i <= n ; ++ i)printf("%d ",rand()%10+1);      //c
    printf("\n");
    for(int i = 1 ; i <= n ; ++ i)printf("%d ",rand()%10+1);      //s
    printf("\n");

//    }
    return 0;
}
