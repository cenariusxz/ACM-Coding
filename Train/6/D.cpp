#include<stdio.h>
#include<string.h>
#include<map>
//#include<hash_map>
#include<algorithm>
#include<math.h>
using namespace std;

typedef long long ll;
const int maxn=1000;

ll L;
int cnt=0,len[2],n[2];
//map<ll,ll>m[2];
//map<ll,ll>::iterator it1,it2;

struct box{
	ll d,c;
	bool operator < (const box a)const{
		if(d==a.d)return c<a.c;
		return d<a.d;
	}
}a[200],M[2][2000000];

void change(){
	cnt=0;
	for(int q=1;q<=5;++q){
		ll h,d,c;
		scanf("%lld%lld%lld",&h,&d,&c);
		int sub=1;
		while(1){
			if(sub<=h){
				++cnt;
				a[cnt].d=d*sub;
				a[cnt].c=c*sub;
				h-=sub;
				sub<<=1;
			}
			else break;
		}
		if(h){
			++cnt;
			a[cnt].d=d*h;
			a[cnt].c=c*h;
		}
	}
}

void dfs(int lim,int now,ll d,ll c,int x){
	if(now>lim){
	/*	if(m[x].find(d)!=m[x].end()){
			if(c<m[x][d]){
				m[x][d]=c;
			}
		}
		else m[x][d]=c;*/
		len[x]++;
		M[x][len[x]].d=d;
		M[x][len[x]].c=c;
		return;
	}
	dfs(lim,now+1,d,c,x);
	dfs(lim,now+1,d+a[now].d,c+a[now].c,x);
}

void get(){
	int num=(cnt+1)/2;
	len[0]=len[1]=0;
	dfs(num,1,0,0,0);
	dfs(cnt,num+1,0,0,1);
	sort(M[0]+1,M[0]+len[0]+1);
	sort(M[1]+1,M[1]+len[1]+1);
	n[0]=n[1]=1;
	for(int i=2;i<=len[0];++i){
		if(M[0][i].d!=M[0][i-1].d)M[0][++n[0]]=M[0][i];
	}
	for(int i=2;i<=len[1];++i){
		if(M[1][i].d!=M[1][i-1].d)M[1][++n[1]]=M[1][i];
	}
}
/*
void Init(){
	m[0].clear();
	m[1].clear();
}*/

void Solve(){
	ll res_d = 0,res_c = 1LL << 60;
//	it2 = m[1].end(); it2--;
	int it1=1;
	int it2=n[1];
	ll min_cost = 1LL << 60,min_cd=0;
/*	for(it1 = m[0].begin(); it1 != m[0].end(); it1++){
		while((*it1).first + (*it2).first >= L){
			if((*it2).second < min_cost){
				min_cost = (*it2).second;
				min_cd = (*it2).first;
			}
			else if((*it2).second == min_cost){
				min_cd = (*it2).first;
			}
			if(it2 != m[1].begin()){
				it2--;
			}
			else break;
		}
		if((*it1).second + min_cost < res_c){
			res_c = (*it1).second + min_cost;
			res_d = (*it1).first  + min_cd;
		}
	}*/
	for(it1=1;it1<=n[0];it1++){
		while(M[0][it1].d+M[1][it2].d>=L){
			if(M[1][it2].c<min_cost){
				min_cost=M[1][it2].c;
				min_cd=M[1][it2].d;
			}
			else if(M[1][it2].c==min_cost){
				min_cd=M[1][it2].d;
			}
			if(it2>1)it2--;
			else break;
		}
		if(M[0][it1].c+min_cost < res_c){
			res_c = M[0][it1].c + min_cost;
			res_d = M[0][it1].d + min_cd;
		}

	}
	printf("%lld %lld\n",res_c,res_d);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
//		Init();
		scanf("%lld",&L);
		change();
		ll sum=0;
		for(int i=1;i<=cnt;++i){
			sum+=a[i].d;
		}
		if(sum<L)printf("We are doomed!!\n");
		else if(cnt==1){
			printf("%lld %lld\n",a[1].c,a[1].d);
		}
		else{
			get();
			Solve();
		}
	}
	return 0;
}
