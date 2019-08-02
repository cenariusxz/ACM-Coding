#include <stdio.h>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

int n;
ll m;
ll a[maxn], dp[maxn], use[maxn], sum[maxn];

multiset<ll>s;
deque<int>q;

int main(){
	scanf("%d%lld",&n,&m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	for(int i = 1 ; i <= n ; ++ i){
		if(a[i] > m){
			printf("-1\n");
			return 0;
		}
	}
	for(int i = 1 ; i <= n ; ++ i)sum[i] = sum[i-1] + a[i];
	int pos = 0;
	for(int i = 1 ; i <= n ; ++ i){
		while(sum[i] - sum[pos] > m)pos++;
		while(!q.empty()){
			if(a[q.front()] <= a[i]){
				s.erase(use[q.front()]);
				q.pop_front();
			}
			else break;
		}
		while(!q.empty()){
			if(q.back() <= pos){
				s.erase(use[q.back()]);
				q.pop_back();	
			}
			else break;
		}
		if(!q.empty()){
			s.erase(use[q.back()]);
			use[q.back()] = dp[pos] + a[q.back()];
			s.insert(use[q.back()]);
			use[i] = dp[q.front()] + a[i];
			q.push_front(i);
			s.insert(use[i]);
		}
		else{
			use[i] = dp[pos] + a[i];
			q.push_front(i);
			s.insert(use[i]);	
		}
		dp[i] = *(s.begin());
	}
	
	printf("%lld\n",dp[n]);
	return 0;
}
