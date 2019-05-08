#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

#define MAXLENGTH 1000
class CString
{
private:
	char m_buff[MAXLENGTH];
public:
	CString(); //构造函数1，设置为空字符串
	CString(const char *src); //构造函数2，在考虑了src的长度是否合法后初始化当前对象
	CString(const char ch); //构造函数3，0号元素赋值为ch
	int setString(const char *src); //设置字符串，在考虑了src的长度是否合法后设置当前对象
	friend ostream& operator<<(ostream& Out, const CString& S); //输出字符串
	char& operator[](const int i);	//重载下标运算符
};

CString::CString(){	//构造函数1，设置为空字符串
	memset(m_buff,0,sizeof(m_buff));
}

CString::CString(const char *src){	//构造函数2，在考虑了src的长度是否合法后初始化当前对象
	if(strlen(src)<MAXLENGTH)strcpy(m_buff,src);
	else{
		cout<<"src长度超过合法范围"<<endl;
		exit(1);
	}
}

CString::CString(const char ch){	//构造函数3，0号元素赋值为ch
	memset(m_buff,0,sizeof(m_buff));
	m_buff[0]=ch;
}

int CString::setString(const char *src){	//设置字符串，在考虑了src的长度是否合法后设置当前对象
	if(strlen(src)<MAXLENGTH)strcpy(m_buff,src);
	else{
		cout<<"src长度超过合法范围"<<endl;
		exit(1);
	}
}

ostream& operator<<(ostream& Out,const CString& S){	//输出字符串
	Out<<S.m_buff;
}

char& CString::operator[](const int i){	//重载下标运算符
	if(i<0||i>=MAXLENGTH){
		cout<<"下标越界"<<endl;
		exit(1);
	}
	return m_buff[i];
}

int main()
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
