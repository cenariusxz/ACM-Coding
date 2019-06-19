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

struct node{
	int a,id;
	bool operator < (const node x)const{
		if(a == x.a)return id < x.id;
		return a < x.a;
	}
}nd[maxn];

int n;

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)nd[i].id = i;
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&nd[i].a);
	sort(nd + 1,nd + 1 + n);
	int sum = 0, time = 0;
	for(int i = 1 ; i <= n ; ++ i){
		sum += time;
		time += nd[i].a;
	}
	for(int i = 1 ; i <= n ; ++ i){
		printf("%d",nd[i].id);
		if(i == n)printf("\n");
		else printf(" ");
	}
	printf("%.2lf\n", sum*1.0/n);
	return 0;
}


