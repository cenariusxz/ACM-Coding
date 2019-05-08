#include<stdio.h>
#include<string.h>
#include<set>
using namespace std;
#define ll long long

ll a[1000005];

int main(){
	int T;
	while(scanf("%d",&T)!=EOF){
		for(int q=1;q<=T;q++){
			bool f=0;
			ll s=0;
			int n,i,k;
			scanf("%d%d",&n,&k);
			set<ll>hash1;
			set<ll>hash2;
			hash1.insert(0);
			hash2.insert(0);
			for(i=0;i<n&&!f;i++){
				scanf("%I64d",&a[i]);
				if(i%2)s-=a[i];
				else s+=a[i];
				hash1.insert(s);
				hash2.insert(-s);
				if(hash1.count(s-k))f=1;
				if(hash2.count(-s-k))f=1;
			}
			if(f)printf("Case #%d: Yes.\n",q);
			else printf("Case #%d: No.\n",q);
		}
	}
	return 0;
}
