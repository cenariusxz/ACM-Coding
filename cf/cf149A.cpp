#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int n;
int a[20];

int main(){
    scanf("%d",&n);
    for(int i = 1 ; i <= 12 ; ++ i)scanf("%d",&a[i]);
    if(n == 0)printf("0\n");
    else{
        sort(a+1,a+12+1);
        int sum = 0;
        for(int i = 12 ; i >= 1 ; -- i){
            sum += a[i];
            if(sum >= n){
                printf("%d\n",12-i+1);
                return 0;
            }
        }
        printf("-1\n");
    }
    return 0;
}
