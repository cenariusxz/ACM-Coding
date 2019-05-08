#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct ss{
	char s[50];
	int len;
	bool operator < (const ss a)const{
		return len < a.len;
	}
}s[105];

bool vis[105];

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;++i){
			scanf("%s",s[i].s);
			s[i].len=strlen(s[i].s);
			vis[i]=0;
		}
		sort(s+1,s+n+1);
		int ans=0;
		for(int i=1;i<=n;++i){
		//	if(vis[i])continue;
			for(int j=1;j<=n;++j){
				if(i==j)continue;
				if(s[j].len!=s[i].len)continue;
				int tmp=0;
				for(int k=0;k<s[i].len;++k){
					if(s[i].s[k]>='a'&&s[i].s[k]<='z'&&s[j].s[k]>='a'&&s[j].s[k]<='z'){
						if(s[i].s[k]==s[j].s[k])tmp++;
					}
					else if(s[i].s[k]>='A'&&s[i].s[k]<='Z'&&s[j].s[k]>='A'&&s[j].s[k]<='Z'){
						if(s[i].s[k]==s[j].s[k])tmp++;
					}
					else if(s[i].s[k]>='a'&&s[i].s[k]<='z'&&s[j].s[k]>='A'&&s[j].s[k]<='Z'){
						if(s[i].s[k]==s[j].s[k]-'A'+'a')tmp++;
					}
					else if(s[i].s[k]>='A'&&s[i].s[k]<='Z'&&s[j].s[k]>='a'&&s[j].s[k]<='z'){
						if(s[i].s[k]-'A'+'a'==s[j].s[k])tmp++;
					}
				}
				if(tmp>2){
					vis[i]=1;
					ans++;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
