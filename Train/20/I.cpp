#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<string>
#include<map>
#include<set>
using namespace std;
const int mod=1e9+7;
const int Mod=277;

vector<string>v[8];
map<string,int>m;
set<string>S[20005];
char s[50];

int main(){
	int cnt=0;
	while(scanf("%s",s)!=EOF){
		if(s[2]=='e'){
			cnt++;
			int now=cnt%7;
			for(int i=0;i<v[now].size();++i){
				string tmp=v[now][i];
				int num=m[tmp];
				S[num].erase(tmp);
				num--;
				if(num)S[num].insert(tmp);
				m[tmp]--;
			}
			v[now].clear();
			while(scanf("%s",s)){
				if(s[0]=='<')break;
				if(strlen(s)<=3)continue;
				else{
					string tmp(s);
					v[now].push_back(tmp);
					int num=m[tmp];
					if(num)S[num].erase(tmp);
					num++;
					S[num].insert(tmp);
					m[tmp]++;
				}
			}
		}
		else{
			int num;
			printf("%s",s);
			scanf("%d%s",&num,s);
			printf(" %d>\n",num);
			for(int i=20000;i>=1;--i){
				if(S[i].size()==0)continue;
				if(S[i].size()>=num){
					set<string>::iterator it=S[i].begin();
					for(;it!=S[i].end();++it){
						printf("%s %d\n",(*it).c_str(),i);
					}
					break;
				}
				else{
					set<string>::iterator it=S[i].begin();
					for(;it!=S[i].end();++it){
						printf("%s %d\n",(*it).c_str(),i);
					}
					num-=S[i].size();
				}
			}
			printf("</top>\n");
		}
	}
	return 0;
}
