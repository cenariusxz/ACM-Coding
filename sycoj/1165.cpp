#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

int m,n,k;
queue<int>q1, q2;

int main(){
	scanf("%d%d%d",&m,&n,&k);
	for(int i = 1 ; i <= m ; ++ i)q1.push(i);
	for(int i = 1 ; i <= n ; ++ i)q2.push(i);
	while(k --){
		int a = q1.front();q1.pop();
		int b = q2.front();q2.pop();
		printf("%d %d\n",a,b);
		q1.push(a);
		q2.push(b);	
	}
	return 0;
}


