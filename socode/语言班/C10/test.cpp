#include <bits/stdc++.h>
using namespace std;

int a[1000005];

void bubblesort(int n){		//��ð�������a����ǰn������������ 
	for(int i = n ; i >= 2 ; -- i){		// ǰi�����������,����i�����������ֵ 
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
