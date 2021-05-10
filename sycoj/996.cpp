#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

char num[maxn];
int vis[maxn];
int s;

int main(){
	scanf("%s%d",num+1,&s);
	int n = strlen(num+1);
	int pre = 0;
	while(s){
		if(s >= n - pre){
			for(int i = pre+1 ; i <= n ; ++ i)vis[i] = 1;
			break;
		}
		int pos = 1;
		for(int i = 2 ; i <= s+1 ; ++ i){
			if(num[pre+i] < num[pre+pos])pos = i;
		}
		for(int i = 1 ; i < pos ; ++ i)vis[pre+i] = 1;
		s -= pos - 1;
		pre += pos;
	}
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i])continue;
		if(num[i] == '0')vis[i] = 1;
		else break;
	}
	int cnt = 0;
	for(int i = 1 ; i <= n ; ++ i){
		if(vis[i])continue;
		putchar(num[i]);
		cnt++;	
	}
	if(!cnt)putchar('0');
	putchar('\n');
	return 0;
}


