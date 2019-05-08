#include<iostream>
using namespace std;

//日期
struct Date
{
	int year;	//年
	int month;	//月
	int day;	//日

	Date(){}
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
};
//账户类
class CAount
{
private:
	double m_Money;	//余额
	Date m_Date;	//存款日期
	static double m_InterestRate;	//年利率

	int NumOfDays(const Date &date) const;	//计算间隔天数，内部计算调用

public:
	static void SetInterestRate(double interest);	//设置年利率
	static double GetInterestRate();				//获取年利率
	
	void SaveMoney(double money, const Date &date);	//存款函数
	bool LendMoney(double money);					//取款函数，返回是否取款成功
	double CalcInterest(const Date &date) const;	//计算利息
	void SaveInterest(const Date &date);			//结算利息
	
	double GetBalance();	//获取余额
	Date GetDate();			//获取存款日期
};

void main()
{
	CAount account;

	CAount::SetInterestRate(0.036);//设置年利率
	account.SaveMoney(200000.0, Date(2015, 4, 22));//存款

	//输出年利率
	cout<<"设置的年利率为："<<CAount::GetInterestRate()<<endl;
	cout<<endl;
	//取款
	cout<<"取款210000元："<<endl;
	if (!account.LendMoney(210000.0))
	{
		cout<<"余额不足！"<<endl;
	}
	else
	{
		cout<<"取款成功！"<<endl;
	}
	cout<<endl;
	//利息计算与结算
	cout<<"到2016年12月1日，利息为："<<account.CalcInterest(Date(2016, 12, 1))<<"元"<<endl;
	account.SaveInterest(Date(2016, 12, 1));
	//取款
	cout<<"取款100000元："<<endl;
	if (!account.LendMoney(100000.0))
	{
		cout<<"余额不足！"<<endl;
	}
	else
	{
		cout<<"取款成功！"<<endl;
		cout<<"您的余额为："<<account.GetBalance()<<"元"<<endl;
		cout<<"存款日期（或上次利息结算日期）为："<<account.GetDate().year<<"年"
			<<account.GetDate().month<<"月"<<account.GetDate().day<<"日"<<endl;
	}
}