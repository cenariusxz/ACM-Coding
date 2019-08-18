#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_back
#define MP make_pair
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 6;

char s[maxn][105], t[105];
int n;

void qsort(int l,int r){
	if(l >= r)return; 
	int i = l,j = r;
	char pivot[105];
	strcpy(pivot, s[(l+r)/2]);
	while(i <= j){
		while(strcmp(s[i],pivot)<0)i++;
		while(strcmp(s[j],pivot)>0)j--;
		if(i <= j){
			strcpy(t,s[i]);
			strcpy(s[i],s[j]);
			strcpy(s[j],t);
			i++;j--;
		}
	}
	qsort(l,j);
	qsort(i,r);
}

int main(){
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; ++ i)scanf("%s",s[i]);
	scanf("%s",t);
	int cnt = 0;
	for(int i = 1 ; i <= n ; ++ i){
		bool flag = 1;
		for(int j = 0 ; s[i][j] && t[j] ; ++ j){
			if(s[i][j] != t[j])flag = 0;
		}
		if(flag)strcpy(s[++cnt], s[i]);
	}
	qsort(1,cnt);
	for(int i = 1 ; i <= cnt ; ++ i)printf("%s\n",s[i]);
	return 0;
}


