#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

struct node{
	int s,a;
	bool operator < (const node x)const{
		return a>x.a;
	}
}nd[maxn];
int n;

int m1[maxn],m2[maxn],sum[maxn];

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&nd[i].s);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&nd[i].a);
	sort(nd+1,nd+1+n);
	for(int i = 1 ; i <= n ; ++ i)sum[i] = sum[i-1] + nd[i].a;
	for(int i = 1 ; i <= n ; ++ i)m1[i] = max(m1[i-1],nd[i].s);
	for(int i = n ; i >= 1 ; -- i)m2[i] = max(m2[i+1],2*nd[i].s+nd[i].a);
	for(int i = 1 ; i <= n ; ++ i)printf("%d\n",max(sum[i]+m1[i]*2,sum[i-1]+m2[i]));
	return 0;
}
