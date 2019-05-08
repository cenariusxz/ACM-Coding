#include<stdio.h>
#include<string.h>
const int maxm=5e4+5;

int head[maxm],nxt[maxm],point[maxm],size;
bool f[maxm];
int t,stx[maxm],edx[maxm];
int st[maxm<<2],ch[maxm<<2];

void add(int a,int b){
	point[size]=a;
	nxt[size]=head[b];
	head[b]=size++;
}

void dfs(int s){
	stx[s]=++t;
	for(int i=head[s];~i;i=nxt[i]){
		int j=point[i];
		dfs(j);
	}
	edx[s]=t;
}

void pushdown(int o){
	if(ch[o]!=-1){
		ch[o<<1]=ch[o];
		ch[o<<1|1]=ch[o];
		st[o<<1]=ch[o];
		st[o<<1|1]=ch[o];
		ch[o]=-1;
	}
}

void pushup(int o){
	if(st[o<<1]==st[o<<1|1])st[o]=st[o<<1];
	else st[o]=-2;
}

void update(int o,int l,int r,int ql,int qr,int c){
	if(ql<=l&&qr>=r){
		ch[o]=c;
		st[o]=c;
		return;
	}
	pushdown(o);
	int m=l+((r-l)>>1);
	if(ql<=m)update(o<<1,l,m,ql,qr,c);
	if(qr>=m+1)update(o<<1|1,m+1,r,ql,qr,c);
	pushup(o);
}

int query(int o,int l,int r,int ind){
	if(st[o]!=-2)return st[o];
	if(l==r)return st[o];
	pushdown(o);
	int m=l+((r-l)>>1);
	if(ind<=m)return query(o<<1,l,m,ind);
	return query(o<<1|1,m+1,r,ind);
}

char s[10];

int main(){
	int T,cnt=0;
	scanf("%d",&T);
	while(T--){
		memset(head,-1,sizeof(head));
		size=0;
		memset(f,0,sizeof(f));
		t=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<n;++i){
			int a,b;
			scanf("%d%d",&a,&b);
			f[a]=1;
			add(a,b);
		}
		for(int i=1;i<=n;++i){
			if(!f[i]){
				dfs(i);
				break;
			}
		}
	//	for(int i=1;i<=n;++i)printf("%d %d %d\n",i,stx[i],edx[i]);
		memset(st,-1,sizeof(st));
		memset(ch,-1,sizeof(ch));
		printf("Case #%d:\n",++cnt);
		int m;
		scanf("%d",&m);
		for(int i=1;i<=m;++i){
			scanf("%s",s);
			if(s[0]=='C'){
				int a;
				scanf("%d",&a);
				printf("%d\n",query(1,1,t,stx[a]));
			}
			else if(s[0]=='T'){
				int a,b;
				scanf("%d%d",&a,&b);
				update(1,1,t,stx[a],edx[a],b);
			}
		}
	}
	return 0;
}
