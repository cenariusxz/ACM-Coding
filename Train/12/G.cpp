#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
	node(int _a=0,int _b=0,int _c=0){
		a=_a;b=_b;c=_c;
	}
};

vector<node> t;

void init()
{
	int i,j,k,tmp;
	for(i=1;i<=1000;i++)
		for(j=1;j<i;j++){
			tmp=sqrt(1.0*i*i+j*j);
			if(tmp*tmp==i*i+j*j)
				t.push_back(node(j,i,tmp));
		}
}

void fuck()
{
	int i,j,h,w,r1,r2;
	long long ans=0;
	scanf("%d%d",&h,&w);
	for(i=1;i<=1000;i++)
		for(j=1;j<=1000;j++){
			if(i*2>h||j*2>h||i*2+j*2>w) break;
			ans+=1ll*(h-max(i,j)*2+1)*(w-i*2-j*2+1);
		}
	for(i=1;i<=1000;i++)
		for(j=1;j<=1000;j++){
			if(i*2>w||j*2>w||i*2+j*2>h) break;
			ans+=1ll*(w-max(i,j)*2+1)*(h-i*2-j*2+1);
		}
	int x,y;
	//cout<<ans<<endl;
	for(auto it:t){
		x=it.a+it.c;y=it.b+it.c;
		if((x>h||y>w)&&(x>w||y>h)) continue;
		for(r1=1;r1<it.c;r1++){
			r2=it.c-r1;
			x=max(it.a+it.c,max(r1,r2)<<1);
			y=max(it.b+it.c,max(r1,r2)<<1);
			if(x<=w&&y<=h) ans+=(w-x+1)*(h-y+1)*2;
			if(x<=h&&y<=w) ans+=(h-x+1)*(w-y+1)*2;
		}
	}
	cout<<ans<<endl;
}

int main()
{
	init();
	//cout<<t.size()<<endl;
	//for(auto it:t) cout<<it.a<<" "<<it.b<<" "<<it.c<<endl;
	int i,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case %d: ",i);
		fuck();
	}
 return 0;
}
