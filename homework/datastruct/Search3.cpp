#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
using namespace std;

const int maxn=1e6;

int n;
int a[2005];
int s1[maxn+5],s2[maxn+5];

void init(int n){
	for(int i=1;i<=n;++i){
		while(1){
			int tmp=rand()%maxn;
			bool f=0;
			for(int j=1;j<i&&!f;++j)if(tmp==a[j])f=1;
			if(!f){
				a[i]=tmp;
				break;
			}
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=maxn;++i){
		s1[i]=a[rand()%n+1];
	}
	for(int i=1;i<=maxn;++i){
		while(1){
			int tmp=rand()%maxn;
			int l=1,r=n;
			bool f=0;
			while(l<=r){
				int mid=l+((r-l)>>1);
				if(a[mid]>tmp)r=mid-1;
				else if(a[mid]<tmp)l=mid+1;
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

int BSearch(int l,int r,int num){
	if(l>r)return -1;
	int mid=l+((r-l)>>1);
	if(a[mid]>num)return BSearch(l,mid-1,num);
	if(a[mid]<num)return BSearch(mid+1,r,num);
	if(a[mid]==num)return mid;
}

int main(){
	printf("Please input the number of integer.\n");
	scanf("%d",&n);
	srand(time(NULL));
	init(n);
	int begin,end;
	int l,r,mid;

	begin=clock();
	for(int i=1;i<=maxn;++i){
		l=1,r=n;
		while(l<=r){
			mid=l+((r-l)>>1);
			if(a[mid]>s1[i])r=mid-1;
			else if(a[mid]<s1[i])l=mid+1;
			else if(a[mid]==s1[i])break;
		}
	}
	end=clock();
	double time1=(end-begin)/1e6;
	printf("%d个元素，循环二分查找成功1000000次所花时间： %.3lf\n",n,time1);

	begin=clock();
	for(int i=1;i<=maxn;++i){
		l=1,r=n;
		while(l<=r){
			mid=l+((r-l)>>1);
			if(a[mid]>s2[i])r=mid-1;
			else if(a[mid]<s2[i])l=mid+1;
			else if(a[mid]==s2[i])break;
		}
	}
	end=clock();
	double time2=(end-begin)/1e6;
	printf("%d个元素，循环二分查找失败1000000次所花时间： %.3lf\n",n,time2);

	begin=clock();
	for(int i=1;i<=maxn;++i){
		BSearch(1,n,s1[i]);
	}
	end=clock();
	double time3=(end-begin)/1e6;
	printf("%d个元素，递归二分查找成功1000000次所花时间： %.3lf\n",n,time3);

	begin=clock();
	for(int i=1;i<=maxn;++i){
		BSearch(1,n,s2[i]);
	}
	end=clock();
	double time4=(end-begin)/1e6;
	printf("%d个元素，递归二分查找失败1000000次所花时间： %.3lf\n",n,time4);

	return 0;
}
