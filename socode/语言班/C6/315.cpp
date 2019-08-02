#include <bits/stdc++.h>
using namespace std;

int main(){
	double h;
	scanf("%lf", &h);
	int cnt = 0;
	while(h > 1){
		cnt ++;
		h /= 2;
	}
	printf("%d\n", cnt);
	return 0;
}
