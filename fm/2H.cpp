#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int id[27],ma[27][27],n,tmp[27],ans[27];

int topo(){
	memcpy(tmp,id,sizeof(tmp));
	queue<int>q;
	for(int i=1;i<=n;++i)if(!tmp[i])q.push(i);
	int cnt=0;
	bool f=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		ans[++cnt]=u;
		if(!q.empty())f=0;
		for(int i=1;i<=n;++i){
			if(i!=u&&ma[u][i]){
				tmp[i]--;
				if(!tmp[i])q.push(i);
			}
		}
	}
	if(cnt!=n)return 0;
	if(f)return 1;
	return -1;
}

char s[10];

int main(){
	int m;
	while(scanf("%d%d",&n,&m)!=EOF&&n+m){
		bool f=0;
		memset(id,0,sizeof(id));
		memset(ma,0,sizeof(ma));
		for(int i=1;i<=m;++i){
			scanf("%s",s);
			if(f)continue;
			int a=s[0]-'A'+1;
			int b=s[2]-'A'+1;
			ma[a][b]=1;
			id[b]++;
			int ff=topo();
			if(!ff){
				printf("Inconsistency found after %d relations.\n",i);
				f=1;
			}
			else if(ff==1){
				printf("Sorted sequence determined after %d relations: ",i);
				for(int j=1;j<=n;++j)printf("%c",'A'+ans[j]-1);
				printf(".\n");
				f=1;
			}
		}
		if(!f)printf("Sorted sequence cannot be determined.\n");
	}
	return 0;
}
