#include<stdio.h>
#define MAX 10000000
int n,fa[MAX+1],num[MAX+1];

 int find(int x)
 {
 	if(fa[x]==x) return x;
 	return fa[x]=find(fa[x]);
 }

 void combine(int x,int y)
 {
 	int tmp;
 	if(num[x]>num[y]){
 		tmp=x;x=y;y=tmp;
 	}
 	fa[x]=y;
 	num[y]+=num[x];
 }

 void init(int x)
 {
 	int i;
 	for(i=1;i<=x;i++){
 		fa[i]=i;
 		num[i]=1;
 	}
 }

 void run()
 {
 	int i,x,y,max=1;
 	init(MAX);
 	for(i=1;i<=n;i++){
 		scanf("%d%d",&x,&y);
 		if(find(x)!=find(y)) combine(find(x),find(y));
 	}
 	for(i=1;i<=MAX;i++)
 		if(num[find(i)]>max) max=num[find(i)];
 	printf("%d\n",max);
 }

int main()
{
	while(scanf("%d",&n)!=EOF){
		run();
	}
 return 0;
}

