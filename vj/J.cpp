#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

struct BN{
	string s;
	int len;
	BN():len(0){}
}pre,One,Zero;

char tmp[1005];
vector<int>v[100];

BN sub(BN a,BN b){
	memset(tmp,0,sizeof(tmp));
	int add=0;
	for(int i=0;i<b.len;++i){
		int num=(int)a.s[i]-add-b.s[i];
		if(num<0){
			num+=10;
			add=1;
		}
		else add=0;
		tmp[i]=num+'0';
	}
	for(int i=b.len;i<a.len;++i){
		int num=a.s[i]-'0'-add;
		if(num<0){
			num+=10;
			add=1;
		}
		else add=0;
		tmp[i]=num+'0';
	}
	for(int i=a.len-1;i>=0;--i){
		if(tmp[i]=='0')tmp[i]=0;
		else break;
	}
	int len=strlen(tmp);
	BN res;
	res.s=string(tmp);
	res.len=len;
	return res;
}

BN get(BN a){
	int len=(a.len+1)/2;
	memset(tmp,0,sizeof(tmp));
	for(int i=0;i<len;++i){
		tmp[i]=a.s[i+a.len-len];
	}
	BN num;
	num.s=string(tmp);
	num.len=len;
	num=sub(num,One);
	memset(tmp,0,sizeof(tmp));
	bool f=1;
	for(int i=0;i<num.len;++i){
		tmp[a.len-len+i]=num.s[i];
		if(num.s[i]!='9')f=0;
	}
	if(f){
		for(int i=0;i<=a.len-len+num.len-1;++i){
			tmp[i]='9';
		}
	}
	else{
		int l=0,r=a.len-len+num.len-1;
		while(l<r){
			tmp[l]=tmp[r];
			l++;r--;
		}
	}
	num.s=string(tmp);
	num.len=strlen(tmp);
	return num;
}

void init(){
	tmp[0]='1';
	tmp[1]=0;
	One.s=string(tmp);
	One.len=1;
	tmp[0]='0';
	Zero.s=string(tmp);
	Zero.len=0;
	v[0].clear();
	for(int i=1;i<=99;++i){
		v[i].clear();
		int tmp=i;
		while(tmp>10){
			int num=tmp/10;
			num=num*11;
			if(num>tmp)num-=11;
			v[i].push_back(num);
			tmp-=num;
		}
		if(tmp==10){
			v[i].push_back(1);
			v[i].push_back(9);
		}
		else if(tmp>0){
			v[i].push_back(tmp);
		}
	}
}

vector<BN>ans;

int main(){
	int T;
	init();
	scanf("%d",&T);
	for(int q=1;q<=T;++q){
		scanf("%s",tmp);
		int l=0,r=strlen(tmp)-1;
		while(l<r){
			swap(tmp[l],tmp[r]);
			l++;r--;
		}
		pre.s=string(tmp);
		pre.len=strlen(tmp);
		pre=sub(pre,Zero);
//		printf("%s\n",pre.s.c_str());
		ans.clear();
		while(pre.len>2){
			BN res=get(pre);
			ans.push_back(res);
			pre=sub(pre,res);
//			for(int i=pre.len-1;i>=0;--i){
//				putchar(pre.s[i]);
//			}
//			printf("\n");
		}
		int p=0;
		for(int i=pre.s.length()-1;i>=0;--i){
			p=p*10+pre.s[i]-'0';
		}
		int num=ans.size()+v[p].size();
		printf("Case #%d:\n",q);
		printf("%d\n",num);
		for(int i=0;i<ans.size();++i){
			for(int j=ans[i].s.length()-1;j>=0;--j){
				putchar(ans[i].s[j]);
			}
			printf("\n");
		}
		for(int i=0;i<v[p].size();++i){
			printf("%d\n",v[p][i]);
		}
	}
	return 0;
}
