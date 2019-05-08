#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;

int T;
int n;
char s[1010];
char init[100010];
int Len[20],L;

bool Check(char *str,int LEN,int p){
	for(int i = 1; i <= LEN; ++i){
		if(init[p + i - 1] != str[i]) return false;
	}
	return true;
}	

bool Solve(){
	for(int i = 1; i <= L; ++i){
		if(s[i] != 'L') continue;
		// 1 ~ i - 1 , i + 1 ~ L
		bool f1 = true,f2 = true;
		if(i > 1){
			char tmp[1010];
			for(int j = 1; j <= i - 1; ++j){
				tmp[j] = s[i - j];
				if(tmp[j] == 'L') tmp[j] = 'R';
				else tmp[j] = 'L';
			}
			f1 = Check(tmp,i - 1,1);
		}
		if(i < L){
			char tmp2[1010];
			for(int j = i + 1; j <= L; ++j){
				tmp2[j - i] = s[j];
			}
			f2 = Check(tmp2,L - i,1);
		}
		if(f1 && f2) return true;
	}
	return false;
}

int main(){
	int len = 1,pos = 1;
	init[1] = 'L';
	Len[1] = 1;
	for(int i = 2; i <= 14; ++i){
		init[++pos] = 'L';
		for(int j = pos - 1; j >= 1; --j){
			if(init[j] == 'L') init[++pos] = 'R';
			else init[++pos] = 'L';
		}
		Len[i] = pos;
	}
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%d%s",&n,s + 1);
		L = strlen(s + 1);
		printf("Case %d: ",tt);
		if(n > 14) n = 14;
		if(n <= 14){
			if(L > Len[n]){
				printf("No\n");
				continue;
			}
			int tL = Len[n];
			bool f = false;
			for(int i = 1; i <= tL; ++i){
				if(i + L - 1 > tL) break;
				if(Check(s,L,i)) f = true; 
			}
			if(f){
				printf("Yes\n");
			}
			else{
				printf("No\n");
			}
		}
		else{
			if(Solve()){
				printf("Yes\n");
			}
			else{
				char ts[1010];
				for(int i = 1; i <= L; ++i){
					if(s[i] == 'L')
						ts[L + 1 - i] = 'R';
					else
						ts[L + 1 - i] = 'L';
				}
				if(Solve()){
					printf("Yes\n");
				}
				else{
					printf("No\n");
				}
			}
		}
	}
	return 0;
}
