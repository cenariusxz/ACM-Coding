#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxm=400010;

int st[(maxm<<2)+5],cnt=0;
ll a[55],num[maxm];
int l1,l2;
ll nl[100005],nr[100005];
int na[100005],nh[100005];
map<ll,int>m;
map<int,ll>m2;
int i,j;	
int cnt2=0;

void init(){
	a[0]=1;
	for(int i=1;i<=51;i++){
		a[i]=a[i-1]*2;
	}
}

void pushup(int o){
	if(st[o<<1]==0&&st[o<<1|1]==0)st[o]=0;
	else if(st[o<<1]==-1&&st[o<<1|1]==-1)st[o]=-1;
	else st[o]=1;
}

void pushdown(int o){
	if(st[o]==-1){
		st[o<<1]=-1;
		st[o<<1|1]=-1;
	}
}

void update(int o,int l,int r,int ql,int qr){
	if(st[o]==-1)return;
	if((ql<=l&&qr>=r)){
		st[o]=-1;
		return;
	}
	pushdown(o);
	int m=l+((r-l)>>1);
	if(ql<=m)update(o<<1,l,m,ql,qr);
	if(qr>=m+1)update(o<<1|1,m+1,r,ql,qr);
	pushup(o);
}

int query(int o,int l,int r){
	if(st[o]==-1)return -1;
	if(l==r)return l;
	pushdown(o);
	int m=l+((r-l)>>1);
	int ans1=query(o<<1,l,m),ans2=query(o<<1|1,m+1,r);
	if(ans1==-1&&ans2==-1)return -1;
	if(ans1==-1)return ans2;
	if(ans2==-1)return ans1;
	return 0;
}


int main(){
	int h,q;
	init();
	scanf("%d%d",&h,&q);
	num[++cnt]=a[h-1];
	num[++cnt]=a[h]-1;
	if(h>=2){
		num[++cnt]=num[1]+1;
		num[++cnt]=num[2]-1;

	}
	for(i=1;i<=q;i++){
		scanf("%d%I64d%I64d%d",&nh[i],&nl[i],&nr[i],&na[i]);
		nl[i]=a[h-nh[i]]*nl[i];
		nr[i]=a[h-nh[i]]*(nr[i]+1)-1;
		nh[i]=h;
		if(nl[i]>num[1]&&nl[i]<num[2]){
			num[++cnt]=nl[i];
			num[++cnt]=nl[i]-1;
		}
		if(nr[i]>num[1]&&nr[i]<num[2]){
			num[++cnt]=nr[i];
			num[++cnt]=nr[i]+1;
		}
	}
	sort(num+1,num+cnt+1);
	for(i=1;i<=cnt;i++){
		if(!m[num[i]]){
			m[num[i]]=++cnt2;
			m2[cnt2]=num[i];
		}
	}
	for(i=1;i<=q;i++){
		l1=m[nl[i]],l2=m[nr[i]];
		if(na[i]){
			if(l1>1){
				update(1,1,cnt2,1,m[nl[i]-1]);
			}
			if(l2<cnt2){
				update(1,1,cnt2,m[nr[i]+1],cnt2);
			}
		}
		else{
			update(1,1,cnt2,l1,l2);
		}
	}
	int ans=query(1,1,cnt2);
	if(ans==-1)printf("Game cheated!\n");
	else if(ans==0)printf("Data not sufficient!\n");
	else{
		printf("%I64d\n",m2[ans]);
	}
	return 0;
}
