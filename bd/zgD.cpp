#include<string.h>
#include<algorithm>
#include<iostream>
#include<string>
#include<math.h>
#include<stdio.h>
#include<map>
using namespace std;

const int maxn=1e5+5;

map<string,int>m;

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		string tmp;
		cin>>tmp;
		sort(tmp.begin(),tmp.end());
		printf("%d\n",m[tmp]);
		m[tmp]++;
	}
	return 0;
}
