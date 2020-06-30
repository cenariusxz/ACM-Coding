#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
string s[maxn],o[maxn];
int n,cn;
int main(){
	cin>>n;
	cn=100000;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	int len=s[0].size();
	string y=s[0]+s[0];
	for(int i=0;i<len;i++){
		o[i]=y.substr(i,len);
	}
	for(int i=0;i<len;i++){
		int ans=0;
		// zwoxz
		for(int j=0;j<n;j++){
			int u=0;
			string t=s[j]+s[j];
			for(int k=0;k<len;k++){
				string h=t.substr(k,len);
				
				if(o[i]!=h){
					ans++;
					if(o[i] == "zwoxz"){
						cout << h << endl;
					}
				}
				else break;
			}
		}
		cn=min(ans,cn);
	}
	cout<<cn;
	return 0;
}

