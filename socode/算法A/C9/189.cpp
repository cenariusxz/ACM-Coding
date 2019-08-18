#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
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

int findk(int l,int r,int k){
	int i = l, j = r, pivot = a[l];
	while(i <= j){
		while(a[i] < pivot)++i;
		while(a[j] > pivot)--j;
		if(i <= j)swap(a[i++],a[j--]);
	}
	// [l,j] <= pivot  [j+1,i-1] == pivot  [i,r] >= pivot
	// 1 ~ j - l + 1     j - l ~ i - l     i - l + 1 ~ r - l + 1
	if(k <= j - l + 1)return findk(l, j, k);
	if(k <= i - l)return pivot;
	return findk(i, r, k - (i - l));
}

int main(){
	int n, k;
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	printf("%d\n",findk(1,n,k));
	return 0;
}

