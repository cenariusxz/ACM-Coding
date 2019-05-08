#include <bits/stdc++.h>
using namespace std;

char s[105][105];
int xx[8] = {0,0,1,-1,1,1,-1,-1};
int yy[8] = {1,-1,0,0,1,-1,1,-1};

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; ++ i){
		scanf("%s",s[i] + 1);
	}
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if(s[i][j] == '?')s[i][j] = '0';
		}
	}
	for(int i = 1 ; i <= n ; ++ i){
		for(int j = 1 ; j <= m ; ++ j){
			if(s[i][j] == '*'){
				for(int k = 0 ; k < 8 ; ++ k){
					int x = i + xx[k];
					int y = j + yy[k];
					if(x < 1 || x > n || y < 1 || y > m)continue;
					if(s[x][y] == '*')continue;
					s[x][y] ++;
				}
			}
		}
	}
	for(int i = 1 ; i <= n ; ++ i){
		printf("%s\n",s[i]+1);
	}
	return 0;
}
