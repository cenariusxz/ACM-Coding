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

stack<int>s_w,s_max;
int n;

int main(){
	scanf("%d",&n);
	int cnt = 0;
	s_w.push(0);
	s_max.push(0);
	for(int i = 1 ; i <= n ; ++ i){
		int type,c;
		scanf("%d",&type);
		if(type == 0){
			scanf("%d",&c);
			s_w.push(c);
			s_max.push(max(c, s_max.top()));
			cnt++;
		}
		if(type == 1 && cnt){
			s_w.pop();
			s_max.pop();
			cnt--;
		}
		if(type == 2)printf("%d\n",s_max.top());	
	}
	return 0;
}

