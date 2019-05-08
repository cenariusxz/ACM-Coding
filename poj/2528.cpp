#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxm=20005;

int st[maxm<<2],add[maxm<<2],seg[maxm];
int x[10005],y[10005];

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

void pushdown(int o,int l,int r){
	if(add[o]){
		add[o<<1]=1;
		add[o<<1|1]=1;
		st[o<<1]=1;
		st[o<<1|1]=1;
		add[o]=0;
	}
}

void pushup(int o){
	if(st[o<<1]==0||st[o<<1|1]==0)st[o]=0;
	else st[o]=1;
}

int query(int o,int l,int r,int ql,int qr){
	if(ql<=seg[l]&&qr>=seg[r]){
		int ans=st[o];
		st[o]=1;
		add[o]=1;
		return ans;
	}
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	int ans=1;
	if(ql<=seg[m]){
		if(query(o<<1,l,m,ql,qr)==0)ans=0;
	}
	if(qr>=seg[m+1]){
		if(query(o<<1|1,m+1,r,ql,qr)==0)ans=0;
	}
	pushup(o);
	return ans;
}

int main(){
	int T=read();
	while(T--){
		int n=read();
		int i,cnt=0;
		for(i=n;i>=1;--i){
			x[i]=read();
			y[i]=read();
			seg[++cnt]=x[i];
			seg[++cnt]=y[i];
		}
		sort(seg+1,seg+cnt+1);
		seg[0]=-1;
		cnt=0;
		for(i=1;i<=2*n;i++){
			if(seg[i]!=seg[i-1])seg[++cnt]=seg[i];
		}
		memset(add,0,sizeof(add));
		memset(st,0,sizeof(st));
		int ans=0;
		for(i=1;i<=n;i++){
			if(query(1,1,cnt,x[i],y[i])==0)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
