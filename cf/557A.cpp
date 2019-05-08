#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int l[4],r[4];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=3;i++)scanf("%d%d",&l[i],&r[i]);
	int ans1=l[1],ans2=l[2],ans3=l[3];
	int sum=ans1+ans2+ans3;
	if(sum<n){
		if(sum+r[1]-l[1]<n){
			ans1=r[1];
			sum=ans1+ans2+ans3;
			if(sum+r[2]-l[2]<n){
				ans2=r[2];
				sum=ans1+ans2+ans3;
				if(sum+r[3]-l[3]<n){
					ans3=r[3];
					sum=ans1+ans2+ans3;
				}
				else{
					ans3=n-ans1-ans2;
					sum=ans1+ans2+ans3;
				}
			}
			else{
				ans2=n-ans1-ans3;
				sum=n;
			}
		}
		else{
			ans1=n-ans2-ans3;
			sum=n;
		}
	}
	printf("%d %d %d\n",ans1,ans2,ans3);
	return 0;
}
