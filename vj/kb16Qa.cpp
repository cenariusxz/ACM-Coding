#include <iostream>
#include<string>
using namespace std;

#define N 1000100
int a[N],next[N];
int m;
string s;
void getNext(){
	next[0]=0;
	next[1]=0;
	for(int i=1;i<m;i++){
		int j=next[i];
		while(s.at(j)!=s.at(i)&&j) j=next[j];
		if(s.at(j)==s.at(i)) next[i+1]=j+1;
		else next[i+1]=0;
	}
}

int main()
{
	int T,count;
	cin.sync_with_stdio(false);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>s;
		m=s.length(),count=0;
		int t=m;
		getNext();

		while(next[m])
		{
			a[count++]=t-next[m];
			m=next[m];
		}

		cout<<"Case #"<<i<<": "<<count+1<<endl;
		for(int i=0;i<count;i++) cout<<a[i]<<' ';
		cout<<t<<endl;
	}
	return 0;
}
