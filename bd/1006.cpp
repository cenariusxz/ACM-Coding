#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define PR 1e-8
#define N 1010*4
#define maxdouble 1e20
struct TPoint
{
	double x,y;
};
struct TPolygon
{
	int n;
	TPoint p[N];
}ply;
double MIN(double a,double b) {return a>b?b:a;}
int dblcmp(double a)
{
	if(fabs(a)<PR) return 0;
	return a>0?1:-1;
}
double dist(TPoint a,TPoint b)//距离
{
	double s1=a.x-b.x;
	double t1=a.y-b.y;
	return sqrt(s1*s1+t1*t1);
}
double cross(TPoint a,TPoint b,TPoint c)//叉积
{
	double s1=b.x-a.x;
	double t1=b.y-a.y;
	double s2=c.x-a.x;
	double t2=c.y-a.y;
	return s1*t2-s2*t1;
}
double dot(TPoint a,TPoint b,TPoint c)//点积
{
	double s1=b.x-a.x;
	double t1=b.y-a.y;
	double s2=c.x-a.x;
	double t2=c.y-a.y;
	return s1*s2+t1*t2;
}
bool cmop(TPoint a,TPoint b)//x、y排序
{
	if(fabs(a.x-b.x)<PR) return a.y<b.y;
	else return a.x<b.x;
}
bool cmp(TPoint a,TPoint b)//叉积内排序
{
	int d1=dblcmp(cross(ply.p[0],a,b));
	return d1>0||(d1==0&&dist(ply.p[0],a)<dist(ply.p[0],b));
}
TPolygon graham()//求凸包
{
	int i,top=2;
	for(i=2;i<ply.n;i++)
	{
		while(top>1&&(dblcmp(cross(ply.p[top-2],ply.p[i],ply.p[top-1])))>=0) top--;
		ply.p[top++]=ply.p[i];
	}
	ply.n=top;
	return ply;
}
double solve()
{
	int i,p=1,q=1,r;
	double minarea=maxdouble,area;
	ply.p[ply.n]=ply.p[0];
	for(i=0;i<ply.n;i++)
	{
		while(dblcmp(cross(ply.p[i],ply.p[i+1],ply.p[p+1])//最上一点
					-cross(ply.p[i],ply.p[i+1],ply.p[p]))>0)
			p=(p+1)%ply.n;
		while(dblcmp(dot(ply.p[i],ply.p[i+1],ply.p[q+1])//最右一点
					-dot(ply.p[i],ply.p[i+1],ply.p[q]))>0)
			q=(q+1)%ply.n;
		if(i==0) r=q;
		while(dblcmp(dot(ply.p[i],ply.p[i+1],ply.p[r+1])//最左一点
					-dot(ply.p[i],ply.p[i+1],ply.p[r]))<=0)
			r=(r+1)%ply.n;
		double d=dist(ply.p[i],ply.p[i+1])*dist(ply.p[i],ply.p[i+1]);
		area=cross(ply.p[i],ply.p[i+1],ply.p[p])* //求面积
			(dot(ply.p[i],ply.p[i+1],ply.p[q])-dot(ply.p[i],ply.p[i+1],ply.p[r]))/d;
		minarea=MIN(area,minarea);//更新
	}
	return minarea;
}
int main()
{
	int T,cnt=0;
	scanf("%d",&T);
	while(T--)
	{
		int i;
		double area;
		scanf("%d",&ply.n);
		ply.n*=4;
		for(i=0;i<ply.n;i++) scanf("%lf%lf",&ply.p[i].x,&ply.p[i].y);
		sort(ply.p,ply.p+ply.n,cmop);//排序
		sort(ply.p+1,ply.p+ply.n,cmp);
		ply=graham();//凸包
		if(ply.n<3) area=0;
		else area=solve();
		printf("Case #%d:\n%.0lf\n",++cnt,area);
	}
	return 0;
}
