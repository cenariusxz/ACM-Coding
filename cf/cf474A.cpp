#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;

char s[10][100] = {
"qwertyuiop",
"asdfghjkl;",
"zxcvbnm,./"
},t[1000];

int d;

char get(char x){
    for(int i = 0 ; i < 3 ; ++ i){
        for(int j = 0 ; s[i][j] ; ++ j){
            if(s[i][j] == x)return s[i][j+d];
        }
    }
}

int main(){
    scanf("%s",t);
    if(t[0] == 'L')d=1;
    else d = -1;
    scanf("%s",t);
    for(int i = 0 ; t[i]; ++ i){
        printf("%c",get(t[i]));
    }
    printf("\n");
    return 0;
}
