#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	n = 4;
	for(int state = 0 ; state <= (1<<n)-1 ; ++ state){
		//代表状态的二进制数
		for(int j = 1 ; j <= n ; ++ j){
			//第j个物品，注意二进制数中下标从0开始，j从1开始`
			if(state & (1<<(j-1)))printf("%d ",j);
		}
		printf("\n");
	}
	return 0;
}
