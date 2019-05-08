#include<iostream>
using namespace std;
#define pi 3.14159

class Circle{					//Circle类
	double x,y,r;				//横纵坐标以及半径
public:
	void Set_o(double,double);	//初始化圆心坐标
	void Set_r(double);			//初始化半径
	double Cal_S()const;		//计算圆面积
	double Cal_C()const;		//计算圆周长
};

void Circle::Set_o(double xx,double yy){	//设置圆心坐标函数
	x=xx;
	y=yy;
}

void Circle::Set_r(double rr){		//设置半径函数
	r=rr;
}

double Circle::Cal_S()const{		//计算面积函数
	return pi*r*r;
}

double Circle::Cal_C()const{		//计算周长函数
	return 2*pi*r;
}

void main(){
	Circle O1;
	double xx,yy,rr;
	cout<<"请依次输入圆心的横纵坐标："<<endl;
	cin>>xx>>yy;
	O1.Set_o(xx,yy);
	cout<<"请输入圆的半径："<<endl;
	cin>>rr;
	O1.Set_r(rr);
	cout<<"圆的面积为："<<O1.Cal_S()<<endl;
	cout<<"圆的周长为："<<O1.Cal_C()<<endl;
}
