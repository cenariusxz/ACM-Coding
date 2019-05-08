#include<stdio.h>
#include<string.h>
const int maxm=300005;
const int INF=0x3f3f3f3f;

char s[300005],ss[10];
int a[300005];
int mi[maxm<<2],ma[maxm<<2],maxx,minn;

int max(int a,int b){
	return a>b?a:b;
}

int min(int a,int b){
	return a<b?a:b;
}

void build(int o,int l,int r){
	if(l==r){
		if(s[l]=='.'){
			ma[o]=0;
			mi[o]=INF;
		}
		else ma[o]=mi[o]=l;
		return;
	}
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
	ma[o]=max(ma[o<<1],ma[o<<1|1]);
	mi[o]=min(mi[o<<1],mi[o<<1|1]);
}

void update(int o,int l,int r,int ind){
	if(l==r){
		if(s[ind]=='.'){
			ma[o]=0;
			mi[o]=INF;
		}
		else ma[o]=mi[o]=l;
		return;
	}
	int m=l+((r-l)>>1);
	if(ind<=m)update(o<<1,l,m,ind);
	else update(o<<1|1,m+1,r,ind);
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
	scanf("%d%d%s",&n,&m,s+1);
	int i,j,pre=0;
	int ans=0;
	int num=-1;
	s[0]=s[n+1]='a';
	for(i=1;i<=n+1;i++){
		if(s[i]=='.'){
			if(!pre)pre=i;
			num++;
		}
		else{
			if(pre){
				ans+=num;
				num++;
				for(j=pre;j<i;++j)a[j]=num;
				pre=0;
				num=-1;
			}
		}
	}
	build(1,0,n+1);
	for(i=1;i<=m;i++){
		int pos;
		scanf("%d%s",&pos,ss);
		if(ss[0]=='.'){
			if(s[pos]=='.')printf("%d\n",ans);
			else{
				maxx=0,minn=n+1;
				s[pos]='.';
				update(1,0,n+1,pos);
				query1(1,0,n+1,0,pos-1);
				query2(1,0,n+1,pos+1,n+1);
				ans-=max(pos-maxx-2,0);
				ans-=max(0,minn-pos-2);
				ans+=max(0,minn-maxx-2);
				printf("%d\n",ans);
			}
		}
		else{
			if(s[pos]=='.'){
				maxx=0,minn=n+1;
				s[pos]=ss[0];
				update(1,0,n+1,pos);
				query1(1,0,n+1,0,pos-1);
				query2(1,0,n+1,pos+1,n+1);
				ans+=max(pos-maxx-2,0);
				ans+=max(0,minn-pos-2);
				ans-=max(0,minn-maxx-2);
				printf("%d\n",ans);
			}
			else printf("%d\n",ans);
		}
	}
	return 0;
}
