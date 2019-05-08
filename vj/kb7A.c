#include<stdio.h>
#include<string.h>

int c[50005],N;
/*
void add(int x,int a){
	while(x<=N){
		c[x]+=a;
		x+=(x&-x);
	}
	return;
}

int sum(int x){
	int t=0;
	while(x){
		t+=c[x];
		x-=(x&-x);
	}
	return t;
}*/
int lowbit(int x){return x&(-x);}
void add(int x,int a){
	for(int i=x;i<=N;i+=lowbit(i))c[i]+=a;
}
int sum(int x){
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i))ans+=c[i];
	return ans;
}
int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		for(int q=1;q<=T;q++){
			printf("Case %d:\n",q);
			memset(c,0,sizeof(c));
			scanf("%d",&N);
			int i,t;
			for(i=1;i<=N;i++){
				scanf("%d",&t);
				add(i,t);
			}
			char s[10];
			while(scanf("%s",s)){
			//	printf("%s\n",s);
				if(s[0]=='S'){
					scanf("%d%d",&i,&t);
					add(i,-t);
				}
				else if(s[0]=='A'){
					scanf("%d%d",&i,&t);
					add(i,t);
				}
				else if(s[0]=='Q'){
					scanf("%d%d",&i,&t);
					printf("%d\n",sum(t)-sum(i-1));
				}
				else if(s[0]=='E')break;
			}
		}
	}
	return 0;
}
