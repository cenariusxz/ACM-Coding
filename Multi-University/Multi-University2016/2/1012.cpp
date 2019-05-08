#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e5+5;

char s[maxn];
char t[5005];
int ans[maxn];
int d1[maxn],d2[maxn];

struct node{
	char s;
	int son[26];
	node(){}
	node(char _s){s=_s;}
}nd[15500];

int n,m;

void solve(){
	memset(nd,0,sizeof(nd));
	memset(d1,0,sizeof(d1));
	memset(d2,0,sizeof(d2));
	int root=0;
	int size=1;
	int tmp=0;
	for(int i=0;t[i];++i){
		int c=t[i]-'a';
		nd[size].s=t[i];
		nd[tmp].son[c]=size;
		tmp=size++;
	}
	tmp=root;
	for(int i=0;t[i+1];++i){
		if(t[i]!=t[i+1]){
			int p=size++;
			int q=size++;
			nd[p].s=t[i+1];
			nd[tmp].son[t[i+1]-'a']=p;
			nd[q].s=t[i];
			nd[p].son[t[i]-'a']=q;
			d1[i]=p;
			d2[i+1]=q;
			if(t[i+2])nd[q].son[t[i+2]-'a']=nd[ nd[ nd[tmp].son[t[i]-'a'] ].son[t[i+1]-'a'] ].son[t[i+2]-'a'];
		}
		tmp=nd[tmp].son[t[i]-'a'];
	}
	for(int i=0;s[i];++i){
		if(d2[i]&&d1[i+1])nd[d2[i]].son[t[i+2]-'a']=d1[i+1];
	}
	
	memset(ans,0,sizeof(ans));
	for(int stx=0;s[stx+m-1];++stx){
		int cnt=0;
		tmp=root;
		while(1){
			if(cnt==m){
				ans[stx]=1;
				break;
			}
			if(nd[tmp].son[s[stx+cnt]-'a']){
				tmp=nd[tmp].son[s[stx+cnt]-'a'];
				cnt++;
			}
			else break;
		}
	}
	for(int i=0;i<n;++i){
		printf("%d",ans[i]);
	}
	printf("\n");
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		scanf("%s%s",s,t);
		solve();
	}
	return 0;
}
