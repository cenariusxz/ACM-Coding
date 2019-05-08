#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
const int maxm=505;

int id[maxm],n,m;
int ma[maxm][maxm];

void topo(){
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=1;i<=n;i++){
		if(!id[i])q.push(i);
	}
	int cnt=0;
	while(!q.empty()){
		int u=q.top();
		printf("%d",u);
		if(++cnt==n)printf("\n");
		else printf(" ");
		q.pop();
		for(int i=1;i<=n;++i){
			if(i==u)continue;
			if(ma[u][i]){
				id[i]--;
				if(!id[i])q.push(i);
			}
		}
	}
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(ma,0,sizeof(ma));
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			if(!ma[a][b]){
				ma[a][b]=1;
				id[b]++;
			}
		}
		topo();
	}
	return 0;
}
