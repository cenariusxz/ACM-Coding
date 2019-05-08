#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int num1[14],num2[14];
char s1[1005],s2[1005];

int main(){
	int n;
	scanf("%d",&n);
	scanf("%s%s",s1,s2);
	memset(num1,0,sizeof(num1));
	memset(num2,0,sizeof(num2));
	for(int i=0;i<n;++i){
		num1[s1[i]-'0']++;
		num2[s2[i]-'0']++;
	}
	int ans1=0,ans2=0;
	int tmp=0;
	for(int i=9;i>=0;--i){
		tmp+=num2[i];
		if(tmp>=num1[i])tmp-=num1[i];
		else{
			ans1+=num1[i]-tmp;
			tmp=0;
		}
	}
	printf("%d\n",ans1);
	tmp=num2[9];
	for(int i=8;i>=0;--i){
		if(tmp>=num1[i]){
			ans2+=num1[i];
			tmp-=num1[i];
		}
		else{
			ans2+=tmp;
			tmp=0;
		}
		tmp+=num2[i];
	}
	printf("%d\n",ans2);
}
