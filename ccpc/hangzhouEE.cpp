#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int lim[10]={0,16,15,14,13,12,11,10,9,8};
int num[10],sum[10];
int p[36][10];
int equ[36][3]={
	{1,1,2},
	{1,2,3},
	{1,3,4},
	{1,4,5},
	{1,5,6},
	{1,6,7},
	{1,7,8},
	{1,8,9},
	{2,1,3},
	{2,2,4},
	{2,3,5},
	{2,4,6},
	{2,5,7},
	{2,6,8},
	{2,7,9},
	{3,1,4},
	{3,2,5},
	{3,3,6},
	{3,4,7},
	{3,5,8},
	{3,6,9},
	{4,1,5},
	{4,2,6},
	{4,3,7},
	{4,4,8},
	{4,5,9},
	{5,1,6},
	{5,2,7},
	{5,3,8},
	{5,4,9},
	{6,1,7},
	{6,2,8},
	{6,3,9},
	{7,1,8},
	{7,2,9},
	{8,1,9}
};
int id[37];

void init(){
	memset(p,0,sizeof(p));
	for(int i=0;i<36;++i){
		for(int j=0;j<3;++j){
			p[i][equ[i][j]]++;
		}
	}
	for(int i=0;i<36;++i)id[i]=i;
}

int ans;

int main(){
	int T;
	init();
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		int cnt=0;
		for(int i=1;i<=9;++i){
			scanf("%d",&num[i]);
			if(num[i]>=lim[i])num[i]=lim[i],cnt++;
		}
		if(cnt==9){
			printf("Case #%d: %d\n",q,36);
		}
		else{
			ans=0;
			for(int k=1;k<=1000;++k){
				int tmp=0,pos;
				random_shuffle(id,id+36);
				for(int i=1;i<=9;++i)sum[i]=num[i];
				for(int i=0;i<36;++i){
					if(tmp+36-i<=ans)break;
					bool f=1;
					pos=id[i];
					for(int j=1;j<=9;++j)if(p[pos][j]>sum[j])f=0;
					if(f){
						for(int j=1;j<=9;++j)sum[j]-=p[pos][j];
						tmp++;
					}
				}
				if(tmp>ans)ans=tmp;
			}
			printf("Case #%d: %d\n",q,ans);
		}
	}
	return 0;
}
