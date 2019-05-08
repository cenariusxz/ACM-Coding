#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const double expp=1e-11;

double aabs(double x){
    return x<0?-x:x;
}

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int q=1;q<=T;q++){
        int n;
        double v,x;
        scanf("%d%lf%lf",&n,&v,&x);
        printf("Case #%d: ",q);
        if(n==1){
            double r,c;
            scanf("%lf%lf",&r,&c);
            if(aabs(c-x)<expp){
                printf("%.9lf\n",v/r);
            }
            else printf("IMPOSSIBLE\n");
        }
        else if(n==2){
            double r1,c1,r2,c2;
            scanf("%lf%lf%lf%lf",&r1,&c1,&r2,&c2);
            if(aabs(c1-c2)<expp){
                if(aabs(c1-x)<expp)printf("%.9lf\n",v/(r1+r2));
                else printf("IMPOSSIBLE\n");
            }
            else{
                double v1=(x-c2)*v/(c1-c2);
                double v2=(c1-x)*v/(c1-c2);
                if(v1<0||v2<0)printf("IMPOSSIBLE\n");
                else{
                    printf("%.9lf\n",max(v1/r1,v2/r2));

                }
            }
        }
    }
    return 0;
}
