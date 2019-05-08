#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;

struct node{
	int a,b,h;
	bool operator < (const node x)const{
		return h < x.h;
	}
}nd[maxn];

struct point{
	int x,y;
}ans[maxn<<2],tmp[maxn<<2];

int left[maxn],right[maxn];
int n;

void solve(int l,int r){
	if(l == r){
		left[l] = 2*l-1;
		right[l] = left[l]-1;
		ans[++right[l]] = (point){nd[l].a,nd[l].h};
		ans[++right[l]] = (point){nd[l].b,0};
		return;
	}
	int mid = (l + r) >> 1;
	solve(l,mid);
	solve(mid+1,r);
	int l1 = left[l], r1 = right[l], l2 = left[mid+1], r2 = right[mid+1];
	int cnt = 0, last1 = 0, last2 = 0;
	int p1 = l1, p2 = l2;
	while(p1 <= r1 && p2 <= r2){
		if(ans[p1].x == ans[p2].x){
			if(ans[p2].y == 0)tmp[++cnt] = ans[p1];
			else tmp[++cnt] = ans[p2];
			last1 = ans[p1].y;
			last2 = ans[p2].y;
			p1++;p2++;
		}
		else if(ans[p1].x < ans[p2].x){
			last1 = ans[p1].y;
			if(!last2)tmp[++cnt] = ans[p1];
			p1++;
		}
		else{
			last2 = ans[p2].y;
			if(last2)tmp[++cnt] = ans[p2];
			else tmp[++cnt] = (point){ans[p2].x,last1};
			p2++;
		}
	}
	while(p1 <= r1)tmp[++cnt] = ans[p1++];
	while(p2 <= r2)tmp[++cnt] = ans[p2++];
	right[l] = left[l]-1;
	for(int i = 1 ; i <= cnt ; ++ i)ans[++right[l]] = tmp[i];
}

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d%d%d",&nd[i].a,&nd[i].b,&nd[i].h);
	sort(nd + 1, nd + 1 + n);
	solve(1,n);
	int l = left[1], r = right[1];
	for(int i = l ; i <= r ; ++ i)printf("(%d,%d)\n",ans[i].x,ans[i].y);
	return 0;
}
