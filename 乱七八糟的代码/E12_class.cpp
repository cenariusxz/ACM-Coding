#include<iostream>
using namespace std;

//����
struct Date
{
	int year;	//��
	int month;	//��
	int day;	//��

	Date(){}
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
};
//�˻���
class CAount
{
private:
	double m_Money;	//���
	Date m_Date;	//�������
	static double m_InterestRate;	//������

	int NumOfDays(const Date &date) const;	//�������������ڲ��������

public:
	static void SetInterestRate(double interest);	//����������
	static double GetInterestRate();				//��ȡ������
	
	void SaveMoney(double money, const Date &date);	//����
	bool LendMoney(double money);					//ȡ����������Ƿ�ȡ��ɹ�
	double CalcInterest(const Date &date) const;	//������Ϣ
	void SaveInterest(const Date &date);			//������Ϣ
	
	double GetBalance();	//��ȡ���
	Date GetDate();			//��ȡ�������
};

void main()
{
	CAount account;

	CAount::SetInterestRate(0.036);//����������
	account.SaveMoney(200000.0, Date(2015, 4, 22));//���

	//���������
	cout<<"���õ�������Ϊ��"<<CAount::GetInterestRate()<<endl;
	cout<<endl;
	//ȡ��
	cout<<"ȡ��210000Ԫ��"<<endl;
	if (!account.LendMoney(210000.0))
	{
		cout<<"���㣡"<<endl;
	}
	else
	{
		cout<<"ȡ��ɹ���"<<endl;
	}
	cout<<endl;
	//��Ϣ���������
	cout<<"��2016��12��1�գ���ϢΪ��"<<account.CalcInterest(Date(2016, 12, 1))<<"Ԫ"<<endl;
	account.SaveInterest(Date(2016, 12, 1));
	//ȡ��
	cout<<"ȡ��100000Ԫ��"<<endl;
	if (!account.LendMoney(100000.0))
	{
		cout<<"���㣡"<<endl;
	}
	else
	{
		cout<<"ȡ��ɹ���"<<endl;
		cout<<"�������Ϊ��"<<account.GetBalance()<<"Ԫ"<<endl;
		cout<<"������ڣ����ϴ���Ϣ�������ڣ�Ϊ��"<<account.GetDate().year<<"��"
			<<account.GetDate().month<<"��"<<account.GetDate().day<<"��"<<endl;
	}
}