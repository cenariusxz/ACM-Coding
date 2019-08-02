#include <bits/stdc++.h>
using namespace std;

int a[1005],b[1005],c[1005];

void merge(int n,int m){
	int cnt = 0;
	int p1 = 1, p2 = 1;
	while(p1 <= n && p2 <= m){
		if(a[p1] <= b[p2])c[++cnt] = a[p1++];
		else c[++cnt] = b[p2++];
	}
	while(p1 <= n)c[++cnt] = a[p1++];
	while(p2 <= m)c[++cnt] = b[p2++];
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	for(int i = 1 ; i <= m ; ++ i)scanf("%d",&b[i]);
	merge(n,m);
	for(int i = 1 ; i <= n+m ; ++ i){
		printf("%d",c[i]);
		if(i == n+m)printf("\n");
		else printf(" ");
	}
	return 0;
}
