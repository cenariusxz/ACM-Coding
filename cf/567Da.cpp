#include<stdio.h>
#include<string.h>
const int maxm=200005;

int st1[maxm<<2],st2[maxm<<2],maxx,minn;

int max(int a,int b){
	return a>b?a:b;
}

int min(int a,int b){
	return a<b?a:b;
}

void update(int o,int l,int r,int x){
	if(l==r){
		st1[o]=x;
		st2[o]=x;
		return;
	}
	int m=l+((r-l)>>1);
	if(x<=m)update(o<<1,l,m,x);
	if(x>=m+1)update(o<<1|1,m+1,r,x);
	st1[o]=max(st1[o<<1],st1[o<<1|1]);
	st2[o]=min(st2[o<<1],st2[o<<1|1]);
}

void query1(int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		maxx=max(st1[o],maxx);
		return;
	}
	int m=l+((r-l)>>1);
	if(ql<=m)query1(o<<1,l,m,ql,qr);
	if(qr>=m+1)query1(o<<1|1,m+1,r,ql,qr);
}

void query2(int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		minn=min(st2[o],minn);
		return;
	}
	int m=l+((r-l)>>1);
	if(ql<=m)query2(o<<1,l,m,ql,qr);
	if(qr>=m+1)query2(o<<1|1,m+1,r,ql,qr);
}

int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int main()
{
	int n=read();int k=read();int a=read();int m=read();
	int num=(n+1)/(a+1);
	int ans=-1,i;
	memset(st2,0x3f,sizeof(st2));
	update(1,0,n+1,0);
	update(1,0,n+1,n+1);
	for(i=1;i<=m;i++){
		int p=read();
		if(ans==-1){
			maxx=0;
			minn=0x7fffffff;
			query1(1,0,n+1,0,p);
			query2(1,0,n+1,p,n+1);
			num-=(minn-maxx)/(a+1);
			num+=(p-maxx)/(a+1);
			num+=(minn-p)/(a+1);
			if(num<k)ans=i;
			update(1,0,n+1,p);
		}
	}
	printf("%d\n",ans);
    return 0;
}
