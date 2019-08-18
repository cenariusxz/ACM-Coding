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

void qsort(int l,int r){
	if(l >= r)return;
	int i = l, j = r, pivot = a[l];
	while(i <= j){
		while(a[i] < pivot)++i;
		while(a[j] > pivot)--j;
		if(i <= j)swap(a[i++],a[j--]);
	}
	qsort(l, j);
	qsort(i, r);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	qsort(1,n);
	for(int i = 1 ; i <= n ; ++ i){
		printf("%d",a[i]);
		if(i == n)printf("\n");
		else printf(" ");
	}
	return 0;
}

