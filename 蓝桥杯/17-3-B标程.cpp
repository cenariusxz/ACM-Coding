#include<stdio.h>

int num[10],Max,use[10];

void dfs(int p,int s){
	if(p==0){
		int tmp=0;
		for(int i=9;i>=1;--i){
			for(int j=1;j<=num[i]-use[i];++j){
				tmp=tmp*10+i;
			}
		}
		if(tmp*s>Max)Max=tmp*s;
		return;
	}
	for(int i=0;i<=num[p];++i){
		use[p]=i;
		int tmp=s;
		for(int j=1;j<=i;++j)tmp=tmp*10+p;
		dfs(p-1,tmp);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		for(int i=1;i<=9;++i)scanf("%d",&num[i]);
		Max=0;
		dfs(9,0);
		printf("%d\r\n",Max);
	}
	return 0;
}
