#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;

string ss[100];
vector<char>v;
char f[100],s[100001];
char M[500];
int vis[500];
int vis2[500];
ll N[100];
ll k;

void init(){
	N[0]=1;
	for(int i=1;i<=18;++i)N[i]=N[i-1]*9;
	ss[1]="a",f[1]='a';
	for(int i=2;i<=17;++i){
		ss[i]=ss[i/2]+(char)(f[i/2]+1)+ss[i/2];
		f[i]=f[i/2]+1;
	}
}

int main(){
	init();
	while(scanf("%lld",&k)!=EOF&&k){
		v.clear();
		memset(M,0,sizeof(M));
		memset(vis,0,sizeof(vis));
		memset(vis2,0,sizeof(vis2));
		scanf("%s",s);
		int l=strlen(s);
		string tmp;
		bool flag=1;

		for(int i=1;i<=17;++i){
			if(l==ss[i].length()){
				flag=0;
				tmp=ss[i];
			}
		}
		if(flag){
			printf("-1\n");
			continue;
		}

		for(int i=0;i<l;++i){
			if(s[i]!='?'){
				if(M[tmp[i]]==0)M[tmp[i]]=s[i];
				else{
					if(s[i]!=M[tmp[i]]){
						flag=1;
						break;
					}
				}
			}
		}
		if(flag){
			printf("-1\n");
			continue;
		}

		for(int i=0;i<l;++i){
			if(s[i]=='?'){
				if(M[tmp[i]]==0){
					if(vis[tmp[i]]==0){
						v.push_back(tmp[i]);
						vis[tmp[i]]=1;
					}
				}
				else s[i]=M[tmp[i]];
			}
		}

		flag=0;
		for(int i=1;i<l;++i){
			if(s[i]!='?'&&s[i]==s[i-1]){
				flag=1;
				break;
			}
		}
		if(flag){
			printf("-1\n");
			continue;
		}
		
/*		printf("%s\n",s);
		for(int i=0;i<v.size();++i){
			printf("%c\n",v[i]);
		}*/
		int cnt=v.size();
		if(cnt==0){
			if(k==1&&s[0]!='0')printf("%s\n",s);
			else printf("-1\n");
			continue;
		}
		
		for(int i=0;i<l;++i){
			if(s[i]!='?')vis2[s[i]]=1;
		}

		bool ff=1;
		int c=0;
		for(int i=0;i<l;++i){
			if(s[i]!='?')continue;
			if(s[i]=='?'&&M[tmp[i]]!=0){
				s[i]=M[tmp[i]];
				continue;
			}
			char l='0',r='9';
			if(i==0)l='1';
			flag=0;
			c++;
			ff=1;
			for(char t=l;t<=r;t++){
				if((i-1>=0&&t==s[i-1])||(i+1<l&&t==s[i+1]))continue;
				if(i==0&&vis2[t]==1)continue;
				if(k<=N[cnt-c]){
					M[tmp[i]]=t;
					ff=0;
					break;
				}
				else{
					k-=N[cnt-c];
				}
			}
			if(ff)break;
			s[i]=M[tmp[i]];
		}
		if(ff){
			printf("-1\n");
			continue;
		}
		flag=0;
		for(int i=0;i<l;++i){
			if(s[i]=='?'){
				if(M[tmp[i]])s[i]=M[tmp[i]];
				else flag=1;
			}
		}
		if(flag){
			printf("-1\n");
			continue;
		}

		flag=0;
		for(int i=1;i<l;++i){
			if(s[i]!='?'&&s[i]==s[i-1]){
				flag=1;
				break;
			}
		}
		if(flag){
			printf("-1\n");
			continue;
		}

		if(k>1){
			printf("-1\n");
			continue;
		}
		if(s[0]=='0'){
			printf("-1\n");
			continue;
		}
		printf("%s\n",s);
	}
	return 0;
}
