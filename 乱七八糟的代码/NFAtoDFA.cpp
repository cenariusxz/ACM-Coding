#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<stack>
#include<vector>
#include<map>
using namespace std;

#define pb push_back

const int maxn=30;
const int maxm=1e5;

vector<int>Map[maxn][maxn];
char newMap[maxn][maxn];
int sta[maxm],size;
int n;
char tran[maxn],tnum;
map<int,char>vis;

char s[maxn];

void read(){
	scanf("%s",s);
	n=0;
	for(int i=0;s[i];++i){
		if(s[i]>='0'&&s[i]<='9'){
			n=n*10+s[i]-'0';
		}
		else break;
	}
	gets(s);
	tnum=0;
	for(int i=0;s[i];++i){
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
			tran[++tnum]=s[i];
		}
	}
	tran[++tnum]='.';
	for(int i=0;i<n;++i){
		for(int j=1;j<=tnum;++j){
			Map[i][j].clear();
			scanf("%s",s);
			if(s[0]!='v'){
				int k=0;
				while(s[k]){
					while(s[k]&&(s[k]>'9'||s[k]<'0'))++k;
					int num=0;
					while(s[k]>='0'&&s[k]<='9'){
						num=num*10+s[k]-'0';
						++k;
					}
					Map[i][j].pb(num);
					while(s[k]&&(s[k]>'9'||s[k]<'0'))++k;
				}
			}
		}
	}
}

void testread(){
	printf("%d ",n);
	for(int i=1;i<=tnum;++i)printf("%c ",tran[i]);
	printf("\n");
	for(int i=0;i<n;++i){
		printf("%d:\n",i);
		for(int j=1;j<=tnum;++j){
			if(Map[i][j].size()){
				printf("%c:",tran[j]);
				for(int k=0;k<Map[i][j].size();++k){
					printf("%d ",Map[i][j][k]);
				}
				printf("\n");
			}
		}
	}
}

int getvoid(int s){
	stack<int>S;
	for(int i=0;i<n;++i){
		if(s&(1<<i))S.push(i);
	}
	while(!S.empty()){
		int u=S.top();S.pop();
		for(int k=0;k<Map[u][tnum].size();++k){
			int v=Map[u][tnum][k];
			if(!(s&(1<<v))){
				S.push(v);
				s|=(1<<v);
			}
		}
	}
	return s;
}

void solve(){
	vis.clear();
	size=0;
	sta[++size]=getvoid(1);
	vis[sta[size]]='A'+size-1;
	for(int i=1;i<=size;++i){
		for(int j=1;j<tnum;++j){
			int nxts=0;
			for(int u=0;u<n;++u){
				if(sta[i]&(1<<u)){
					for(int k=0;k<Map[u][j].size();++k){
						int v=Map[u][j][k];
						nxts|=(1<<v);
					}
				}
			}
			if(!nxts)newMap[i][j]='.';
			else{
				nxts=getvoid(nxts);
				if(!vis[nxts]){
					sta[++size]=nxts;
					vis[sta[size]]='A'+size-1;
				}
				newMap[i][j]=vis[nxts];
			}
		}
	}
}

void print(){
	printf("   ");
	for(int i=1;i<tnum;++i){
		printf("%4c ",tran[i]);
	}
	printf("\n");
	for(int i=1;i<=size;++i){
		printf("%c: ",vis[sta[i]]);
		for(int j=1;j<tnum;++j){
			if(newMap[i][j]=='.')printf("void ");
			else{
				printf("%4c ",newMap[i][j]);
			}
		}
		printf("\n");
	}
}

int main(){
	read();
//	testread();
	solve();
	print();
	return 0;
}
