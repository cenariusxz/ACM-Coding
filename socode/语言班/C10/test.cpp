#include <bits/stdc++.h>
using namespace std;

int a[1000005];

void bubblesort(int n){		//用冒泡排序对a数组前n个数进行排序 
	for(int i = n ; i >= 2 ; -- i){		// 前i个数是无序的,将第i个数换成最大值 
		for(int j = 1 ; j < i ; ++ j){
			if(a[j] > a[j+1])swap(a[j],a[j+1]);
		}
	}
}

int main(){
	int a,b,c;
	scanf("%d,%d,%d",&a,&b,&c);
	printf("%d %d %d",a,b,c);
	
	int n;
	scanf("%d",&n);

	bubblesort(n);

	return 0;
}
