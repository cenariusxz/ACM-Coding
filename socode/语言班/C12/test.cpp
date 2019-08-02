#include <bits/stdc++.h>
using namespace std;

int n;

void fun(int f[105]){
	printf("%d\n",f[0]);
	f[10] = 105;
}

int a[105];
bool vis[105];

int main(){
	a[0] = 1;
	fun(a);
	printf("%d\n",a[10]);
	return 0;
}
