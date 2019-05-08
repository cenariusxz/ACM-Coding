#include<stdio.h>
#include<string.h>

int fa[100005],num[100005];
bool vi[100005];

void init(){
	for(int i=1;i<=100004;i++)fa[i]=i;
}

int find(int x){
	int r=x,t;
	while(r!=fa[r])r=fa[r];
	while(x!=r){
		t=fa[x];
		fa[x]=r;
		x=t;
	}
	return r;
}

int main(){
	int a,b,c=0;
	while(scanf("%d%d",&a,&b)!=EOF&&a!=-1||b!=-1){
		printf("Case %d is ",++c);
		if(a==0&&b==0){printf("a tree.\n");continue;}
		init();
		memset(num,0,sizeof(num));
		memset(vi,0,sizeof(vi));
		bool f=1;
		int x=find(a),y=find(b),cnt=0,ans=0;
		if(!vi[a]){
			cnt++;
			vi[a]=1;
		}
		if(!vi[b]){
			cnt++;
			vi[b]=1;
		}
		num[b]++;
		if(num[b]>1)f=0;
		if(x!=y){
			fa[x]=y;
			ans++;
		}
		else f=0;
		while(scanf("%d%d",&a,&b)&&a!=0||b!=0){
			x=find(a),y=find(b);
			if(!vi[a]){
				cnt++;
				vi[a]=1;
			}
			if(!vi[b]){
				cnt++;
				vi[b]=1;
			}
			num[b]++;
			if(num[b]>1)f=0;
			if(x!=y){
				fa[x]=y;
				ans++;
			}
			else f=0;
		}
		if(ans==cnt-1&&f)printf("a tree.\n");
		else printf("not a tree.\n");
	}
	return 0;
}
