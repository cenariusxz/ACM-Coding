#include<stdio.h>
#define MIN(x,y) (x)<(y)?x:y
#define MAX(x,y) (x)>(y)?x:y
int n,q,h[50001];

struct node{
	int min,max;
	node(int min=0,int max=0):min(min),max(max){}
}t[200000];

 node tree_query(int p,int l,int r,int ll,int rr)
 {
 	int mid=(l+r)>>1;
 	node x,y;
 	if(l==ll&&r==rr) return t[p];
 	if(mid>=rr) return tree_query(p<<1,l,mid,ll,rr);
 	if(mid+1<=ll) return tree_query((p<<1)+1,mid+1,r,ll,rr);
 	x=tree_query(p<<1,l,mid,ll,mid);
 	y=tree_query((p<<1)+1,mid+1,r,mid+1,rr);
 	return node(MIN(x.min,y.min),MAX(x.max,y.max));
 }

 void tree_build(int p,int l,int r)
 {
 	int mid=(l+r)>>1;
 	if(l==r) t[p].max=t[p].min=h[l];
 	else{
 		tree_build(p<<1,l,mid);
		tree_build((p<<1)+1,mid+1,r);
 		t[p].min=MIN(t[p<<1].min,t[(p<<1)+1].min);
 		t[p].max=MAX(t[p<<1].max,t[(p<<1)+1].max);
 	}
 }

int main()
{
	int i,l,r;
	node x;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
		scanf("%d",&h[i]);
	tree_build(1,1,n);
	for(i=1;i<=q;i++){
		scanf("%d%d",&l,&r);
		x=tree_query(1,1,n,l,r);
		printf("%d\n",x.max-x.min);
	}
 return 0;
}

