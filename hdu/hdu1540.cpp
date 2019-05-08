#include<stdio.h>
#include<string.h>
const int maxm=5e4+5;
const int INF=0x3f3f3f3f;

int ma[maxm<<2],mi[maxm<<2];
int sta[maxm],cnt;
int maxx,minn;
char s[10];

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}

void update(int o,int l,int r,int ind,int c){
	if(l==r){
		if(c==1){
			ma[o]=-1;
			mi[o]=INF;
		}
		else ma[o]=mi[o]=l;
		return;
	}
	int m=l+((r-l)>>1);
	if(ind<=m)update(o<<1,l,m,ind,c);
	else update(o<<1|1,m+1,r,ind,c);
	ma[o]=max(ma[o<<1],ma[o<<1|1]);
	mi[o]=min(mi[o<<1],mi[o<<1|1]);
}

void query1(int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		maxx=max(maxx,ma[o]);
		return;
	}
	int m=l+((r-l)>>1);
	if(ql<=m)query1(o<<1,l,m,ql,qr);
	if(qr>=m+1)query1(o<<1|1,m+1,r,ql,qr);
}

void query2(int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r){
		minn=min(minn,mi[o]);
		return;
	}
	int m=l+((r-l)>>1);
	if(ql<=m)query2(o<<1,l,m,ql,qr);
	if(qr>=m+1)query2(o<<1|1,m+1,r,ql,qr);
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		cnt=0;
		memset(ma,-1,sizeof(ma));
		memset(mi,0x3f,sizeof(mi));
		update(1,0,n+1,0,0);
		update(1,0,n+1,n+1,0);
		for(int i=1;i<=m;++i){
			scanf("%s",s);
			if(s[0]=='D'){
				int ind;
				scanf("%d",&ind);
				update(1,0,n+1,ind,0);
				sta[++cnt]=ind;
			}
			else if(s[0]=='Q'){
				int ind;
				scanf("%d",&ind);
				maxx=-1;
				minn=INF;
				query1(1,0,n+1,0,ind);
				query2(1,0,n+1,ind,n+1);
				if(minn==maxx)printf("0\n");
				else printf("%d\n",minn-maxx-1);
			}
			else if(s[0]=='R'){
				update(1,0,n+1,sta[cnt--],1);
			}
		}
	}
	return 0;
}
