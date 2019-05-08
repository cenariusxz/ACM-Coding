#include<stdio.h>
#include<string.h>

int fa[10005],n,a[10005],ans[50005];
int l1[20005],l2[20005],y[50005],z[50005];
bool x[50005];
int head[10005],nxt[40005],point[40005],size;
char s[10];

void add(int a,int b){
	point[size]=b;
	nxt[size]=head[a];
	head[a]=size++;
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

int mmax(int a,int b){
	return a>b?a:b;
}

void init(){
	for(int i=0;i<n;i++)fa[i]=i;
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
	int c=0;
	while(scanf("%d",&n)!=EOF){
		if(c++)printf("\n");
		int i,m;
		size=0;
		memset(head,-1,sizeof(head));
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		init();
		scanf("%d",&m);
		for(i=1;i<=m;i++)scanf("%d%d",&l1[i],&l2[i]);
		int q;
		scanf("%d",&q);
		for(i=1;i<=q;i++){
			scanf("%s",s);
			if(s[0]=='q'){
				x[i]=0;
				scanf("%d",&y[i]);
			}
			else{
				x[i]=1;
				scanf("%d%d",&y[i],&z[i]);
				add(y[i],z[i]);
			}
		}
		int j;
		bool f;
		for(i=1;i<=m;i++){
			f=1;
			for(j=head[l1[i]];~j;j=nxt[j]){
				if(point[j]==l2[i]){f=0;break;}
			}
			if(!f)continue;
			int x1=find(l1[i]),y1=find(l2[i]);
			if(x1!=y1){
				if(a[x1]>a[y1])fa[y1]=x1;
				else if(a[x1]<a[y1])fa[x1]=y1;
				else if(x1<y1)fa[y1]=x1;
				else fa[x1]=y1;
			}
		}
		int cnt=0;
		for(i=q;i>=1;i--){
			if(x[i]){
				int x1=find(y[i]),y1=find(z[i]);
				if(x1!=y1){
					if(a[x1]>a[y1])fa[y1]=x1;
					else if(a[x1]<a[y1])fa[x1]=y1;
					else if(x1<y1)fa[y1]=x1;
					else fa[x1]=y1;
				}
			}
			else{
				int x1=find(y[i]);
				ans[++cnt]=a[x1]>a[y[i]]?x1:-1;
			}
		}
		for(i=cnt;i>=1;i--){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}
