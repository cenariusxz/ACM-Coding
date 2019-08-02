#include <bits/stdc++.h> 
using namespace std; 

int a[1000005],b[1000005],c[1000005] ;

void merge(int n,int m){
	int p1=1,p2=1;
	int cnt = 0;
	while(){
		if(a[p1]<=b[p2]){
			c[cnt=1]=a[p1];
			cnt ++;
			p1++; 
		}
	}
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i = 1;i<=m;++i){
		scanf("%d"&b[i]);
	}
	merge(n,m);
	
	return 0;
}

