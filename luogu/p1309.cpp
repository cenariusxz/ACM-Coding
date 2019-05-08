#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;

struct node{
	int s,w,id;
	bool operator< (const node a)const{
		if(s==a.s)return id<a.id;
		return s>a.s;
	}
}nd[maxn],t1[maxn],t2[maxn];


int main(){
	int n,r,q;
	while(scanf("%d%d%d",&n,&r,&q)!=EOF){
		for(int i = 1 ; i <= 2*n ; ++ i)nd[i].id = i;
		for(int i = 1 ; i <= 2*n ; ++ i)scanf("%d",&nd[i].s);
		for(int i = 1 ; i <= 2*n ; ++ i)scanf("%d",&nd[i].w);
		sort(nd+1,nd+2*n+1);
		while(r--){
			for(int i = 1 ; i <= n ; ++ i){
				if(nd[2*i-1].w > nd[2*i].w){
					nd[2*i-1].s++;
					t1[i] = nd[2*i-1];
					t2[i] = nd[2*i];
				}
				else{
					nd[2*i].s++;
					t1[i] = nd[2*i];
					t2[i] = nd[2*i-1];
				}
			}
			int p1 = 1,p2 = 1,pos = 1;
			while(p1 <= n && p2 <= n){
				if(t1[p1] < t2[p2])nd[pos++] = t1[p1++];
				else nd[pos++] = t2[p2++];
			}
			while(p1 <= n)nd[pos++] = t1[p1++];
			while(p2 <= n)nd[pos++] = t2[p2++];
		}
		printf("%d\n",nd[q].id);
	}
	return 0;
}
