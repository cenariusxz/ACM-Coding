#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int DP(int N,int M)
{
	if (0 == N)
		return 1;
    if (1 == N)
		return 0;
	if (1 == M)
		return 0;
	if (2 == N)
		return M-1;
	int n1, n2, sum;
	n1 = (DP(N-1,M)*(M-2))%1000000007;
	n2 = DP(N - 2, M)*(M - 1)%1000000007;
	sum = (n1 + n2) % 1000000007;
	return sum;
}
int main()
{
	int N, M;
	cin >> N >> M;
	cout << DP(N,M)<<endl;
	return 0;
}
