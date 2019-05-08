#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;

char s[maxn][maxn];
int vis1[200],vis2[200];
int n,m;

char ID[11][5] = {"","1","2","3","4","5","6","7","8","9","10"};

int main(){
    for(int T = 1 ; T <= 10 ; ++ T){
    freopen( (string("T1-") + ID[T] + ".in").c_str() ,"r",stdin);
    freopen( (string("T1-") + ID[T] + "-c.out").c_str() ,"w",stdout);

    scanf("%d%d",&n,&m);
    if(T <= 7 && (n<1 || n > 100 || m < 1 || m > 100))printf("NO\n");
    if(T > 7  && (n<1 || n > 1000 || m < 1 || m > 1000))printf("NO\n");
    int nn = 0;
    while(scanf("%s",s[1])!=EOF){
        nn++;
        if(strlen(s[1])!=m)printf("NO\n");
        for(int i = 0 ; s[1][i] ; ++ i){
            if(   !((s[1][i] >= 'a' && s[1][i] <= 'z') || (s[1][i] >= 'A' && s[1][i] <= 'Z' ))       )printf("NO\n");
        }
    }
    if(nn != n)printf("WA\n");
    printf("AC\n");

    }
    return 0;
}
