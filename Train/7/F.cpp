#include<bits/stdc++.h>
#define MAXN 120010
#define INF 1e20
using namespace std;
const double eps=1e-8;
struct node{
	double x,y,z;
	int index;
	node(double _x=0,double _y=0,double _z=0,int _index=0){
		double l=sqrt(_x*_x+_y*_y+_z*_z);
		x=_x/l;y=_y/l;z=_z/l;
		index=_index;
	}
}v[MAXN],tmp[MAXN];
struct node2{
	int a,b;
	double d;
};
int m,n,S,W,a,b;
int x[MAXN],y[MAXN],z[MAXN];

bool cmpz(const node& x,const node& y)
{
	return x.z<y.z;
}

bool cmpy(const node& x,const node& y)
{
	return x.y<y.y;
}

bool cmpx(const node& x,const node& y)
{
	return x.x<y.x;
}

double cal_angle(const node& x,const node &y)
{
	double tt=x.x*y.x+x.y*y.y+x.z*y.z;
	if(tt>=1.0) return INF;
	return acos(tt);
}

node2 cloest(int l,int r)
{
	int m=(l+r)>>1;
	node2 t;
	t.d=INF;
	if(l==r) return t;
	if(l+1==r){
		t.d=cal_angle(v[l],v[r]);
		t.a=v[l].index;t.b=v[r].index;
		return t;
	}
	node2 t1=cloest(l,m);
	node2 t2=cloest(m+1,r);
	t=t1.d<t2.d?t1:t2;
	int cnt=0;
	for(int i=l;i<=r;i++){
		if(cal_angle(v[m],node(v[m].x,v[m].y,v[i].z))<=t.d)
			tmp[++cnt]=v[i];
	}
	//sort(tmp+1,tmp+1+cnt,cmpx);
	for(int i=1;i<=cnt;i++)
		for(int j=i+1;j<=cnt;j++){
			double d=cal_angle(tmp[i],tmp[j]);
			if(d<t.d){
				t.d=d;t.a=tmp[i].index;t.b=tmp[j].index;
			}
		}
	return t;
}

void fuck()
{
	int i;
	n+=m;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
	}
	int g=S;
	for(i=m+1;i<=n;i++){
		x[i]=(g/7)    %100+1;
		y[i]=(g/700)  %100+1;
		z[i]=(g/70000)%100+1;
		if(g%2==0) g=g/2;
		else g=(g/2)^W;
	}
	for(i=1;i<=n;i++){
		v[i].index=i;
		v[i].x=x[i];v[i].y=y[i];v[i].z=z[i];
		double l=sqrt(v[i].x*v[i].x+v[i].y*v[i].y+v[i].z*v[i].z);
		v[i].x/=l;
		v[i].y/=l;
		v[i].z/=l;
	}
	sort(v+1,v+n+1,cmpz);
	node2 ans=cloest(1,n);
	if(ans.a>ans.b) swap(ans.a,ans.b);
	printf("%d %d %d %d %d %d\n",x[ans.a],y[ans.a],z[ans.a],x[ans.b],y[ans.b],z[ans.b]);
}

int main()
{
	while(~scanf("%d%d%d%d",&m,&n,&S,&W)&&(m+n+S+W))
		fuck();
 return 0;
}
