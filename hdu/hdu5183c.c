#include<stdio.h>
#include<string.h>
#define ll long long

const int MAXM=1000007;
ll a[MAXM];

ll read(){
	ll f=1,x=0;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

struct HashMap{
	int next[MAXM],head[MAXM],size;
	ll state[MAXM];
	void init(){
		size=0;
		memset(head,-1,sizeof(head));
	}
	bool check(ll val){
		int h=(val%MAXM+MAXM)%MAXM;
		for(int i=head[h];~i;i=next[i]){
			if(state[i]==val)return 1;
		}
		return 0;
	}
	bool insert(ll val){
		int h=(val%MAXM+MAXM)%MAXM;
		for(int i=head[h];~i;i=next[i]){
			if(state[i]==val)return 1;
		}
		state[size]=val;
		next[size]=head[h];
		head[h]=size++;
		return 0;
	}
}H1,H2;

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		for(int q=1;q<=T;q++){
			H1.init();
			H1.insert(0);
			H2.init();
	//		H2.insert(0);
			int n,k;
			n=read();
			k=read();
			int i;
			ll s=0;
			bool f=0;
			for(i=0;i<n;i++) a[i]=read();
			for(i=0;i<n&&!f;i++){
				if(i&1){
					s-=a[i];/*
					if(H1.check(s-k)){
						f=1;
					}
					H1.insert(s);*/
				}
				else{
					s+=a[i];/*
					if(H2.check(-s-k)){
						f=1;
					}
					H2.insert(-s);*/
				}
				if(H1.check(s-k)||H2.check(-s-k))f=1;
				if(i&1){
					H1.insert(s);
				}
				else H2.insert(-s);
			}
			if(f)printf("Case #%d: Yes.\n",q);
			else printf("Case #%d: No.\n",q);
		}
	}
	return 0;
}
