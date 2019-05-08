#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

int num[100004];

int main(){
	int p,c;
	int cnt=0;
	while(scanf("%d%d",&p,&c)!=EOF){
		printf("Case %d:\n",++cnt);
		if(p<=1000){
			memset(num,0,sizeof(num));
			queue<int>q;
			for(int i=1;i<=p;++i)q.push(i);
			int pos=0;
			stack<int>S;
			while(c--){
				char s[10];
				scanf("%s",s);
				if(s[0]=='N'){
					if(!S.empty()){
						int u=S.top();
						printf("%d\n",u);
						S.pop();
						q.push(u);
					}
					else{
						int u=q.front();
						while(num[u]){
							q.pop();
							num[u]--;
							u=q.front();
						}
						printf("%d\n",u);
						q.pop();
						q.push(u);
					}
				}
				else{
					int a;
					scanf("%d",&a);
					S.push(a);
					num[a]++;
				}
			}
		}
		else{
			memset(num,0,sizeof(num));
			int pos=0;
			stack<int>S;
			while(c--){
				char s[10];
				scanf("%s",s);
				if(s[0]=='N'){
					if(!S.empty()){
						int u=S.top();
						printf("%d\n",u);
						S.pop();
					}
					else{
						while(num[pos]){
							pos++;
						}
						printf("%d\n",pos);
					}
				}
				else{
					int a;
					scanf("%d",&a);
					S.push(a);
					num[a]=1;
				}
			}
		}
	}
	return 0;
}
