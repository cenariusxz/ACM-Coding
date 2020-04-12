#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;
int n,k,sum=0,mini=INF;
struct node{
	int l,s;
}jl[maxm];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&jl[i].l,&jl[i].s);
	}
	sort(jl+1,jl+1+n,cmp);
	for(int i=1;i<=n;i++){
		
	}
	printf("%d",sum*mini);
	return 0;
}

