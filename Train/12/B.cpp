#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
typedef long long ll;

struct candle{
	ll num;
	int bit;
	vector<int>v;
	bool operator <(const candle a)const{
		if(bit==a.bit)return num<a.num;
		return bit<a.bit;
	}
}a[1050];

int vis[10];

void init(){
	for(int i=1;i<(1<<10);++i){
		for(int j=1;j<=105;++j){
			a[i].v.push_back(0);
		}
		for(int k=9;k>=0;--k){
			if(i&(1<<k)){
				a[i].bit++;
				a[i].num=a[i].num*10+k;
			}
		}
	}
	for(int i=1;i<=100;++i){
		
		for(int j=0;j<=9;++j)vis[j]=0;
		int tmp=i;
		while(tmp){
			int b=tmp%10;
			tmp/=10;
			vis[b]++;
		}
		int t=0;
		bool f=0;
		for(int j=9;j>=0;--j){
			if(vis[j]>1)f=1;
			else if(vis[j]==1)t+=(1<<j);
		}
		if(!f)a[t].v[i]=1;

		for(int j=1;j<=i/2;++j){
			for(int k=0;k<=9;++k)vis[k]=0;
			int tmp1=j,tmp2=i-j;
			while(tmp1){
				int b=tmp1%10;
				tmp1/=10;
				vis[b]++;
			}
			while(tmp2){
				int b=tmp2%10;
				tmp2/=10;
				vis[b]++;
			}
			t=0;f=0;
			for(int k=9;k>=0;--k){
				if(vis[k]>1)f=1;
				else if(vis[k]==1)t+=(1<<k);
			}
	//		if(i==10&&j==4)printf("f%d\n",t);
			if(!f)a[t].v[i]=1;

		}
	}
//	printf("%d\n",a[80].v[10]);
	
	for(int i=1;i<(1<<10);++i){
		for(int j=0;j<=9;++j){
			if(!(i&(1<<j))){
				int tmp=i+(1<<j);
				for(int k=1;k<=100;++k){
					if(a[i].v[k]==1)a[tmp].v[k]=1;
				}
			}
		}
	}

//	printf("%lld %d\n",a[112].num,a[112].bit);
//	printf("%d %d\n",a[112].v[10],a[112].v[11]);
	sort(a+1,a+1023+1);

}

int num[15];

int main(){
	int c=0,n;
	init();
	while(scanf("%d",&n)!=EOF&&n){
		c++;
		for(int i=1;i<=n;++i)scanf("%d",&num[i]);
		printf("Case %d: ",c);
		for(int i=1;i<(1<<10);++i){
			bool f=0;
			for(int j=1;j<=n;++j){
				if(!a[i].v[num[j]])f=1;
			}
			if(f)continue;
			else{
				printf("%lld\n",a[i].num);
				break;
			}
		}
	}
	return 0;
}
