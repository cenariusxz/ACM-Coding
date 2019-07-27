#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll jiecheng(int n){
	if(n == 1)return 1;
	return n*jiecheng(n-1);
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%lld\n",jiecheng(n));
	return 0;
}
