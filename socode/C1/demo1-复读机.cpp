#include <bits/stdc++.h> 
using namespace std;
// 以上两行为引入头文件和使用名空间，初学可以不用理解 

char s[10001];		// 定义一个字符数组，数组名为s 
int n;				// 定义一个整型变量，变量名为n 

int main(){			// 主函数，程序的开始位置 
	for(int i = 1 ; i <= 3 ; ++ i){		// 运行三次的一个循环 
		scanf("%s", s);					// 向s读入一个字符串 
		if( i < 3 ) printf("%s/n", s);	// 在前两轮循环的时候，对输入的字符串进行复读（即输出） 
	}
	printf("不陪你玩了！\n"); 			// 输出固定的字符串 
	return 0;		// 函数的结束 
}
