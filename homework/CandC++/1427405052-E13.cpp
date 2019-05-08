#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class CComplex
{
private:
	double m_real;
	double m_image;
public:
	void setValue(double real,double image)
	{
		m_real=real;
		m_image=image;
	}
	
	friend ostream& operator<<(ostream& o,const CComplex& c);		//重载流输出符

	friend CComplex operator+(const CComplex& a,const CComplex& b); //重载复数+复数

	friend CComplex operator+(const CComplex& a,const double b);	//重载复数+实数

	friend CComplex& operator++(CComplex& a);						//重载前自增

	friend CComplex operator++(CComplex& a,int);					//重载后自增

};

ostream& operator<<(ostream& o,const CComplex& c){					//重载流输出符
	o<<c.m_real<<"+"<<c.m_image<<'i'<<endl;
}

CComplex operator+(const CComplex& a,const CComplex& b){			//重载复数+复数
	CComplex ans;
	ans.setValue(a.m_real+b.m_real,a.m_image+b.m_image);
	return ans;
}

CComplex operator+(const CComplex& a,constdouble b){				//重载复数+实数
	CComplex ans;
	ans.setValue(a.m_real+b,a.m_image);
	return ans;
}

CComplex& operator++(CComplex& a){									//重载前自增
	a.m_real+=1;
	a.m_image+=1;
	return a;
}

CComplex operator++(CComplex& a,int){								//重载后自增
	CComplex ans(a);
	a.m_real+=1;
	a.m_image+=1;
	return ans;
}

void main(){
	srand(time(NULL));
	CComplex C1,C2;													//生成C1，C2两个复数并测试流输出符
	C1.setValue(rand()%21,rand()%21);
	C2.setValue(rand()%21,rand()%21);
	cout<<"复数C1为："<<C1<<"复数C2为："<<C2<<endl;

	CComplex C3=C1+C2;												//测试复数+复数
	cout<<"C3=C1+C2="<<C3<<endl;

	int num=rand()%21;												//测试复数+实数
	cout<<"C1+"<<num<<"="<<(C1+num)<<endl;

	CComplex C4=C1++;												//测试后自增
	cout<<"运行C4=C1++后："<<endl<<"C1="<<C1<<"C4="<<C4<<endl;

	CComplex C5=++C1;												//测试前自增
	cout<<"运行C5=++C1后："<<endl<<"C1="<<C1<<"C5="<<C5<<endl;
	
}
