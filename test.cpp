#include<stdio.h>

int main(){
	int a[10] = {5, 3, 4, 7, 3, 5, 6}, b[10], n = 7, i, j, mn;
	for(i = 0 ; i < n ; ++ i)b[i] = -1;		// -1 表示还没有确定编号 
	for(i = 1 ; i <= n ; ++ i){				// 本轮要找所有剩下的数中的最小值，它们的编号为 i 
		mn = -1;							// 本轮的最小值，-1 表示还没有最小值 
		for(j = 0 ; j < n ; ++ j){
			if(b[j] != -1)continue;			// b[j] 不为 -1 表示之前已经有编号了，不参与后续的编号 
			if(mn == -1 || a[j] < mn)mn = a[j];		// 当没有找到过最小值，或当前的数更小的话，更新最小值 
		}
		if(mn == -1)break;					// 如果一轮没有找到最小值，就是所有数都有编号了，就结束循环 
		for(j = 0 ; j < n ; ++ j){ 
			if(a[j] == mn)b[j] = i;			// 将所有等于本轮最小值的都加上编号 
		}
	}
	for(i = 0 ; i < n ; ++ i){				// 输出 
		printf("%d", b[i]);
		if(i == n-1)printf("\n");
		else printf(" ");
	}
	return 0;
}

