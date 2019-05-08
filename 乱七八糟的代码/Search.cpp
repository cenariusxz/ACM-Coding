#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
using namespace std;

const int maxn=1e6;

int a[2005],b[2005];
int s1[maxn+5],s2[maxn+5];

void init(int n){
	for(int i=1;i<=n;++i){
		while(1){
			int tmp=rand()%maxn;
			bool f=0;
			for(int j=1;j<i&&!f;++j)if(tmp==a[j])f=1;
			if(!f){
				a[i]=b[i]=tmp;
				break;
			}
		}
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=maxn;++i){
		s1[i]=b[rand()%n+1];
	}
	for(int i=1;i<=maxn;++i){
		while(1){
			int tmp=rand()%maxn;
			int l=1,r=n;
			bool f=0;
			while(l<=r){
				int mid=l+((r-l)>>1);
				if(b[mid]>tmp)r=mid-1;
				else if(b[mid]<tmp)l=mid+1;
				else {
					f=1;
					break;
				}
			}
			if(!f){
				s2[i]=tmp;
				break;
			}
		}
	}
}

int main(){
	int n;
	printf("Please input the number of integer.\n");
	scanf("%d",&n);
	srand(time(NULL));
	init(n);
	int begin,end;
	begin=clock();
	for(int i=1;i<=maxn;++i){
		for(int j=1;j<=n&&a[j]!=s1[i];++j);
	}
	end=clock();
	double time1=(end-begin)/1e6;
	int count1=0;
	for(int i=1;i<=maxn;++i){
		for(int j=1;j<=n&&a[j]!=s1[i];++j,++count1);
	}
	printf("%d个元素，无序表顺序查找成功1000000次所花时间： %.3lf s，遍历元素个数： %.3lf 个\n",n,time1,count1*1.0/maxn);

	begin=clock();
	for(int i=1;i<=maxn;++i){
		for(int j=1;j<=n&&a[j]!=s2[i];++j);
	}
	end=clock();
	double time2=(end-begin)/1e6;
	int count2=0;
	for(int i=1;i<=maxn;++i){
		for(int j=1;j<=n&&a[j]!=s2[i];++j,++count2);
	}
	printf("%d个元素，无序表顺序查找失败1000000次所花时间： %.3lf s，遍历元素个数： %.3lf 个\n",n,time2,count2*1.0/maxn);

	begin=clock();
	for(int i=1;i<=maxn;++i){
		for(int j=1;j<=n&&b[j]<s1[i];++j);
	}
	end=clock();
	double time3=(end-begin)/1e6;
	int count3=0;
	for(int i=1;i<=maxn;++i){
		for(int j=1;j<=n&&b[j]<s1[i];++j,++count3);
	}
	printf("%d个元素，有序表比较查找成功1000000次所花时间： %.3lf s，遍历元素个数： %.3lf 个\n",n,time3,count3*1.0/maxn);

	begin=clock();
	for(int i=1;i<=maxn;++i){
		for(int j=1;j<=n&&b[j]<s2[i];++j);
	}
	end=clock();
	double time4=(end-begin)/1e6;
	int count4=0;
	for(int i=1;i<=maxn;++i){
		for(int j=1;j<=n&&b[j]<s2[i];++j,++count4);
	}
	printf("%d个元素，有序表比较查找失败1000000次所花时间： %.3lf s，遍历元素个数： %.3lf 个\n",n,time4,count4*1.0/maxn);

	return 0;
}
