#include<iostream>
using namespace std;
#define pi 3.14159

class Column{					//圆柱体类
private:
	double x,y,r,h;
public:
	void Set_o(double,double);	//初始化底面圆心坐标
	void Set_r(double);			//初始化底面圆半径
	double Cal_S()const;		//计算底面圆面积
	double Cal_C()const;		//计算底面圆周长
	void Set_h(double);			//初始化圆柱体的高
	double Cal_lS()const;		//计算圆柱体侧面积
	double Cal_V()const;		//计算圆柱体体积
};

void Column::Set_o(double xx,double yy){	//设置底面圆心坐标函数
	x=xx;
	y=yy;
}

void Column::Set_r(double rr){		//设置底面圆半径函数
	r=rr;
}

double Column::Cal_S()const{		//计算底面圆面积函数
	return pi*r*r;
}

double Column::Cal_C()const{		//计算底面圆周长函数
	return 2*pi*r;
}

void Column::Set_h(double hh){		//设置圆柱体高函数
	h=hh;
}

double Column::Cal_lS()const{		//计算圆柱体侧面积函数
	return Cal_C()*h;
}

double Column::Cal_V()const{		//计算圆柱体体积函数
	return Cal_S()*h;
}


void main(){
	Column C1;
	double xx,yy,rr,hh;
	cout<<"请依次输入底面圆心的横纵坐标："<<endl;
	cin>>xx>>yy;
	C1.Set_o(xx,yy);
	cout<<"请输入底面圆的半径："<<endl;
	cin>>rr;
	C1.Set_r(rr);
	cout<<"请输入圆柱体的高："<<endl;
	cin>>hh;
	C1.Set_h(hh);
	cout<<"底面圆的面积为："<<C1.Cal_S()<<endl;
	cout<<"底面圆的周长为："<<C1.Cal_C()<<endl;
	cout<<"圆柱体的侧面积为："<<C1.Cal_lS()<<endl;
	cout<<"圆柱体的体积为："<<C1.Cal_V()<<endl;
}
