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
	int res = -1, sum = 0;
	for(int i = 0 ; i < n ; ++ i){
		if(A[i] >= 0){
			sum += A[i];
			res = max(res, sum);
		}
		else sum = 0;
	}
	return res;
}

int main(){
	vector<int> A;
	A.PB(1);A.PB(2);A.PB(-3);A.PB(4);A.PB(5);A.PB(-6);
	printf("%d\n", solution(A));
	return 0;
}

