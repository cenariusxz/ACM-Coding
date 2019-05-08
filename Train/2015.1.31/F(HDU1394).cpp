#include<stdio.h>
#include<string.h>
int n,a[5001],tree[5001],inver[5001];

 int tree_sum(int x)
 {
 	int cnt=0;
 	while(x>0){
 		cnt+=tree[x];
 		x-=(x&-x);
 	}
 	return cnt;
 }

 void tree_add(int x,int d)
 {
 	while(x<=n){
 		tree[x]+=d;
 		x+=(x&-x);
 	}
 }
 void run()
 {
 	int i,sum=0,x,min;
 	memset(tree,0,sizeof(tree));
 	for(i=1;i<=n;i++){
 		scanf("%d",&a[i]);
 		a[i]++;
 	}
 	for(i=1;i<=n;i++){
 		tree_add(a[i],1);
 		inver[i]=a[i]-tree_sum(a[i]);
 		//printf("%d ",inver[i]);
 		sum+=inver[i];
 	}
 	memset(tree,0,sizeof(tree));
 	min=sum;
 	for(i=1;i<n;i++){
 		tree_add(a[i],1);
 		inver[i]+=tree_sum(a[i])-1;
 		sum=sum-inver[i]+n-1-inver[i];
 		if(sum<min) min=sum;
 	}
 	printf("%d\n",min);
 }

int main()
{
	while(scanf("%d",&n)!=EOF&&n){
		run();
	}
 return 0;
}

