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

int solution(vector<int> &A){
	int n = A.size();
	int res = A[1] + A[3];
	int premin = A[1];
	for(int i = 4 ; i < n-1 ; ++ i){
		premin = min(premin, A[i-2]);
		res = min(res, premin + A[i]);
	}
	return res;
}

int main(){
	vector<int> A;
	A.PB(5);A.PB(2);A.PB(4);A.PB(6);A.PB(3);A.PB(7);
	printf("%d\n", solution(A));
	return 0;
}

