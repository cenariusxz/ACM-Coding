#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],x,t;
void in() {
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
}
int bfind(int L,int R,long long X) {
	while(L<=R) {
		int mid=(L+R)/2;
		if(a[mid]==X)return mid;
		if(a[mid]>X)R=mid-1;
		if(a[mid]<X)L=mid+1;
	}
	if(R<=0)return L;//³ö×ó±ß½×
	if(L>n)return R;//³öÓÒ±ß½×
	if(x-a[R]<=a[L]-x)return R;
	else return L;
}
void out() {
	cin>>t;
	for(int i=1; i<=t; i++) {
		cin>>x;
		long long j=bfind(1,n,x);
		cout<<a[j]<<endl;
	}
}
int main() {
	in();
	out();
	return 0;
}
