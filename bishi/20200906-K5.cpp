#include <bits/stdc++.h>
using namespace std;
const int maxn = 6000 + 5;

int n, num[maxn], ans = 0;
char s[maxn];
void solve(int pos){
	int st = 0;
	for(int i = 1 ; i < pos ; ++ i){
		if(s[i] == s[pos] && num[i] > num[pos]){
			st = i;
			break;
		}
	}
	if(!st)return;
	for(int i = pos - 1 ; i >= st ; -- i){
		ans ++;
		swap(num[i], num[i+1]);
		swap(s[i], s[i+1]);
	}
}
int main(){
	scanf("%d%s", &n, s+1);
	for(int i = 1 ; i <= 2 * n ; ++ i)scanf("%d", &num[i]);
	for(int i = 1 ; i <= n ; ++ i){
		int pos1 = 0, pos2 = 0;
		for(int j = 1 ; j <= 2 * n ; ++ j){
			if(num[j] == i){
				if(pos1)pos2 = j;
				else pos1 = j;
			}
		}
		solve(pos1);
		solve(pos2);
	}
	printf("%d\n", ans);
	return 0;
}

