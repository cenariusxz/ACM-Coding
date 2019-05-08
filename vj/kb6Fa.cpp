#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char a[2005][10];
int fa[2005];
struct seg{
	int a,b,l;
}s[2000*2000+5];

void init(int n){
	for(int i=1;i<=n;i++)fa[i]=i;
}

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

bool cmp(seg a,seg b){
	return a.l<b.l;
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0){
		int i,j,k,l,c=0;
		for(i=1;i<=n;i++)scanf("%s",a[i]);
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				l=0;
				for(k=0;k<7;k++){
					if(a[i][k]!=a[j][k])l++;
				}
				s[++c].a=i;
				s[c].b=j;
				s[c].l=l;
			}
		}
		init(n);
		sort(s+1,s+c+1,cmp);
		int ans=0,t=0;
		for(i=1;i<=c;i++){
			int x=find(s[i].a),y=find(s[i].b);
			if(x!=y){
				fa[x]=y;
				ans+=s[i].l;
				t++;
				if(t==n-1)break;
			}
		}
		printf("The highest possible quality is 1/%d.\n",ans);
	}
	return 0;
}
