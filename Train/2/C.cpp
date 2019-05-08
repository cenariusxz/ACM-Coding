#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;

struct node{
	ll num;
	int pos;
	bool operator<(const node x)const{
		if(num==x.num)return pos<x.pos;
		return num<x.num;
	}
	node(ll a,int b):num(a),pos(b){}
};

ll a[100005];
vector <node> v[2];

ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}


int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
		v[0].clear();
		v[1].clear();
		int now,pre;
		v[1].push_back(node(a[1],1));
		ll ans=a[1];
		for(int i=2;i<=n;++i){
			now=i&1;
			pre=now^1;
			v[now].clear();
			for(int j=0;j<v[pre].size();++j){
				v[now].push_back(node(gcd(v[pre][j].num,a[i]),v[pre][j].pos));
			}
			v[now].push_back(node(a[i],i));
			sort(v[now].begin(),v[now].end());
			v[pre].clear();
			for(int j=0;j<v[now].size();++j){
				if(j==0||v[now][j].num!=v[now][j-1].num){
					v[pre].push_back(v[now][j]);
					ans=max(ans,v[now][j].num*(i-v[now][j].pos+1));
				}
			}
			v[now]=v[pre];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
