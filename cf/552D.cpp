#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;

int x[2005],y[2005];

int main(){
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	int ans=0;
	for(i=1;i<=n;i++){
		map<double,int>m;
		m.clear();
		for(j=i+1;j<=n;j++){
			if(x[i]==x[j])m[1000]++;
			else m[(y[i]*1.0-y[j])/(x[i]*1.0-x[j])]++;
		}
		map<double,int>::iterator it;
		int tmp=0;
		for(it=m.begin();it!=m.end();++it){
			tmp+=(it->second)*(n-i-it->second);
		}
		tmp/=2;
		ans+=tmp;
	}
	printf("%d\n",ans);
	return 0;
}
