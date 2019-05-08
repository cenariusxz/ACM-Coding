#include<stdio.h>
#include<string.h>

int a[1005],t;

void run(int l,int r,int m){
	int i,m1=0x3f3f3f3f,l1,r1;
	bool f=1;
	if(m>0)t++;
	for(i=l;i<=r;i++){
		a[i]-=m;
		if(f&&a[i]>0){
			l1=i;
			r1=i;
			m1=a[i];
			f=0;
		}
		else if(!f&&a[i]>0){
			r1=i;
			if(a[i]<m1)m1=a[i];
		}
		else if(!f&&a[i]==0){
			run(l1,r1,m1);
			f=1;
		}
		if(!f&&i==r){
			run(l1,r,m1);
		}
	}
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int i,m=0x3f3f3f3f;t=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]<m)m=a[i];
		}
		run(1,n,m);
		printf("%d\n",t);
	}
	return 0;
}
