#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int a[5];
char s[maxn];

int main(){
	for(int i = 1 ; i <= 4 ; ++ i)scanf("%d",&a[i]);
	scanf("%s",s);
	int ans = 0;
	for(int i = 0 ; s[i] ; ++ i)ans += a[s[i] - '0'];
	printf("%d\n",ans);
	return 0;
}
