#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;

void solve(){

}

double a[20], b[20], c[20], d[20];

int main(){
	scanf("%lf%lf",&a[1],&b[1]);
	scanf("%lf%lf",&c[1],&d[1]);
	scanf("%lf%lf",&a[2],&b[2]);
	scanf("%lf%lf",&c[2],&d[2]);
	for(int i = 3 ; i <= 10 ; ++ i){
		a[i] = 2 * a[i-1] - a[i-2];
		b[i] = 2 * b[i-1] - b[i-2];
		c[i] = 2 * c[i-1] - c[i-2];
		d[i] = 2 * d[i-1] - d[i-2];
	}
	for(int i = 1 ; i <= 10 ; ++ i)printf("%.2lf %.2lf\t\t%.2lf %.2lf\n", a[i], b[i], c[i], d[i]);
	return 0;
}

