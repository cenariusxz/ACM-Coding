#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;

string a[3005];
int len[3005];
int cnt=0;

void init(){
	for(int i=2;i<=61;++i){
		for(int j=1;j<=i-1;++j){
			len[++cnt]=i;
			for(int k=1;k<=j;++k)a[cnt]+='1';
			a[cnt]+='0';
			for(int k=j+2;k<=i;++k)a[cnt]+='1';
		}
	}
}

int main(){
	init();
	ll num1,num2;
	scanf("%I64d%I64d",&num1,&num2);
	string s1,s2;
	int l1,l2;
	while(num1){
		char a=num1%2+'0';
		s1=a+s1;
		num1/=2;
	}
	while(num2){
		char a=num2%2+'0';
		s2=a+s2;
		num2/=2;
	}
	l1=s1.length();
	l2=s2.length();
	int ans=0;
	int pos=0;
	for(int i=1;i<=cnt;++i){
		if(len[i]>l1){
			pos=i;
			break;
		}
		else if(len[i]==l1&&a[i]>s1){
			pos=i;
			break;
		}
		else if(len[i]==l1&&a[i]==s1){
			pos=i;
			break;
		}
	}
	for(int i=pos;i<=cnt;++i){
		if(len[i]>l2){
			break;
		}
		else if(len[i]==l2&&a[i]>s2){
			break;
		}
		ans++;
	}
	printf("%d\n",ans);

	return 0;
}
