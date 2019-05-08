#include<stdio.h>
#include<string.h>

int fa[2005],n,m,num[2005];

void init(){
	for(int i=1;i<=n;i++)fa[i]=i;
	memset(num,0,sizeof(num));
}

int find(int x){
	int r=x,t1,t2,c=0;
	while(r!=fa[r]){
		c+=num[r];
		r=fa[r];
	}
	while(x!=r){
		t1=fa[x];
		t2=c-num[x];
		fa[x]=r;
		num[x]=c%2;
		x=t1;
		c=t2;
	}
	return r;
}

int main(){
	int t;
	scanf("%d",&t);
		for(int q=1;q<=t;q++){
			scanf("%d%d",&n,&m);
			init();
			int i;
			bool f=1;
			for(i=1;i<=m;i++){
				int a,b;
				scanf("%d%d",&a,&b);
				int x=find(a),y=find(b);
				if(x!=y){
					num[x]=((num[b]+1-num[a])%2+2)%2;
					fa[x]=y;
				}
				else{
					if(num[a]==num[b])f=0;
				}
			}
			printf("Scenario #%d:\n",q);
			if(!f)printf("Suspicious bugs found!\n");
			else printf("No suspicious bugs found!\n");
			printf("\n");
		}
	return 0;
}
