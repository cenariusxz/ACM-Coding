#include <bits/stdc++.h>
using namespace std;

void me_fish(int t){
	if(t == 0){
		printf("我的小鲤鱼");
		return;
	}
	printf("抱着");
	me_fish(t-1);
	printf("的我");
}

int main(){
	printf("吓得我抱起了");
	me_fish(3);
	printf("\n");
	return 0;
}
