#include <iostream>
#include <cmath>
using namespace std;
class CPoint
{
private:
	int m_x; //点的X坐标
	int m_y; //点的Y坐标º
public:
	CPoint()
	{
		m_x=0;
		m_y=0;
	}
	CPoint (int x,int y)
	{
		m_x=x;
		m_y=y;
	}
	int getx()
	{
		return m_x;
	}
	int gety()
	{
		return m_y;
	}
	void showPoint()
	{
		cout<<"("<<this->m_x<<","<<this->m_y<<")"<<endl;
	}
};
class CLine
{
private:
	CPoint m_point1;
	CPoint m_point2;
public:
	CLine();	//无参构造函数

	void ShowLine();	//输出两端点
	
	double distance();	//返回线段长度
	
	CLine(const int x1,const int y1,const int x2,const int y2);	//构造函数

};

CLine::CLine():m_point1(),m_point2(){}	//无参构造函数

CLine::CLine(const int x1,const int y1,const int x2,const int y2):m_point1(x1,y1),m_point2(x2,y2){}	//构造函数

void CLine::ShowLine(){	//输出两端点
	cout<<"Point 1 is:";
	m_point1.showPoint();
	cout<<"Point 2 is:";
	m_point2.showPoint();
}
	
double CLine::distance(){	//返回线段长度
	int x1=m_point1.getx(),y1=m_point1.gety(),x2=m_point2.getx(),y2=m_point2.gety();
	return sqrt((x1-x2)*(x1-x2)*1.0+(y1-y2)*(y1-y2)*1.0);
}

void main()
{
	CLine line1;
	line1.ShowLine();
	cout<<"Length="<<line1.distance()<<endl;
	CLine line2(1,1,5,5);
	line2.ShowLine();
	cout<<"Length="<<line2.distance()<<endl;
}
