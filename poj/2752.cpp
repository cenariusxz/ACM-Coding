#include <stdio.h>
#include <string.h>
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
const int maxm = 1e5 + 5;

char s[maxn];
int p[maxn], ans[maxn];

int main(){
	while(scanf("%s",s)!=EOF){
        int i,j = 0;
        int n = strlen(s);
        p[0] = p[1] = 0;
        for(i = 1 ; i < n ; ++ i){
            while(j && s[i] != s[j])j = p[j];
            if(s[i] == s[j])++ j;
            p[i+1] = j;
        }
        int cnt = 0;
        j = n;
        while(j){
        	ans[++cnt] = j;
			j = p[j];	
        }
        for(int i = cnt ; i >= 1 ; -- i){
        	printf("%d", ans[i]);
			if(i == 1)printf("\n");
			else printf(" ");	
        }
    }
    return 0;
}
