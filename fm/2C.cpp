#include<stdio.h>
#include<string.h>
#include<map>
#include<string>
#include<iostream>
using namespace std;

int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		map<string,int>m;
		int ans=0;
		while(n--){
			string a,b;
			cin>>a>>b;
			if(m[a]==0){
				ans++;
				m[a]=-1;
			}
			if(m[b]==0)m[b]++;
			else if(m[b]==-1){
				m[b]=1;
				ans--;
			}
		}
		if(ans==1)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
