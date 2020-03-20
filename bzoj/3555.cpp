#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e8 + 9;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 3e4 + 5;
const int maxm = 1e6 + 5;
 
int n,l;
char s[205];
 
struct Hash{
    ull B,len,Has[205],Base[205];
 
    void init(char *s, int _len, ll _B){    // s[0] ¿ªÊ¼ 
        B = _B; len = _len;
        Base[0] = 1; Has[0] = 0;
        for(int i=1;i<=len;i++){
            Base[i] = Base[i-1]*B;
            Has[i] = Has[i-1]*B + s[i-1];
        }
    }

    ull gethash(int l,int r){       // s[l]~s[r] 
        if(l > r)return 0;
        l++; r++;
        return Has[r] - Has[l-1] * Base[r-l+1];
    }
}H[maxn];
 
ull res[maxn];

int main(){
    int num;
    scanf("%d%d%d",&n,&l,&num);
    for(int i = 1 ; i <= n ; ++ i){
        scanf("%s",s);
        H[i].init(s,l,171);
    }
    int ans = 0;
    for(int i = 0 ; i < l ; ++ i){
        for(int j = 1 ; j <= n ; ++ j){
            ull h1 = H[j].gethash(0, i-1);
            ull h2 = H[j].gethash(i+1, l-1);
            ull hsum = h1 * H[j].Base[l-1-i] + h2;
            res[j] = hsum;
        }
        sort(res + 1, res + 1 + n);
        int cnt = 0;
        for(int j = 1 ; j <= n ; ++ j){
            if(res[j] == res[j-1])ans += (++cnt);
            else cnt = 0;   
        }
    }
    printf("%d\n", ans);
    return 0;
}
