#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5 + 5; 
int n,a[maxn],k;
int kuaixuan(int l,int r,int k){
	int pi=a[l],i=l,j=r;
	while(i<=j){
		while(a[i]<pi)i++;
		while(a[j]>pi)j--;
		if(i<=j){
			swap(a[i],a[j]);
			i++,j--;
		}
	}
	if(k<=j-l+1)return kuaixuan(l,j,k);
	else if(k<=i-l)return pi;
	else kuaixuan(i,r,k-(i-l));
}
int main(){
	n=7;
	a[1]=1;
	a[2]=0;
	a[3]=-2;
	a[4]=5;
	a[5]=7;
	a[6]=8;
	a[7]=3;
	for(int i=1;i<=n;++i){
		cout<<kuaixuan(1,n,i)<<" ";
	}
	cout<<endl;
} 

