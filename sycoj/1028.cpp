#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

int a[maxn];

void qsort(int l,int r){
	int i = l,j = r;
	int pivot = a[(l+r)/2];
	if(l < r){
		while(i <= j){
			while(a[i] < pivot)i++;
			while(a[j] > pivot)j--;
			if(i <= j){
				swap(a[i],a[j]);
				i++;j--;
			}
		}
	}
	if(l<j)qsort(l,j);
	if(i<r)qsort(i,r);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	qsort(1,n);
	for(int i = 1 ; i <= n ; ++ i)printf("%d\n",a[i]);
	return 0;
}


