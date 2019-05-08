#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int p1 = 1;
    while(1){
        if( a + (p1-1)/b >= p1)p1++;
        else{
            printf("%d\n",p1-1);
            return 0;
        }
    }
    return 0;
}
