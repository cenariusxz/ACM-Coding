#include<stdio.h>
#define N 50000
struct node{
    int v;
    int l,r;
}stree[131072];
int n,a[N+1],fa[N+1];
 
 int t_query(int pos,int left,int right)
 {
     int mid=(stree[pos].l+stree[pos].r)/2;
     //printf("%d %d %d %d %d\n",pos,stree[pos].l,stree[pos].r,left,right);
     if(left==stree[pos].l&&right==stree[pos].r) return stree[pos].v;
     if(left>mid) return t_query(pos*2+1,left,right);
     if(right<=mid) return t_query(pos*2,left,right);
     return t_query(pos*2,left,mid)+t_query(pos*2+1,mid+1,right);
 }

 void t_updata(int pos,int add)
 {
     stree[pos].v+=add;
     if(pos!=1) t_updata(pos/2,add);
 }

 void t_build(int pos,int left,int right)
 {
     int mid=(right+left)/2;
     stree[pos].l=left;
     stree[pos].r=right;
     //printf("%d %d %d %d\n",pos,left,right,mid);
     if(left==right) {
         stree[pos].v=a[left];
         fa[left]=pos;
         return;
     }
     t_build(pos*2,left,mid);
     t_build(pos*2+1,mid+1,right);
     stree[pos].v=stree[pos*2].v+stree[pos*2+1].v;
 }

 void init()
 {
     int i,j,p,q;
     char s[6];
     scanf("%d",&n);
     for(i=1;i<=n;i++)
         scanf("%d",&a[i]);
     t_build(1,1,n);
     //for(i=1;i<=25;i++) printf("%d %d %d %d\n",i,stree[i].l,stree[i].r,stree[i].v);
     while(1){
         scanf("%s",&s);
         if(s[0]=='E') break;
         scanf("%d%d",&p,&q);
         switch(s[0]){
             case('A'):t_updata(fa[p],q);break;
             case('S'):t_updata(fa[p],-q);break;
             case('Q'):printf("%d\n",t_query(1,p,q));break;
         }
     }
 }

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        printf("Case %d:\n",i);
        init();
    }
 return 0;
 }
