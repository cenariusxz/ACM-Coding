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

ll a;
int n;

queue<ll>q1, q2;

int main(){
	while(scanf("%lld%d",&a,&n)!=EOF){
		if(n == 1)printf("%lld\n",a);
		else{
			while(!q1.empty())q1.pop();
			while(!q2.empty())q2.pop();
			n--;
			q1.push(2*a + 1);
			q2.push(3*a + 1);
			ll x;
			while(n--){
				if(q1.front() == q2.front()){
					x = q1.front();
					q1.pop();
					q2.pop();
				}
				else if(q1.front() < q2.front()){
					x = q1.front();
					q1.pop();
				}
				else{
					x = q2.front();
					q2.pop();
				}
				q1.push(2*x + 1);
				q2.push(3*x + 1);
			}
			printf("%lld\n",x);
		}
	}
	return 0;
}


