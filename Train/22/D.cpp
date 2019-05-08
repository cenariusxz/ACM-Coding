#include<bits/stdc++.h>
using namespace std;
char s1[30],s2[30];
long long h[30],a[30];

long long mod(long long n)
{
	int i;
	for(i=20;i>=0;i--){
		if((n^h[i])<n) n^=h[i];
	}
	return n;
}

long long mul(long long n)
{
	int i;
	long long res=0;
	for(i=0;i<=20;i++){
		if((1<<i)&n) res^=a[i];
	}
	return res;
}

long long tonum(char s[])
{
	long long tmp=1,res=0;
	int i,l=strlen(s+1);
	for(i=l;i>=1;i--){
		if(s[i]=='1') res+=tmp;
		tmp<<=1;
	}
	return res;
}

void fuck()
{
	int i,b;
	long long tmp;
	a[0]=tonum(s1);
	h[0]=tonum(s2);
	for(i=1;i<=20;i++) h[i]=(h[i-1]<<1);
	a[0]=mod(a[0]);
	for(i=1;i<=20;i++) a[i]=(a[i-1]<<1);
	for(b=1;b<=h[0];b++){
		tmp=mul(b);
		tmp=mod(tmp);
		if(tmp==1) break;
	}
	string ans="";
	i=0;
	while(b){
		if(b&1) ans+='1';
		else ans+='0';
		b>>=1;
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;
}

int main()
{
	while(~scanf("%s",s1+1)){
		if(s1[1]=='0') break;
		scanf("%s",s2+1);
		fuck();
	}
 return 0;
}
