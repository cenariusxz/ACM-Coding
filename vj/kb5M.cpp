#include<stdio.h>
#include<string.h>

int fa[100005],n,vi[100005],cnt;

int mmax(int a,int b){
	return a>b?a:b;
}

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
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF&&a!=-1||b!=-1){
		if(a==0&&b==0){
			printf("Yes\n");
			continue;
		}
		init();
		cnt=0;
		memset(vi,0,sizeof(vi));
		if(!vi[a]){
			cnt++;
			vi[a]=1;
		}
		if(!vi[b]){
			cnt++;
			vi[b]=1;
		}
		int x=find(a),y=find(b),ans=0;
		bool f=1;
		if(x!=y){
			fa[x]=y;
			ans++;
		}
		else f=0;
		while(scanf("%d%d",&a,&b)&&a!=0||b!=0){
			if(!vi[a]){
				cnt++;
				vi[a]=1;
			}
			if(!vi[b]){
				cnt++;
				vi[b]=1;
			}
			x=find(a),y=find(b);
			if(x!=y){
				fa[x]=y;
				ans++;
			}
			else f=0;
		}
		if(ans==cnt-1&&f)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
