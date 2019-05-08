#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
#define pi 3.14159

class Circle{					//Circle类
private:
	double x,y,r;				//横纵坐标以及半径
public:
	void Set_o(double,double);	//初始化圆心坐标
	void Set_r(double);			//初始化半径
	double Cal_S()const;		//计算圆面积
	double Cal_C()const;		//计算圆周长
	double Get_x()const;		//获得圆心横坐标
	double Get_y()const;		//获得圆心纵坐标
	double Get_r()const;		//获得半径


	friend Circle operator+(const Circle&,const Circle&);	//加号重载
	friend Circle operator-(const Circle&,const Circle&);	//减号重载
	friend Circle& operator++(Circle&);						//前自增重载
	friend Circle operator++(Circle&,int);					//后自增重载
	friend Circle& operator--(Circle&);						//前自减重载
	friend Circle operator--(Circle&,int);					//后自减重载
	friend ostream& operator<<(ostream&,const Circle&);		//流输出重载
	friend bool operator>(const Circle&,const Circle&);		//大于号重载
	friend bool operator<(const Circle&,const Circle&);		//小于号重载
	friend bool operator==(const Circle&,const Circle&);	//判等重载
	friend bool operator!=(const Circle&,const Circle&);	//不等重载
	friend bool operator&(const Circle&,const Circle&);		//位与重载
	friend int operator|(const Circle&,const Circle&);		//位或重载
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

double Circle::Get_x()const{		//获得圆心横坐标函数
	return x;
}

double Circle::Get_y()const{		//获得圆心纵坐标函数
	return y;
}

double Circle::Get_r()const{		//获得半径函数
	return r;
}

Circle operator+(const Circle& c1,const Circle& c2){		//加号重载
	Circle a;
	a.x=c1.x;
	a.y=c1.y;
	a.r=c1.r+c2.r;
	return a;
}

Circle operator-(const Circle& c1,const Circle& c2){		//减号重载
	Circle a;
	a.x=c1.x;
	a.y=c1.y;
	a.r=sqrt(abs(c1.r*c1.r-c2.r*c2.r));
	return a;
}

Circle& operator++(Circle& c){								//前自增重载
	c.r+=1;
	return c;
}

Circle operator++(Circle& c,int){							//后自增重载
	Circle a(c);
	c.r+=1;
	return a;
}

Circle& operator--(Circle& c){								//前自减重载
	c.r-=1;
	return c;
}

Circle operator--(Circle& c,int){							//后自减重载
	Circle a(c);
	c.r-=1;
	return a;
}

ostream& operator<<(ostream& o,const Circle& c){			//流输出重载
	o<<"圆心坐标：("<<c.x<<","<<c.y<<")"<<endl;
	o<<"圆的半径："<<c.r<<endl;
	o<<"圆的周长："<<c.Cal_C()<<endl;
	o<<"圆的面积："<<c.Cal_S()<<endl;
}

bool operator>(const Circle& c1,const Circle& c2){			//大于号重载
	return c1.r>c2.r?1:0;
}

bool operator<(const Circle& c1,const Circle& c2){			//小于号重载
	return c1.r<c2.r?1:0;
}

bool operator==(const Circle& c1,const Circle& c2){			//判等重载
	return (c1.x==c2.x&&c1.y==c2.y&&c1.r==c2.r)?1:0;
}

bool operator!=(const Circle& c1,const Circle& c2){			//不等重载
	return (c1.x!=c2.x||c1.y!=c2.y||c1.r!=c2.r)?1:0;
}

bool operator&(const Circle& c1,const Circle& c2){			//位与重载
	return (c1.x==c2.x&&c1.y==c2.y)?1:0;
}

int operator|(const Circle& c1,const Circle& c2){			//位或重载
	double d=sqrt((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y));
	if(d<c1.r+c2.r&&d>abs(c1.r-c2.r))return 1;
	else if(d==c1.r+c2.r||d==abs(c1.r-c2.r))return 2;
	else if(d>c1.r+c2.r)return 3;
	else if(d<abs(c1.r-c2.r))return 4;
}

int main(){
	srand(time(NULL));
	
	Circle C1;						//生成C1圆
	Circle C2;						//生成C2圆
	
	C1.Set_o(rand()%20,rand()%20);		//不断随机生成两圆直到相离
	C1.Set_r(rand()%20+1);
	C2.Set_o(rand()%20,rand()%20);
	C2.Set_r(rand()%20+1);

	while((C1|C2)!=3||C1>C2){
		C1.Set_o(rand()%20,rand()%20);
		C1.Set_r(rand()%20+1);
		C2.Set_o(rand()%20,rand()%20);
		C2.Set_r(rand()%20+1);	
	}
	//计算圆的各个值
	double v2=1,v1,r1=C1.Get_r(),x1=C1.Get_x(),y1=C1.Get_y(),r2=C2.Get_r(),x2=C2.Get_x(),y2=C2.Get_y();
	double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	double dx=(x2-x1)/d,dy=(y2-y1)/d;
	v1=(r2*r2)/(r1*r1);
	d-=(r1+r2);
	if(d<1e-5)d=0;

	int time=0;				//输出初始状态圆
	cout<<"time:"<<time++<<endl;
	cout<<"C1:  O("<<x1<<","<<y1<<")"<<"  r="<<r1<<"  v="<<v1<<endl;
	cout<<"C2:  O("<<x2<<","<<y2<<")"<<"  r="<<r2<<"  v="<<v2<<endl;
	cout<<"距离:"<<d<<endl;
	double dd=d;
	bool f=0;

	while((C1|C2)==3&&r1>1e-5&&r2>1e-5){	//循环模拟圆的运动直到不相离或圆消失
		if(r1>1)C1--;		//改变两圆半径
		else C1=C1-C1;
		r1=C1.Get_r();
		if(r2>1)C2--;
		else C2=C2-C2;
		r2=C2.Get_r();

		C1.Set_o(x1+dx*v1,y1+dy*v1);	//改变两圆圆心坐标
		C2.Set_o(x2-dx*v2,y2-dy*v2);
		x1=C1.Get_x();
		y1=C1.Get_y();
		x2=C2.Get_x();
		y2=C2.Get_y();

		d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))-r1-r2;	//计算两圆距离和速度
		if(d<1e-5)d=0;
		if(r1<1e-5)v1=0;
		else v1=(r2*r2)/(r1*r1);
		if(r2<1e-5)v2=0;
		
		cout<<"time:"<<time++<<endl;		//输出两圆状态
		cout<<"C1:  O("<<x1<<","<<y1<<")"<<"  r="<<r1<<"  v="<<v1<<endl;
		cout<<"C2:  O("<<x2<<","<<y2<<")"<<"  r="<<r2<<"  v="<<v2<<endl;
		cout<<"距离:"<<d<<endl;

		if(d-dd>1e-5){
			f=1;
			break;
		}
		dd=d;
	}

	if(f||(C1|C2)!=3)cout<<"相撞"<<endl;	//判定是否能相撞
	else cout<<"未相撞"<<endl;	

}
