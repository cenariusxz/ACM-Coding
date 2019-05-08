#include <bits/stdc++.h>
using namespace std;

int main(){
	int x,y;
	while(scanf("%d%d",&x,&y)!=EOF){
		if(y % x){
			printf("0\n");
			continue;
		}
		y /= x;
		int cnt = 0;
		for(int i = 2 ; i*i <= y ; ++ i){
			if(y % i)continue;
			cnt++;
			while(y % i == 0)y /= i;
		}
		if(y > 1)cnt++;
		printf("%d\n",1<<cnt);
	}
	return 0;
}
