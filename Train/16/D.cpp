#include <bits/stdc++.h>
using namespace std;

int b[]={119,18,93,91,58,107,111,82,127,123};
struct node{
	int t[5];
	node(){
		memset(t,0,sizeof(t));
	}
	void go(){
		t[4]++;
		if(t[4]<10) return;
		t[4]=0;t[3]++;
		if(t[3]<6) return;
		t[3]=0;t[2]++;
		if(t[1]==2&&t[2]==4){
			memset(t,0,sizeof(t));
			return;
		}
		if(t[2]<10) return;
		t[2]=0;t[1]++;
	}
	void print(){
		printf("%d%d:%d%d",t[1],t[2],t[3],t[4]);
	}
	int extract(){
		return b[t[1]]|(b[t[2]]<<7)|(b[t[3]]<<14)|(b[t[4]]<<21);
	}
}a[55];
int n;

void fuck()
{
	int i,t,A,B;
	int hao,huai;
	vector<node> ans;
	node x,xx;
	for(i=1;i<=n;i++)
		scanf("%1d%1d:%1d%1d",&a[i].t[1],&a[i].t[2],&a[i].t[3],&a[i].t[4]);
	for(t=0;t<1440;t++){
		hao=huai=0;
		xx=x;
		for(i=1;i<=n;i++){
			A=xx.extract();
			B=a[i].extract();
			if((A|B)!=A) break;
			hao|=B;
			huai|=(A^B);
			//if(t==58) printf("%d %d\n",A,B);
			if(hao&huai) break;
			xx.go();
		}
		if(i>n) ans.push_back(x);
		x.go();
	}
	if(ans.size()==0){
		printf("none\n");
	}
	for(i=0;i<ans.size();i++){
		ans[i].print();
		if(i<ans.size()-1) printf(" ");
		else printf("\n");
	}
}

int main()
{
	while(~scanf("%d",&n))
		fuck();
 return 0;
}
