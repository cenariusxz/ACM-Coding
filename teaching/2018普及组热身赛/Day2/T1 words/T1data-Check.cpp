#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 +5;

char s[maxn],t[maxn];
int n;

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 1 ; T <= 10 ; ++ T){
        freopen( (string("T1-") + ID[T] + ".in").c_str() ,"r",stdin);
        freopen( (string("T1-") + ID[T] + "-c.out").c_str() ,"w",stdout);
        scanf("%d",&n);
        if(T <= 2 && n != 2)printf("NO\n");
        if(T > 2 && T <=5 && (n < 2 || n > 10))printf("NO\n");
        if(T > 5 && (n < 2 || n > 100))printf("NO\n");
        int suml = 0;
    /*    for(int i = 1 ; i <= n ; ++ i){
            scanf("%s",s);
            int len = strlen(s);
            suml += len;
            if(T <= 2 && (len < 1 || len > 10))printf("NO\n");
            if(T > 2 && T <=5 && (len < 1 || len > 100))printf("NO\n");
            if(T > 5 && (len < 1 || len > 100000))printf("NO\n");
        }
        if(suml > 1000000)printf("NO\n");*/
        while(scanf("%s",s)!=EOF)suml++;
        if(suml != n)printf("NO\n");
        printf("AC2\n");
    }
    return 0;
}
