#include <bits/stdc++.h> 
using namespace std;

int a[10005];

int main(){
	int m, cnt = 0;
	scanf("%d",&m);
	for(int t = 1 ; t <= m ; ++ t){
		int cz;
		scanf("%d",&cz);
		if(cz == 0){
			int x, i;
			scanf("%d",&x);
			for(i = cnt ; i >= 1 ; -- i){
				if(a[i] > x)a[i+1] = a[i];
				else break;	
			}
			a[i+1] = x;
			cnt ++;
		}
		else{
			int k;
			scanf("%d",&k);
			printf("%d\n",a[k]);	
		}
	}
	return 0;
}

