#include<bits/stdc++.h>
using namespace std;

long long gcd(long long x,long long y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}

long long _abs(long long x)
{
	return x>0?x:-x;
}

struct Fraction{
	long long num;
	long long den;
	Fraction(long long num=0,long long den=1){
		if(den<0){
			num=-num;
			den=-den;
		}
		assert(den!=0);
		long long g=gcd(_abs(num),den);
		this->num=num/g;
		this->den=den/g;
	}
	Fraction operator+(const Fraction &o)const{
		return Fraction(num*o.den+den*o.num,den*o.den);
	}
	Fraction operator-(const Fraction &o)const{
		return Fraction(num*o.den-den*o.num,den*o.den);
	}
	Fraction operator*(const Fraction &o)const{
		return Fraction(num*o.num,den*o.den);
	}
	Fraction operator/(const Fraction &o)const{
		return Fraction(num*o.den,den*o.num);
	}
	Fraction operator%(int mod)const{
		long long _num=num;
		while(_num>=den*mod) _num-=den*mod;
		return Fraction(_num,den);
	}
	bool operator<(const Fraction &o) const{
		return num*o.den<den*o.num;
	}
	bool operator==(const Fraction &o) const{
		return num*o.den==den*o.num;
	}
};
int H,h,m,s;

void fuck()
{
	Fraction res1,res2,ans;
	Fraction vh(1,10*H);
	Fraction vm(1,10);
	Fraction vs(6,1);
	Fraction vv=(vm+vh)*Fraction(1,2);
	Fraction ss(s+m*60+h*60*60,1);
	Fraction dh=ss*vh%360;
	Fraction dm=ss*vm%360;
	Fraction ds=ss*vs%360;
	Fraction dd=(dh+dm)*Fraction(1,2);
	Fraction d=dd-ds;
	if(d.num<0) d=d+Fraction(360,1);
	res1=d/(vs-vv);
	dd=(dd+Fraction(180,1))%360;
	d=dd-ds;
	if(d.num<0) d=d+Fraction(360,1);
	res2=d/(vs-vv);
	if(res2<res1) swap(res1,res2);
	dh=(dh+res1*vh)%360;
	dm=(dm+res1*vm)%360;
	if(dh==dm) ans=res2;
	else ans=res1;
	//printf("%lld %lld\n",ans.num,ans.den);
	ans=ans+Fraction(s,1);
	m+=ans.num/(60*ans.den);
	ans=ans%60;
	h+=m/60;
	m%=60;
	h%=H;
	printf("%d %d %lld %lld\n",h,m,ans.num,ans.den);
}

int main()
{
	while(~scanf("%d%d%d%d",&H,&h,&m,&s)&&(H+h+m+s)){
		fuck();
	}
 return 0;
}
