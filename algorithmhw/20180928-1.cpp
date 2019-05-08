#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[maxn],b[maxn];

int get(int a[],int b[],int n,int m,int id){
//	printf("findk : %d\n",id);
	int l1 = 1, r1 = n, l2 = 1, r2 = m, k = id;
	while(1){
//		printf("[%d,%d] [%d,%d] k:%d\n",l1,r1,l2,r2,k);
		if(l1 > r1)return b[l2 + k - 1];
		if(l2 > r2)return a[l1 + k - 1];
		int mid1 = (l1 + r1) >> 1;
		int mid2 = (l2 + r2) >> 1;
		int len11 = mid1 - l1;
		int len12 = r1 - mid1;
		int len21 = mid2 - l2;
		int len22 = r2 - mid2;
		int tl1 = l1, tr1 = r1, tl2 = l2, tr2 = r2;
		if(a[mid1] <= b[mid2]){
			if(k > len11 + len21 + 1)tl1 = mid1 + 1;
			else if(k > len11 + len21)tl1 = mid1;
			if(k < len11 + len21 + 2)tr2 = mid2 - 1;
			else if(k < len11 + len21 + 3)tr2 = mid2;
			k -= tl1 - l1;
		}
		else{
			if(k > len11 + len21 + 1)tl2 = mid2 + 1;
			else if(k > len11 + len21)tl2 = mid2;
			if(k < len11 + len21 + 2)tr1 = mid1 - 1;
			else if(k < len11 + len21 + 3)tr1 = mid1;
			k -= tl2 - l2;
		}
		l1 = tl1, r1 = tr1, l2 = tl2, r2 = tr2;
	}
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
		for(int i = 1 ; i <= m ; ++ i)scanf("%d",&b[i]);
		int ans1 = get(a,b,n,m,(n+m+1)/2);
		int ans2 = get(a,b,n,m,(n+m)/2+1);
		printf("%d %d %.1lf\n",ans1,ans2,(ans1+ans2)*1.0/2);
	}
	return 0;
}
