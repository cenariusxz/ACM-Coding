#include<bits/stdc++.h>
using namespace std;

int main(){
	int x;
	scanf("%d",&x);
	for(int i = 2 ; i * i <= x ; ++ i){
		if(x % i == 0){
			int cnt = 0;
			while(x % i == 0){
				x /= i;
				cnt++;	
			}
			printf("%d %d\n",i,cnt);
		}
	}
	if(x != 1)printf("%d %d\n",x,1);
	return 0;
}
