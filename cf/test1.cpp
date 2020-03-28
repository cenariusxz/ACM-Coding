#include<bits/stdc++.h>
using namespace std;
int n,m;
string ans;
int main(){
	cin>>m>>n;
	int t=n+m;
	while(n>0&&m>0){
		ans+="11";
		n-=2;
		ans+="0";
		m--;
	}
	if(n==-1){
		ans[t]='2';
	}
	if(m==1){
		ans+="0";
		m=0;
	}
	if(n>0||m>0){
		cout<<"-1";
	}else
	{
		int k=0;
		while(ans[k]!='2'){
			cout<<ans[k];
			k++;
		}
	}
	return 0;
}

