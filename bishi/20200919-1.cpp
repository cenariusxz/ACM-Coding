#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 6;

char s[maxn], t[maxn];
int M[10][10], vis[10];

int main(){
	scanf("%s%s", s, t);
	for(int i = 0 ; s[i] ; ++ i){
		if(s[i] != t[i])M[s[i] - 'a'][t[i] - 'a']++;
	}
	int sum = 0;
	while(1){
		int st = -1, tmp = -1;
		for(int i = 0 ; i < 6 ; ++ i){
			vis[i] = 0;
			for(int j = 0 ; j < 6 ; ++ j){
				if(M[i][j])st = i, tmp = j;
			}
		}
		if(st == -1)break;
		int cnt = 1;
		M[st][tmp] --;
		vis[tmp] = 1;
		while(tmp != st){
			int nxt = -1;
			for(int j = 0 ; j < 6 ; ++ j){
				if(vis[j] || !M[tmp][j])continue;
				nxt = j;
				break;
			}
			M[tmp][nxt] --;
			vis[nxt] = 1;
			tmp = nxt;
			cnt ++;
		}
		sum += cnt - 1;
	}
	printf("%d\n", sum);
	return 0;
}

