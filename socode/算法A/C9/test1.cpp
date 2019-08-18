#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];

void quicksort(int l,int r){	// �������[l,r]�����ų������
	if(l >= r)return;
	int pivot = a[l];			// ��׼ֵ
	int i = l, j = r;			// [i,j]δ֪����  [l,i-1]<=pivot  [j+1,r]>=pivot 
	while(i<=j){
		while(a[i] < pivot)i++;
		while(a[j] > pivot)j--;
		if(i<=j){
			swap(a[i],a[j]);
			i++; j--;
		}
	}
	//[l,j] <= pivot  [i,r] >= pivot
	quicksort(l,j);
	quicksort(i,r);
}

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	quicksort(1,n);
	for(int i = 1 ; i <= n ; ++ i){
		printf("%d",a[i]);
		if(i == n)printf("\n");
		else printf(" ");	
	}
	return 0;
}
