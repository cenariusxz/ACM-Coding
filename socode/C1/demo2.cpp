#include <bits/stdc++.h>
using namespace std;

int main(){
	int MAX = 100;
	int ans = rand()%MAX + 1;
	printf("我有一个 1 到 %d 之间的数，你来猜猜是多少？\n", MAX);
	while(true){
		int a;
		scanf("%d", &a);
		if( a < ans ){
			printf("猜小了，再猜！\n");
		}
		else if( a == ans ){
			printf("恭喜你，猜中了！\n");
			break; 
		}
		else{
			printf("猜大了，再猜！\n");	
		}
	}
	return 0;
}
