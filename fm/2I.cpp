#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int ma[105][105],id[105],n;

void topo(){
	queue<int>q;
	for(int i=1;i<=n;++i)if(!id[i])q.push(i);
	int cnt=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		printf("%d",u);
		if(++cnt==n)printf("\n");
		else printf(" ");
		for(int i=1;i<=n;++i){
			if(i!=u&&ma[u][i]){
				id[i]--;
				if(!id[i])q.push(i);
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int a;
		while(scanf("%d",&a)&&a){
			ma[i][a]=1;
			id[a]++;
		}
	}
	topo();
	return 0;
}
