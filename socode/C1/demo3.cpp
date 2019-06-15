#include <bits/stdc++.h>
using namespace std;

int main(){
	int left = 1 , right = 100;
	while(true){
		if(left <= right){
			int mid = (left+right)/2;
			printf("我猜是 %d\n", mid);
			char ans[5];
			scanf("%s",ans);
			if(ans[0] == '='){
				printf("猜中咯！\n");
				break;	
			}
			else if(ans[0] == '<'){
				left = mid + 1;
			}
			else{
				right = mid - 1;	
			}
		}
		else{
			printf("你一定是在骗我！\n");	
		}
	}
	return 0;	
}
