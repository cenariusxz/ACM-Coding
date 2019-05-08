#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;

struct peo{
	int f,t;
	bool operator < (const peo a)const{
		if(f==a.f)return t<a.t;
		return f>a.f;
	}
}p[105];

int main(){
	int n,s;
	scanf("%d%d",&n,&s);
	int ans=s;
	for(int i=1;i<=n;++i){
		scanf("%d%d",&p[i].f,&p[i].t);
		if(p[i].f+p[i].t>ans)ans=p[i].f+p[i].t;
	}
//	int t=0,pre=s;;
	printf("%d\n",ans);
	return 0;
}
