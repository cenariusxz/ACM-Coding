#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
struct node{
	int t1,t2;
	bool operator < (const node a)const{
		return t2 < a.t2;
	}
}nd[maxn];
int n,ans;

priority_queue<int>q;

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d",&nd[i].t1,&nd[i].t2);
	sort(nd+1,nd+1+n);
	ll sum = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(sum + nd[i].t1 <= nd[i].t2){
			sum += nd[i].t1;
			ans ++;
			q.push(nd[i].t1);	
		}
		else{
			if(!q.empty() && nd[i].t1 < q.top()){
				int t = q.top();q.pop();
				sum = sum - t + nd[i].t1;
				q.push(nd[i].t1);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
