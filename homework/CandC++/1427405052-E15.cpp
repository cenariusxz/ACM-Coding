#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

class CString
{
private:
	char * m_pbuff; //指向字符串的指针
	int m_length; //表示当前字符串的最大允许长度，也就是字符数组的长度
public:
	CString(); //构造函数1，设置为空字符串，m_length=100
	CString(const char *src); //构造函数2，在考虑了src的长度后初始化当前对象，m_length>=src的长度+1
	CString(const char ch); //构造函数3，0号元素赋值为ch, m_length=100
	int setString(const char *src); //设置字符串，在考虑了src的长度后设置当前对象,m_length>=src的长度+1
	friend ostream& operator<<(ostream& Out,const CString& S); //输出字符串
	char& operator[](const int i);	//重载下标运算符
	CString(const CString& S);	//拷贝构造函数
	~CString();	//析构函数
};

CString::CString(){	//构造函数1，设置为空字符串，m_length=100
	m_pbuff=new char[100];
	m_length=100;
}

CString::CString(const char *src){	//构造函数2，在考虑了src的长度后初始化当前对象，m_length>=src的长度+1
	m_pbuff=new char[strlen(src)+1];
	if(m_pbuff)strcpy(m_pbuff,src);
}

CString::CString(const char ch){	//构造函数3，0号元素赋值为ch, m_length=100
	m_pbuff=new char[100];
	m_length=100;
	memset(m_pbuff,0,sizeof(m_pbuff));
	m_pbuff[0]=ch;
}

int CString::setString(const char *src){	//设置字符串，在考虑了src的长度后设置当前对象,m_length>=src的长度+1
	if(m_length<strlen(src)+1){
		cout<<"src长度超过合法范围"<<endl;
		exit(1);
	}
	strcpy(m_pbuff,src);
}

ostream& operator<<(ostream& Out,const CString& S){	//输出字符串
	Out<<S.m_pbuff;
}

char& CString::operator[](const int i){	//重载下标运算符
	if(i<0||i>=m_length){
		cout<<"下标越界"<<endl;
		exit(1);
	}
	return m_pbuff[i];
}

CString::CString(const CString& S){	//拷贝构造函数
	m_pbuff=new char[strlen(S.m_pbuff)+1];
	if(m_pbuff)strcpy(m_pbuff,S.m_pbuff);
}

CString::~CString(){	//析构函数
	delete[] m_pbuff;
}

void main()
{
	CString s1;
	cout<<s1;
	s1.setString("abc1");
	cout<<s1;
	CString s2("abc2");
	cout<<s2;
	CString s3('a');
	cout<<s3;
	CString s4(s2);
	cout<<s4;
}
