#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<map>
#include<vector>
using namespace std;
#define pb push_back

map<string,int>M;
map<string,int>::iterator it;

struct rule{
	vector<string>v;
	string res;
	bool vis;
}R[1000];

char s[10000];
char mod1[10]="IF",mod2[10]="THEN";

int main(){
	int n,m;
	M.clear();
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		R[i].v.clear();
		R[i].vis=0;
		while(scanf("%s",s)){
			if(strcmp(s,mod1)==0)continue;
			if(strcmp(s,mod2)==0)break;
			R[i].v.pb(string(s));
		}
		scanf("%s",s);
		R[i].res=string(s);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		scanf("%s",s);
		M[string(s)]=1;
	}
	bool f=1;
	while(f){
		f=0;
		for(int i=1;i<=n;++i){
			if(R[i].vis||M[R[i].res])continue;
			int j;
			for(j=0;j<R[i].v.size();++j){
				string tmp=R[i].v[j];
				if(!M[tmp])break;
			}
			if(j==R[i].v.size()){
				f=1;
				M[R[i].res]=1;
			}
		}
	}
	printf("可得到：\n");
	for(it=M.begin();it!=M.end();it++){
		if((*it).second){
			printf("%s\n",(*it).first.c_str());
		}
	}
	return 0;
}
