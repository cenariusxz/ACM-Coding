#include<stdio.h>
#include<string.h>
#include <set>
using namespace std;

const int maxn=1e5+5;

char ss[maxn],tt[maxn];

int pos[128];
int s[maxn],t[maxn];    //s为待匹配串，t为模板串
int n,m;
set<int>Set[2];
set<int>::iterator it;

inline bool check(int p1,int p2){
	if((!t[p2] && s[p1] >= m-p2) || s[p1] == t[p2])return 1;
	return 0;
}

int main(){
	scanf("%s%s",ss,tt);
	n=strlen(ss),m=strlen(tt);
	memset(pos,-1,sizeof(pos));
	for(int i = n-1 ; i >= 0 ; -- i){
		if(pos[ss[i]] == -1)s[i] = 0;
		else s[i] = pos[ss[i]] - i;
		pos[ss[i]] = i;
	}
	memset(pos,-1,sizeof(pos));
	for(int i = m-1 ; i >= 0 ; -- i){
		if(pos[tt[i]] == -1)t[i] = 0;
		else t[i] = pos[tt[i]] - i;
		pos[tt[i]] = i;
	}
	for(int i = 0 ; i <= n-m ; ++ i){
		if(check(i,0))Set[0].insert(i);
	}

	for(int i = 1 ; tt[i] ; ++ i){
		int now = i&1;
		int pre = now^1;
		Set[now].clear();
		for(it = Set[pre].begin() ; it != Set[pre].end() ; ++it){
			if(check((*it)+i,i))Set[now].insert(*it);
		}
	}
	printf("%d\n",(int)Set[m&1].size());
	return 0;
}
