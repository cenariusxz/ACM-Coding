#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
const long double eps = 1000000;

int w,h,n;
long double EW[1000010],EH[1000010];
long double P[1000010];
int cnt[1000010];
long double at_pw[1000010];

int main(){
	scanf("%d%d%d",&w,&h,&n);
	at_pw[0] = 1.0;
	for(int i = 1; i <= n; ++i){
		at_pw[i] = at_pw[i - 1] * 0.5;
	}
	P[0] = 1.0;
	cnt[0] = n;
	for(int i = 1; i <= n; ++i){
		P[i] = P[i - 1] * (n - i + 1) / (1.0 * i);
		cnt[i] = cnt[i - 1];
		while(cnt[i] && P[i] > eps){
			cnt[i]--;
			P[i] *= 0.5;
		}
	}
	EW[0] = w;
	EH[0] = h;
	for(int i = 1; i <= n; ++i) EW[i] = 1.0 * w / (1.0*(i+1)*(i+1));
	for(int i = 1; i <= n; ++i) EH[i] = 1.0 * h / (1.0*(i+1)*(i+1));
	long double ans = 0;
	for(int i = 0; i <= n; ++i){
		ans += P[i] * EW[i] * EH[n - i] * at_pw[cnt[i]];
	}
	cout << fixed <<setprecision(60) <<ans << endl;
	return 0;
}
