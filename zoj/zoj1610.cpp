#include<stdio.h>
#include<string.h>

int st[32005],ans[8001],p,ql,qr;

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

void update(int o,int l,int r,int c){
	if(ql<=l&&qr>=r){
		st[o]=c;
		return;
	}
	if(st[o]!=-2&&st[o]!=-1){
		st[o<<1]=st[o];
		st[o<<1|1]=st[o];
	}
	int m=l+((r-l)>>1);
	if(ql<=m)update(o<<1,l,m,ql,qr,c);
	if(qr>=m+1)update(o<<1|1,m+1,r,ql,qr,c);
	st[o]=(st[o<<1]==st[o<<1|1])?st[o<<1]:-2;
}

void query(int o,int l,int r){
	if(st[o]==-1){
		p=-1;
		return;
	}
	if(st[o]==-2){
		int m=l+((r-l)>>1);
		query(o<<1,l,m);
		query(o<<1|1,m+1,r);
		return;
	}
	if(st[o]!=p){
		ans[st[o]]++;
		p=st[o];
		return;
	}
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		memset(st,-1,sizeof(st));
		memset(ans,0,sizeof(ans));
		p=-1;
		int i;
		for(i=1;i<=n;i++){
			ql=read();
			qr=read();
			int c=read();
			update(1,1,8000,ql+1,qr,c);
		}
		query(1,1,8000);
		for(i=0;i<=8000;i++)if(ans[i])printf("%d %d\n",i,ans[i]);
		printf("\n");
	}
	return 0;
}
