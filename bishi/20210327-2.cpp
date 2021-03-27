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

int id[100005];

int solution(int N, vector<int> &A, vector<int> &B){
	memset(id, 0, sizeof(id));
	int m = A.size();
	for(int i = 0 ; i < m ; ++ i){
		id[A[i]] ++;
		id[B[i]] ++;
	}
	sort(id + 1, id + 1 + N);
	int res = 0;
	for(int i = 1 ; i <= N ; ++ i) res += i * id[i];
	return res;
}

int main(){
	int n = 5;
	vector<int>A,B;
	A.PB(2);A.PB(2);A.PB(1);A.PB(2);
	B.PB(1);B.PB(3);B.PB(4);B.PB(4);
	printf("%d\n", solution(n,A,B));
	return 0;
}

