#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;
string s;
int n; 
string mini="~~~~"; 
vector<string>vec;
int main(){
	scanf("%d",&n);cin>>s;
//	s.erase(s.size()-1);
	for(int i=1;i<=n;i++){
		string t="";
		for(int j=n-i;j<n;j++)t+=s[j];
		for(int j=0;j<n-i;j++)t+=s[j];
		int k='9'-t[0]+1;
		for(int i=0;i<n;i++){
			t[i]=t[i]+k;
			if(t[i]>'9')t[i]-=10;
		}
		mini=min(mini,t);
//		cout<<t<<endl;
	}
	cout<<mini<<endl;
//	cout<<s<<endl;
	return 0;
}


