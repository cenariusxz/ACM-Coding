#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int T;
char g[5][5];
int vis[30];
string s1,s2;

void Change(){
	string ts1 = "",ts2 = "";
	for(int i = 0; i < s1.size(); ++i){
		if(s1[i] >= 'a' && s1[i] <= 'z') s1[i] = s1[i] - 'a' + 'A';
		if(s1[i] >= 'A' && s1[i] <= 'Z') ts1 += s1[i];
	}
	for(int i = 0; i < s2.size(); ++i){
		if(s2[i] >= 'a' && s2[i] <= 'z') s2[i] = s2[i] - 'a' + 'A';
		if(s2[i] >= 'A' && s2[i] <= 'Z') ts2 += s2[i];
	}
	s1 = ts1;
	s2 = ts2;
}

void Build(){
	memset(vis,0,sizeof(vis));
	int x = 0,y = 0;
	for(int i = 0; i < s1.size(); ++i){
		if(vis[s1[i] - 'A']) continue;
		g[x][y] = s1[i];
		y++;
		if(y == 5) x++,y = 0;
	}
	for(int i = 0; i < 26; ++i){
		if(vis[i] || i == ('J' - 'A')) continue;
		g[x][y] = i + 'A';
		y++;
		if(y == 5) x++,y = 0;
	}
}

void Solve(){
	int cur = 0;
	for(int i = 0; i < s2.size();){
		if(i == s2.size() - 1){
			if(cur == s2[i] - 'A'){
				cur = (cur + 1) % 26;
				if(cur == 'J' - 'A') 	
			}
		}
	}
}

int main(){
	scanf("%d",&T);
	getchar();
	for(int tt = 1; tt <= T; ++tt){
		getline(cin,s1);
		getline(cin,s2);
		Change();
		Build();
		printf("Case %d: ",tt);
		Solve();
	}
	return 0;
}
