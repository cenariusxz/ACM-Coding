#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

map<string,int>M;
char s[maxn];

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        string tmp(s);
        if(M[tmp]){
            printf("%s%d\n",s,M[tmp]);
            M[tmp]++;
        }
        else{
            printf("OK\n");
            M[tmp]++;
        }
    }
    return 0;
}
