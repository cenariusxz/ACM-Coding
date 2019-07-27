#include <bits/stdc++.h>
using namespace std;

const int n = 10;

int main(){
	int n = 5;
	int h = 10;
	int cnt = 10;
	scanf("%d",&h);
	while( h > 1 ){
		int cnt = 0;
		printf("%d\n",cnt);
		h /= 2;
	}
	printf("%d\n",cnt);
	return 0;
}

