#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

int main(){
    double x;
    scanf("%lf",&x);
    double l = 0 , r = 1e6;
    for(int i = 1 ; i <= 50 ; ++ i){
    	double mid = (l+r)/2;
    	if(mid*mid <= x)l = mid;
    	else r = mid;
    }
    printf("%.5lf\n",l);
    return 0;
}
