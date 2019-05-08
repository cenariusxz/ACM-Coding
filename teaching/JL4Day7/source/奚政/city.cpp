#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

struct node{
	int num,id;
	bool operator < (const node x)const{
		if(num == x.num)return id < x.id;
		return num > x.num;
	}
}nd[maxn];

int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	int n,a,b;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%d%d",&a,&b);
		nd[i] = (node){abs(a-b),i};
	}
	sort(nd+1,nd+1+n);
	for(int i = 1 ; i <= n ; ++ i)printf("%d ",nd[i].id);
	printf("\n");
	return 0;
}
