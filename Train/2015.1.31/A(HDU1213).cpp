#include<stdio.h>
#include<algorithm>
using namespace std;
int fa[1001];

 int find(int x)
 {
 	if(fa[x]==x) return x;
 	return fa[x]=find(fa[x]);
 }

 void combine(int x,int y)
 {
 	fa[find(x)]=find(y);
 }

 void init(int x)
 {
 	int i;
 	for(i=1;i<=x;i++)
 		fa[i]=i;
 }

 void run()
 {
 	int n,m,i,x,y,count=1;
 	scanf("%d%d",&n,&m);
 	init(n);
 	for(i=1;i<=m;i++){
 		scanf("%d%d",&x,&y);
 		if(find(x)!=find(y)) combine(x,y);
 	}
 	for(i=1;i<=n;i++) fa[i]=find(i);
 	sort(fa+1,fa+n+1);
 	for(i=1;i<n;i++)
 		if(fa[i]!=fa[i+1]) count++;
 	printf("%d\n",count);
 }
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		run();
 return 0;
}

