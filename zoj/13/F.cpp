#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int n,k,m;
int ans;

struct seg{
	int l,r;
	bool operator < (const seg a)const{
		if(l==a.l)return r<a.r;
		return l<a.l;
	}
}tmp[25],s[25],tmp2[25];
int vis[25],tail[25];
int cnt=0;

void Pre1(){
	sort(tmp+1,tmp+n+1);
	cnt=1;
	s[1].l=tmp[1].l;
	s[1].r=tmp[1].r;
	int pos=2;
	while(pos<=n){
		if(tmp[pos].l>s[cnt].r+1){
			cnt++;
			s[cnt].l=tmp[pos].l;
			s[cnt].r=tmp[pos].r;
		}
		else if(tmp[pos].r>s[cnt].r){
			s[cnt].r=tmp[pos].r;
		}
		pos++;
	}
	n=cnt;
}

void Pre2(){
	cnt=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		++cnt;
		int pos=i;
		int l,r;
		while(1){
			vis[pos]=1;
			l=s[i].l,r=s[pos].r;
			int len=r-l+1;
			int c=len/k;
			int p1=l+c*k,p2=l+(c+1)*k;
			if(pos<n&&p1<=r&&p2>=s[pos+1].l)pos++;
			else break;
		}
		int len=r-l+1;
		int c=len/k;
		if(len%k)++c;
		if(c>=m){
			tmp[cnt].l=l,tmp[cnt].r=l+m*k-1;
			m=0;
			return;
		}
		tmp[cnt].l=l,tmp[cnt].r=l+c*k-1;
		tail[cnt]=r;
		m-=c;
	}
	n=cnt;
}

int solve(){
	cnt=n;
	for(int i=1;i<=cnt;++i){
		tmp2[i]=tmp[i];
	}
	for(int i=1;i<=n;++i){
		if(vis[i]){
			++cnt;
			tmp2[cnt].l=tail[i];
			tmp2[cnt].r=tail[i]+k-1;
		}
	}
	sort(tmp2+1,tmp2+cnt+1);
	int cnt2=1;
	s[1].l=tmp[1].l;
	s[1].r=tmp[1].r;
	int pos=2;
	while(pos<=cnt){
		if(tmp2[pos].l>s[cnt2].r+1){
			cnt2++;
			s[cnt2].l=tmp2[pos].l;
			s[cnt2].r=tmp2[pos].r;
		}
		else if(tmp2[pos].r>s[cnt2].r){
			s[cnt2].r=tmp2[pos].r;
		}
		pos++;
	}
	int res=0;
	for(int i=1;i<=cnt2;++i)res+=s[i].r-s[i].l+1;
	return res;
}

void dfs(int now,int num){
	if(num==0){
		ans=max(ans,solve());
		return;
	}
	for(int i=now;i<=n;++i){
		vis[i]=1;
		dfs(i+1,num-1);
		vis[i]=0;
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&k,&m);
		for(int i=1;i<=n;++i)scanf("%d%d",&tmp[i].l,&tmp[i].r);
		Pre1();
		Pre2();
		if(!m){
			ans=0;
			for(int i=1;i<=cnt;++i)ans+=tmp[i].r-tmp[i].l+1;
			printf("%d\n",ans);
			continue;
		}
		m=min(m,n);
		ans=-1;
		memset(vis,0,sizeof(vis));
		dfs(1,m);
		printf("%d\n",ans);
	}
	return 0;
}
