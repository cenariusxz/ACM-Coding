#include<stdio.h>
#include<map>
using namespace std;

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		map<int,int>m;
		int ans=0,tmp=0;
		for(int i=1;i<=n;++i){
			int a;
			scanf("%d",&a);
			m[a]++;
			if(m[a]>ans){
				ans=m[a];
				tmp=a;
			}
		}
		printf("%d\n",tmp);
	}
	return 0;
}
