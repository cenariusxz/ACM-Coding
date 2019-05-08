#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int a[305];
int c[905];

int lowbit(int x){return x&(-x);}
void change(int x,int v){
	while(x<=901){
		c[x]+=v;
		x+=lowbit(x);
	}
}
int sum(int x){
	int s=0;
	while(x){
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}
void update(int l,int r){
	change(l,1);
	change(r+1,-1);
}

int main(){
	int m,t,r,i,j;
	memset(c,0,sizeof(c));
	scanf("%d%d%d",&m,&t,&r);
	for(i=1;i<=m;i++){
		scanf("%d",&a[i]);
		a[i]+=300;
	}
	if(t<r){printf("-1\n");return 0;}
	sort(a+1,a+m+1);
	int ans=0;
	for(i=1;i<=m;i++){
		int s=sum(a[i]);
		if(s<r){
			int num=r-s;
	//		printf("%d\n",num);
			for(j=a[i]-num;j<=a[i]-1;j++){
				update(j+1,j+t);
				ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
