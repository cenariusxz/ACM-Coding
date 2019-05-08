#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

char s[maxn];

int main(){
    scanf("%s",s);
    bool f = 0;
    for(int i = 0 ; s[i] ; ++ i){
        if(s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B'){
            if(f)printf(" ");
            f = 0;
            i += 2;
        }
        else{
            printf("%c",s[i]);
            f = 1;
        }
    }
    printf("\n");
	return 0;
}
