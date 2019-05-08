#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

string s,t;

bool f=0;
bool judge(string ss,string tt){
	if(ss==tt)return 1;
	int l=ss.length();
	if(l%2)return 0;
	return (
(judge(ss.substr(0,l/2),tt.substr(l/2,l/2)) &&
			 judge(ss.substr(l/2,l/2),tt.substr(0,l/2))
		||	(judge(ss.substr(0,l/2),tt.substr(0,l/2)) &&
			judge(ss.substr(l/2,l/2),tt.substr(l/2,l/2))))
		   );
}

int main(){
//	freopen("a.txt","r",stdin);
	cin>>s>>t;
	if(judge(s,t))printf("YES\n");
	else printf("NO\n");
	return 0;
}
