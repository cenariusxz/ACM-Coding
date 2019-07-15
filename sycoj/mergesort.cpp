#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int n;
int a[maxn], b[maxn];

void mergesort(int left, int right){
	if(left == right)return;
	int mid = (left + right)/2;
	mergesort(left, mid);
	mergesort(mid+1, right);
	int pos1 = left, pos2 = mid+1, cnt = left;
	while(pos1 <= mid && pos2 <= right){
		if(a[pos1] < a[pos2])b[cnt++] = a[pos1++];
		else b[cnt++] = a[pos2++];
	}
	while(pos1 <= mid)b[cnt++] = a[pos1++];
	while(pos2 <= right)b[cnt++] = a[pos2++];
	for(int i = left ; i <= right ; ++ i)a[i] = b[i];
}

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	mergesort(1,n);
	for(int i = 1 ; i <= n ; ++ i)printf("%d ",a[i]);
	printf("\n");
	return 0;
}


