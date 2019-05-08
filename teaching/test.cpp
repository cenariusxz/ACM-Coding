#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int fi[200],la[200];
char s[maxn];

int main(){
	scanf("%s",s+1);
	int len = strlen(s+1);
	memset(fi,-1,sizeof(fi));
	memset(la,-1,sizeof(la));
	for(int i = 1 ; s[i] ; ++ i){
		if(fi[s[i]] == -1)fi[s[i]] = i;
		la[s[i]] = i;
	}
	int ans = 0, L = 0, R = 0;
	while(R < len){
		ans++;
		L = R+1;
		R = la[ s[L] ];
		bool flag = 1;
		while(flag){
			flag = 0;
			for(int i = 'a' ; i <= 'z' ; ++ i){
				if(fi[i] == -1)continue;
				if(fi[i] >= L && fi[i] <= R && la[i] > R){
					R = la[i];
					flag = 1;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
