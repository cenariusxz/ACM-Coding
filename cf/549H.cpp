#include<stdio.h>
#include<string.h>
#include<algorithm>
#define eps 1e-12
using namespace std;

int main()
{
    double a,b,c,d;
    double le=0,ri=1000000000000,mid;
    double a1,a2,b1,b2,c1,c2,d1,d2,t1,t2,p1,p2;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    while(ri-le>eps){
        mid=(le+ri)/2;
        a1=a-mid;a2=a+mid;
        d1=d-mid;d2=d+mid;
        t1=min(min(a1*d1,a2*d2),min(a1*d2,a2*d1));
        t2=max(max(a1*d1,a2*d2),max(a1*d2,a2*d1));
        b1=b-mid;b2=b+mid;
        c1=c-mid;c2=c+mid;
        p1=min(min(b1*c1,b2*c2),min(b1*c2,b2*c1));
        p2=max(max(b1*c1,b2*c2),max(b1*c2,b2*c1));
        if(t1<p2&&p1<t2) ri=mid;
        else le=mid;
    }
    printf("%.10lf\n",le);
 return 0;
}
