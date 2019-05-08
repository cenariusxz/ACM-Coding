#include <stdio.h>
#include <set>

using namespace std;

const int MAXN = 32;

struct Pos
{
	Pos(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}

	int x, y;
};

struct Rect
{
	bool operator < (const Rect &x) const
	{ return 1; }

	int x[4], y[4];
};

int ans;
set<Rect> S;
set<int> X, Y;
Pos pData[MAXN];

int MAX(const int x[]);
int MIN(const int x[]);
int GetArea(const Rect &A, const Rect &B);
bool Check(const Rect &A, const Rect &B);
bool CheckRect(int i, int j, int k, int l);
void AddRect(int i, int j, int k, int l);
void check2(const Rect &A,const Rect &B);


int main()
{
	int N;
	while(scanf("%d", &N) && N)
	{
		ans = -1;
		S.clear();
		for(int i = 1; i <= N; i++)
		{ scanf("%d%d", &pData[i].x, &pData[i].y); }
		for(int i = 1; i <= N; i++)
		{
			for(int j = i + 1; j <= N; j++)
			{
				for(int k = j + 1; k <= N; k++)
				{
					for(int l = k + 1; l <= N; l++)
					{
						if(CheckRect(i, j, k, l)) { AddRect(i, j, k, l); }
					}
				}
			}
		}
		set<Rect>::iterator i, j;
		for(i = S.begin(); i != S.end(); i++)
		{
			for(j = i, j++; j != S.end(); j++)
			{
				if(Check(*i, *j)) { ans = max(ans, GetArea(*i, *j)); }
				else check2(*i,*j);
			}
		}
		if(ans == -1) { printf("imp\n"); }
		else { printf("%d\n", ans); }
	}
	return 0;
}

int MAX(const int x[])
{ return max(x[0], max(x[1], max(x[2], x[3]))); }

int MIN(const int x[])
{ return min(x[0], min(x[1], min(x[2], x[3]))); }

int GetArea(const Rect &A, const Rect &B)
{
	int a, b, c, d;
	a = MAX(A.x) - MIN(A.x);
	b = MAX(A.y) - MIN(A.y);
	c = MAX(B.x) - MIN(B.x);
	d = MAX(B.y) - MIN(B.y);
	return a * b + c * d;
}

void check2(const Rect &A,const Rect &B){
	int x11=MIN(A.x),x12=MAX(A.x);
	int x21=MIN(B.x),x22=MAX(B.x);
	int y11=MIN(A.y),y12=MAX(A.y);
	int y21=MIN(B.y),y22=MAX(B.y);
	if(x11<x21&&x12>x22){
		if(y11<y21&&y12>y22){
			int a=MAX(A.x)-MIN(A.x);
			int b=MAX(A.y)-MIN(A.y);
			ans=max(ans,a*b);
		}
	}
	if(x11>x21&&x12<x22){
		if(y11>y21&&y12<y22){
			int a=MAX(B.x)-MIN(B.x);
			int b=MAX(B.y)-MIN(B.y);
			ans=max(ans,a*b);
		}
	}
}

bool Check(const Rect &A, const Rect &B)
{
	bool a, b, c, d;
	a = MAX(A.x) < MIN(B.x);
	b = MAX(B.x) < MIN(A.x);
	c = MAX(A.y) < MIN(B.y);
	d = MAX(B.y) < MIN(A.y);
	return a || b || c || d;
}

bool CheckRect(int i, int j, int k, int l)
{
	X.clear(); Y.clear();
	X.insert(pData[i].x); Y.insert(pData[i].y);
	X.insert(pData[j].x); Y.insert(pData[j].y);
	X.insert(pData[k].x); Y.insert(pData[k].y);
	X.insert(pData[l].x); Y.insert(pData[l].y);
	return X.size() == 2 && Y.size() == 2;
}

void AddRect(int i, int j, int k, int l)
{
	Rect Tmp;
	Tmp.x[0] = pData[i].x; Tmp.y[0] = pData[i].y;
	Tmp.x[1] = pData[j].x; Tmp.y[1] = pData[j].y;
	Tmp.x[2] = pData[k].x; Tmp.y[2] = pData[k].y;
	Tmp.x[3] = pData[l].x; Tmp.y[3] = pData[l].y;
	S.insert(Tmp);
}
