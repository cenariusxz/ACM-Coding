#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;

int fa[10005],n,m,num[10005],a[5005],b[5005],v[5005];
char s[10];

void init(){
	for(int i=0;i<=10004;i++)fa[i]=i;
	memset(num,0,sizeof(num));
}

int find(int x){
	int r=x,c=0,t1,t2;
	while(r!=fa[r]){
		c+=num[r];
		r=fa[r];
	}
	while(x!=r){
		t1=fa[x];
		t2=c-num[x];
		num[x]=c%2;
		fa[x]=r;
		x=t1;
		c=t2;
	}
	return r;
}
int main(){
	scanf("%d%d",&n,&m);
	init();
	int i,cnt=0,ans=0;
	map<int,int>M;
	for(i=1;i<=m;i++){
		scanf("%d%d%s",&a[i],&b[i],s);
		a[i]--;
		if(s[0]=='e')v[i]=0;
		else v[i]=1;
		if(M.find(a[i])==M.end())M[a[i]]=++cnt;
		if(M.find(b[i])==M.end())M[b[i]]=++cnt;		
	}
	bool f=1;
	for(i=1;i<=m&&f;i++){
		int x=find(M[a[i]]),y=find(M[b[i]]);
		if(x!=y){
			num[x]=(num[M[b[i]]]+v[i]-num[M[a[i]]]+2)%2;
			fa[x]=y;
			if(f)ans++;
		}
		else{
			if(f){
				if(!v[i]&&num[M[a[i]]]==num[M[b[i]]])ans++;
				else if(v[i]&&num[M[a[i]]]!=num[M[b[i]]])ans++;
				else f=0;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
