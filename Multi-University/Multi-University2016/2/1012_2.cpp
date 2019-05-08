#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn=1e5+5;

char s[maxn];
char t[5005];
int ans[maxn];
int is[maxn];
int v0[5050],v1[5050];
int num0[26],num1[26];
int n,m;

void solve(){
	memset(num0,0,sizeof(num0));
	memset(num1,0,sizeof(num1));
	memset(ans,0,sizeof(ans));
	memset(is,0,sizeof(is));
	for(int i=0;t[i];++i)num0[t[i]-'a']++;
	for(int i=0;t[i];++i)num1[s[i]-'a']++;
	for(int stx=0;s[stx+m-1];++stx){
		if(stx!=0){
			num1[s[stx-1]-'a']--;
			num1[s[stx+m-1]-'a']++;
		}
		if(stx==0){
			bool f=1;
			for(int i=0;i<26&&f;++i){
				if(num0[i]!=num1[i])f=0;
			}
			if(!f)continue;
			is[stx]=1;
		}
		else{
			if(is[stx-1]){
				if(s[stx-1]!=s[stx+m-1])continue;
				else is[stx]=1;
			}
			else{
				bool f=1;
				for(int i=0;i<26&&f;++i){
					if(num0[i]!=num1[i])f=0;
				}
				if(!f)continue;
				is[stx]=1;
			}
		}
		memset(v0,0,sizeof(v0));
		v0[0]=1;
		int i;
		for(i=0;i<m;++i){
			if(v0[i]==0&&v0[i+1]==0)break;
			if(v0[i]){
				if(t[i]==s[stx+i])v0[i+1]=1;
				else if(t[i]==s[stx+i+1]&&t[i+1]==s[stx+i])v0[i+2]=1;
			}
		}
		if(i==m&&v0[m])ans[stx]=1;
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
