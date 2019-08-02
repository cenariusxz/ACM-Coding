#include <bits/stdc++.h>
using namespace std;

int num[5005];

int main(){
	int n = 0,m;
	scanf("%d",&m);
	for(int i = 1 ; i <= m ; ++ i){
		int t, a;
		scanf("%d%d",&t,&a);
		if(t == 0){
			int j;
			for(j = n ; j >= 1 ; -- j){
				if(num[j] > a)num[j+1] = num[j];
				else break;	
			}
			num[j+1] = a;
			n++;
		}
		else printf("%d\n",num[a]);
	}
	return 0; 
} 
