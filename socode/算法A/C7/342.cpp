#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;

int a[maxn];

int bsearch(int a[], int start, int end, int x){
	int l = start, r = end;
	while(l <= r){
		int mid = (l+r) >> 1;
		if(a[mid] == x)return mid;
		else if(a[mid] < x)l = mid+1;
		else r = mid-1;
	}
	return -1;
}

int main(){
	int n,s;
	scanf("%d%d",&n,&s);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	sort(a+1, a+1+n);
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = i + 1 ; j <= n ; ++ j){
			int x = s - a[i] - a[j];
			if(x < a[j])break;
			int ans = bsearch(a,j+1,n,x);
			if(ans != -1){
				printf("Yes.\n");
				return 0;	
			}
		}
	}
	printf("No.\n");
	return 0;
}

