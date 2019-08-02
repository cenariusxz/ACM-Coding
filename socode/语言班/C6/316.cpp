#include <bits/stdc++.h>
using namespace std;

int main(){
	int x;
	scanf("%d",&x);
	if(x == 0){
		printf("0\n");
	}
	else{
		if(x < 0){
			printf("-");
			x = -x;	
		}
		bool flag = 0;	//已经输出过非0的数了 
		while(x){
			int t = x % 10;
			x /= 10;
			if(t == 0){
				if(flag)printf("%d",t);
			}
			else{
				printf("%d",t);
				flag = 1;
			}
		}
		printf("\n");
	}
	return 0;	
}
