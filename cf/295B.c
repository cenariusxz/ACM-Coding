#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

bool f[20005];
int b[20005];

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		if(n>=m)printf("%d\n",n-m);
		else{
			memset(f,0,sizeof(f));
			memset(b,0,sizeof(b));
			f[n]=1;
			b[n]=0;
			queue<int>q;
			while(!q.empty()){
				q.pop();
			}
			q.push(n);
			int ans=0;
			while(!q.empty()){
				int a=q.front();
				q.pop();
				if(a<m){
					if(!f[2*a]){
						q.push(a*2);
						f[a*2]=1;
						b[a*2]=b[a]+1;
						if(a*2==m){
							ans=b[a*2];
							break;
						}
					}
				}
				if((a-1)>0){
					if(!f[a-1]){
						q.push(a-1);
						f[a-1]=1;
						b[a-1]=b[a]+1;
						if(a-1==m){
							ans=b[a-1];
							break;
						}
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
