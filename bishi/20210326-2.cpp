#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 6;

int mx0[100005], mx1[100005], mn0[100005], mn1[100005];

int solution(vector<int> &A, int K){
	int n = A.size();
	mx0[0] = mn0[0] = A[0];
	for(int i = 1 ; i < n ; ++ i){
		mx0[i] = max(mx0[i-1], A[i]);
		mn0[i] = min(mn0[i-1], A[i]);
	}
	mx1[n-1] = mn1[n-1] = A[n-1];
	for(int i = n - 2 ; i >= 0 ; -- i){
		mx1[i] = max(mx1[i+1], A[i]);
		mn1[i] = min(mn1[i+1], A[i]);
	}
	int res = min(mx1[K] - mn1[K], mx0[n-K-1] - mn0[n-K-1]);
	for(int i = 1 ; i + K - 1 <= n-2 ; ++ i){
		int mx2 = max(mx0[i-1], mx1[i+K]);
		int mn2 = min(mn0[i-1], mn1[i+K]);
		res = min(res, mx2 - mn2);
	}
	return res;
}

int main(){
	vector<int> A;
	A.PB(3);A.PB(5);A.PB(1);A.PB(3);A.PB(9);A.PB(8);
	printf("%d\n", solution(A, 4));
	return 0;
}

