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
	friend void operator|(const Circle&,const Circle&);		//位或重载
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

void operator|(const Circle& c1,const Circle& c2){			//位或重载
	double d=sqrt((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y));
	if(d<c1.r+c2.r&&d>abs(c1.r-c2.r))cout<<"相交";
	else if(d==c1.r+c2.r||d==abs(c1.r-c2.r))cout<<"相切";
	else if(d>c1.r+c2.r)cout<<"相离";
	else if(d<abs(c1.r-c2.r))cout<<"包含";
	cout<<endl;
}

void main(){
	srand(time(NULL));
	
	Circle C1;						//生成C1圆
	C1.Set_o(rand()%20,rand()%20);
	C1.Set_r(rand()%20+1);
	cout<<"生成的圆C1:"<<endl<<C1<<endl;
	
	Circle C2;						//生成C2圆
	C2.Set_o(rand()%20,rand()%20);
	C2.Set_r(rand()%20+1);
	cout<<"生成的圆C2:"<<endl<<C2<<endl;
	
	Circle C3=C1+C2;				//测试相加
	cout<<"C1与C2相加得到的圆C3:"<<endl<<C3<<endl;
	
	Circle C4=C1-C2;				//测试相减
	cout<<"C1与C2相减得到的圆C4:"<<endl<<C4<<endl;
	
	Circle C5=C1++;					//测试后自增
	cout<<"运行“C5=C1++”后:"<<endl<<"C5:"<<endl<<C5<<"C1:"<<endl<<C1<<endl;
	
	Circle C6=C1--;					//测试后自减
	cout<<"运行“C6=C1--”后:"<<endl<<"C6:"<<endl<<C6<<"C1:"<<endl<<C1<<endl;
	
	Circle C7=++C1;					//测试前自增
	cout<<"运行“C7=++C1”后:"<<endl<<"C7:"<<endl<<C7<<"C1:"<<endl<<C1<<endl;
	
	Circle C8=--C1;					//测试前自减
	cout<<"运行“C8=--C1”后:"<<endl<<"C8:"<<endl<<C8<<"C1:"<<endl<<C1<<endl;
	
	if(C1>C2)cout<<"C1>C2"<<endl;	//测试大于
	if(C1<C2)cout<<"C1<C2"<<endl;	//测试小于
	if(C1==C2)cout<<"C1==C2"<<endl;	//测试判等
	if(C1!=C2)cout<<"C1!=C2"<<endl;	//测试不等
	cout<<endl;
	
	if(C1&C2)cout<<"C1,C2是同心圆"<<endl<<endl;	//测试判同心圆
	else cout<<"C1,C2不是同心圆"<<endl<<endl;
	
	C1|C2;							//测试判断相对位置

}
