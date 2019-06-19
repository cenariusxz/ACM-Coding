#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e4 + 5;

int a[maxn];

int main(){
	int w,n;
	scanf("%d%d",&w,&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	int pos = n, ans = 0;
	for(int i = 1 ; i <= pos ; ++ i){
		if(i == pos)ans++;
		else if(a[i] + a[pos] <= w)ans++,pos--;
		else if(a[i] <= w)ans++;
	}
	printf("%d\n",ans);
	return 0;
}

