#include <bits/stdc++.h>
using namespace std;

int main(){
	int left = 1 , right = 100;		// 猜数的范围 
	while(true){
		if(left <= right){			// 在还有未排除的数时进行猜数 
			int mid = (left+right)/2;	// 猜中间的一个数 
			printf("我猜是 %d\n", mid);
			char ans[5];
			scanf("%s",ans);		// 当程序猜大了的时候输入'>'，当程序猜中的时候输入'=',当程序猜小的时候输入'<' 
			if(ans[0] == '='){		// 根据用户输入跳出循环或者是缩小猜数的范围 
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
		else{		// 所有数都排除了但还没有得到正确答案，就说明使用者在使坏！ 
			printf("你一定是在骗我！\n");	
		}
	}
	return 0;	
}
