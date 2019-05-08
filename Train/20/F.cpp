#include<bits/stdc++.h>
using namespace std;

long long fuck(long long n,bool x)
{
	//cout<<"  "<<n<<" "<<x<<endl;
	if(n<=5) return n*x;
	long long i,m=5,mm=5,last=5,curr=5;
	bool f=0,st=1;
	while(1){
		mm+=m;
		if(!f) st^=1;
		if(mm>n) break;
		if(f) curr+=last;
		else curr+=m-last;
		mm+=m;
		if(!f) st^=1;
		if(mm>n) break;
		curr+=last;
		mm+=m;
		if(!f) st^=1;
		if(mm>n) break;
		if(f) curr+=last;
		else curr+=m-last;
		mm+=m;
		if(!f) st^=1;
		if(mm>n) break;
		curr+=last;
		f^=1;st=1;
		m=mm;
		last=curr;
	}
	mm-=m;
	long long tmp=curr+fuck(n-mm,st);
	if(x) return tmp;
	else return n-tmp;
}

int main()
{
	long long n;
	while(cin>>n&&n!=-1)
		cout<<fuck(n+1,1)<<endl;
 return 0;
}
