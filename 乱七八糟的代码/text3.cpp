#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<fstream>
#include<cstring>
#include<sstream>
#include<string>
using namespace std;

class CGoods{
private:
	int m_num;	//商品编号
	string m_name;	//商品名称
	float m_price;	//商品价格
public:
	CGoods (int num=1, const string& name="M8", float price=100.0);
	friend ostream& operator<<(ostream&, const CGoods&);
	int GetNum()const;
	string GetName()const;
	float GetPrice()const;
};

CGoods::CGoods(int num, const string& name, float price){
	if(num<0 ||price<=0)exit(0);
	m_name=name;
	m_num=num;
	m_price=price;
}

ostream& operator<<(ostream& out, const CGoods& a){
	out<<"商品编号："<<setw(10)<<a.m_num<<endl<<"商品名称："<<setw(10)<<a.m_name<<endl<<"商品价格："<<setw(10)<<a.m_price<<endl;
	return out;
}

int CGoods::GetNum()const{
	return m_num;
}

string CGoods::GetName()const{
	return m_name;
}

float CGoods::GetPrice()const{
	return m_price;	
}

class CRouter : public CGoods{
private:
	float m_frequency;//信号频率
	int m_channels;//端口数量

public:
	CRouter(int num=1,string name="M8",float price=100.0,float frequency=2.4,int channels=8);

	CRouter(const CRouter& a); 

	int GetChannels() const;
	double GetFrequency() const;
	friend ostream& operator<<(ostream&, const CRouter&);
	friend CRouter & operator++(CRouter&);
	friend CRouter operator++(CRouter,int );
};

CRouter::CRouter(int num,string name,float price,float frequency,int channels):CGoods(num,name,price){	
	if(frequency<0 ||channels<0)exit(0);
	m_frequency=frequency;
	m_channels=channels;
}

CRouter::CRouter(const CRouter& a):CGoods(a.GetNum(),a.GetName(),a.GetPrice()){
	m_frequency=a.m_frequency;
	m_channels=a.m_channels;
}

int CRouter::GetChannels() const{
	return m_channels;
}

double CRouter::GetFrequency() const{
	return m_channels;
}

ostream& operator<<(ostream& out, const CRouter& a){
	return out<<(CGoods)a<<"信号频率："<<setw(10)<<a.m_frequency<<endl<<"端口数量："<<setw(10)<<a.m_channels<<endl;
}

CRouter & operator++(CRouter& a){
	a.m_channels++;
	return a;
}

CRouter  operator++(CRouter a,int ){
	CRouter t(a);
	a.m_channels++;
	return t;
}

void ReadData(vector<CRouter>& s,const char* FileName){
	ifstream fin(FileName);
	if(fin==NULL){
		cout<<"读入文件错误！"<<endl;
		exit(0);
	}
	s.clear();
	while(fin.eof()!=true){
		int num;
		string name;
		float price;
		float frequency;
		int channels;
		fin>>num>>name>>price>>frequency>>channels;
	/*	if(fin!=NULL){
			s.push_back(CRouter(num,name,price,frequency,channels));
		}*/
		s.push_back(CRouter(num,name,price,frequency,channels));
	}
	fin.close();
}

void DisplayData(const vector<CRouter> & s){
	int i=0;
	for(;i<s.size()-1;i++)
	{
		CRouter tmp(s[i]);
		cout<<tmp;
	}
}

CRouter FindMax(const vector<CRouter> & s){
	int i=0,max=i+1;
	for(;i<s.size()-1;i++)
	{
		if((s[i].GetChannels()*s[i].GetFrequency())>(s[max].GetChannels()*s[max].GetFrequency()))
			max=i;
	}
	return s[max];
}

int main(){
	vector<CRouter> s;

	ReadData(s,"Data.txt");
	cout<<"读取完成后的向量为"<<endl;
	DisplayData(s);

	CRouter t;
	cout<<endl<<"路由器对象的初始值为"<<endl<<t<<endl;

	t=FindMax(s);
	cout<<endl<<"乘积最大的向量元素为"<<endl<<t<<endl;

	cout<<endl<<"乘积最大的向量元素进行自增运算结果分别如下:"<<endl;
	cout<<t++<<endl;
	cout<<t<<endl;

	cout<<++t<<endl;
	cout<<t<<endl;
}

