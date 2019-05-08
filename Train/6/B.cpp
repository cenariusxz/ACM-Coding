#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;

int xx[30]={0,2,3,4,5,6,1,2,3,4,5,6,7,1,2,3,4,5,6,7,1,2,3,4,5,6,7},
	yy[30]={0,4,4,4,4,4,3,3,3,3,3,3,3,2,2,2,2,2,2,2,1,1,1,1,1,1,1};
string ss1[7][5]={
	{},
	{"","TU","MN","FG","A"},
	{"","UV","NO","GH","AB"},
	{"","VW","OP","HI","BC"},
	{"","WX","PQ","IJ","CD"},
	{"","XY","QR","JK","DE"},
	{"","YZ","RS","KL","E"}
};
string ss2[5][8]={
	{},
	{"","MT","NU","OV","PW","QX","RY","SZ"},
	{"","FM","GN","HO","IP","JQ","KR","LS"},
	{"","F","AG","BH","CI","DJ","EK","L"}
};


string f(int a,int b)
{
	double k1=(double)(yy[a]-yy[b])/(xx[a]-xx[b]);
	double k2=(double)(xx[a]-xx[b])/(yy[a]-yy[b]);
	string res="";
	int i;
	if(fabs(xx[a]-xx[b])>eps)
	for(i=1;i<=6;i++){
		double x=i+0.5;
		double y=k1*(x-xx[a])+yy[a];
		int tmp=y-0.5;
		if(fabs(y-0.5-tmp)<eps||fabs(y-0.5-tmp-1)<eps) continue;
		tmp=y+0.5;
		res+=ss1[i][tmp];
	}
	if(fabs(yy[a]-yy[b])>eps)
	for(i=1;i<=3;i++){
		double y=i+0.5;
		double x=k2*(y-yy[a])+xx[a];
		int tmp=x-0.5;
		if(fabs(x-0.5-tmp)<eps||fabs(x-0.5-tmp-1)<eps) continue;
		tmp=x+0.5;
		res+=ss2[i][tmp];
	}
	sort(res.begin(),res.end());
	string tmp;
	for(int i=1;i<res.length();++i){
		if(res[i]!=res[i-1]){
			tmp+=res[i];
		}
	}
	return tmp;
}

int main()
{
	int i;
	char s[10];
	scanf("%s",s);
	cout<<f(s[0]-'a'+1,s[1]-'a'+1);	
 return 0;
}
