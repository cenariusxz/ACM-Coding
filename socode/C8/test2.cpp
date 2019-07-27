#include <bits/stdc++.h> 
using namespace std;

int a[10005];

int main(){
	int n; 
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i = 2;i<=n;++i){
		int k = a[i],j;
		for(j = i-1,j>=1;--j){
			if(a[j]>k)a[j+1] = a[j];
			else break;
		}
		a[j+1] = k;
	}
	for(int i = 1;i<=n;++i){
		if(i==n)printf("%d\n",a[i]);
		else printf("%d ",a[i]);
	}
	return 0;
}

