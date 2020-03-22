#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,k;
char s[maxn];
stack<int> stk;
int vis[maxn],a[maxn];
int main(){
	cin>>n>>k;
	scanf("%s",s);
	k = n-k;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			stk.push(i);
		}else
		{
			if(k>0){
				int idx=stk.top();
				stk.pop();
				s[i]='#';
				s[idx]='#';
				k-=2;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]!='#'){
			cout<<s[i];
		}
	}
	return 0;
}

