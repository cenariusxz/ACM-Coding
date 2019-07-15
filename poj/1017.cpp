#include <stdio.h>
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

int a[10], ans = 0;

void solve6(){
	ans += a[6];
	a[6] = 0;
}

void solve5(){
	ans += a[5];
	int cnt1 = a[5] * 11;
	a[1] -= cnt1;
	if(a[1] < 0)a[1] = 0;
	a[5] = 0;	
}

void solve4(){
	ans += a[4];
	int cnt2 = a[4] * 5;
	int cnt1 = 0;
	if(cnt2 > a[2]){
		cnt1 += (cnt2 - a[2]) * 4;
		cnt2 = a[2];
	}
	a[2] -= cnt2;
	a[1] -= cnt1;
	if(a[1] < 0)a[1] = 0;
	a[4] = 0;
}

void solve3(){
	ans += a[3] / 4 + (a[3]%4 != 0);
	int p = a[3] % 4;
	a[3] = 0;
	int cnt2 = 0, cnt1 = 0;
	if(p == 1)cnt2 = 5, cnt1 = 7;
	if(p == 2)cnt2 = 3, cnt1 = 6;
	if(p == 3)cnt2 = 1, cnt1 = 5;
	if(cnt2 > a[2]){
		cnt1 += (cnt2 - a[2]) * 4;
		cnt2 = a[2];
	}
	a[2] -= cnt2;
	a[1] -= cnt1;
	if(a[1] < 0)a[1] = 0;
}

void solve2(){
	ans += a[2] / 9 + (a[2]%9 != 0);
	int p = a[2] % 9;
	a[2] = 0;
	int cnt1 = 0;
	if(p)cnt1 = (9 - p) * 4;
	a[1] -= cnt1;
	if(a[1] < 0)a[1] = 0;
	ans += a[1] / 36 + (a[1]%36 != 0);
	a[1] = 0;
}


int main(){
	while(1){
		for(int i = 1 ; i <= 6 ; ++ i)scanf("%d",&a[i]);
		int sum = 0 ;
		for(int i = 1 ; i <= 6 ; ++ i)sum += a[i];
		if(!sum)break;
		ans = 0;
		solve6();
		solve5();
		solve4();
		solve3();
		solve2();
		printf("%d\n",ans);
	}
	return 0;
}

