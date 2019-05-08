#include<stdio.h>
#include<string.h>
const int MAXM=50000;

int segtree[(MAXM<<2)+5],change[(MAXM<<2)+5];
int head[(MAXM<<2)+5],next[(MAXM<<2)+5],point[(MAXM<<2)+5];
int stx[(MAXM<<2)+5],edx[(MAXM<<2)+5],t;
bool f[(MAXM<<2)+5];

void dfs(int o){
	stx[o]=++t;
	int i;
	for(i=head[o];i!=-1;i=next[i]){
		dfs(point[i]);
	}
	edx[o]=t;
}

/*
void build(int o,int l,int r){
	if(l==r){
		segtree[o]=-1;
	}
	int m=l+((r-l)>>1);
	build(o<<1,l,m);
	build(o<<1|1,m+1,r);
}
*/

void pushup(int o){
	segtree[o]=segtree[o<<1];
}

void pushdown(int o,int l,int r){
	if(~change[o]){
		segtree[o<<1]=change[o];
		segtree[o<<1|1]=change[o];
		change[o<<1]=change[o];
		change[o<<1|1]=change[o];
		change[o]=-1;
	}
}

int query(int o,int l,int r,int q){
	if(l==q&&r==q)return segtree[o];
	if(l==r)return -1;
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	int ans=0;
	if(q<=m){
		ans=query(o<<1,l,m,q);
	}
	else if(q>=m+1){
		ans=query(o<<1|1,m+1,r,q);
	}
	return ans;
}

void update(int o,int l,int r,int ql,int qr,int c){
	if (l > qr || r < ql) return ;
	if(l==ql&&r==qr){
		segtree[o]=c;
		change[o]=c;
		return;
	}
	if(l==r)return;
	pushdown(o,l,r);
	int m=l+((r-l)>>1);
	if(qr<=m){
		update(o<<1,l,m,ql,qr,c);
	}
	else if(ql>=m+1){
		update(o<<1|1,m+1,r,ql,qr,c);
	}
	else{
		update(o<<1,l,m,ql,m,c);
		update(o<<1|1,m+1,r,m+1,qr,c);
	}
	//pushup(o);
}

int main(){
	int T;
	scanf("%d",&T);
	for(int q=1;q<=T;q++){
		printf("Case #%d:\n",q);
		int n,m;
		scanf("%d",&n);
		int i;
		memset(head,-1,sizeof(head));
		memset(next,-1,sizeof(next));
		memset(f,0,sizeof(f));
		int c=0;
		t=0;
		for(i=1;i<=n-1;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			f[a]=1;
			point[c]=a;
			next[c]=head[b];
			head[b]=c++;
		}
		for(i=1;i<=n;i++){
			if(!f[i]){
				dfs(i);
				break;
			}
		}
		memset(segtree,-1,sizeof(segtree));
		memset(change,-1,sizeof(change));
		//	build(1,l,r);
		scanf("%d",&m);
		for(i=1;i<=m;i++){
			char s[10];
			scanf("%s",s);
			if(s[0]=='C'){
				int a;
				scanf("%d",&a);
				printf("%d\n", query(1,1,t,stx[a]));
			}
			if(s[0]=='T'){
				int a,b;
				scanf("%d%d",&a,&b);
				update(1,1,t,stx[a],edx[a],b);
			}
		}
	}
	return 0;
}
