#include <bits/stdc++.h>
using namespace std;

int main(){
	srand(time(0));		// 随机数部分的初始化 
	int MAX = 100;		// 定义猜数的最大范围 
	int ans = rand() % MAX + 1;	// 随机产生一个1到MAX之间的整数 
	printf("我有一个 1 到 %d 之间的数，你来猜猜是多少？\n", MAX);	// 输出提示 
	while(true){	// 没有结束条件的循环 
		int a;
		scanf("%d", &a);	// 读入一个整数到变量a 
		if( a < ans ){		// 根据输入的数和答案的大小关系决定要执行的分支 
			printf("猜小了，再猜！\n");
		}
		else if( a == ans ){
			printf("恭喜你，猜中了！\n");
			break; 		// 在猜中时跳出循环 
		}
		else{
			printf("猜大了，再猜！\n");	
		}
	}
	return 0;
}
