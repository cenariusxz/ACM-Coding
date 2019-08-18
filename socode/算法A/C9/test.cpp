#include <bits/stdc++.h>
using namespace std;
int a[100005],b;
void sort_pro(int l,int r){
  	if(l>=r)return;
	int c=a[l];
	int i=l,j=r;
	while(i<=j){
		while(a[i]<c)i++;
		while(a[j]>c)j--;
		if(i<=j){
			swap(a[i],a[j]);
			i++,j--;
		}
	}
	sort_pro(l,j);
	sort_pro(i,r);
}

int main(){
	scanf("%d",&b);
	for(int i=0;i<b;++i)scanf("%d",&a[i]);
	sort_pro(0,b-1);
	for(int i=0;i<b;++i){
		printf("%d",a[i]);
		if(i==b-1)printf("\n");
		else printf(" ");
	}
	return 0;
}

