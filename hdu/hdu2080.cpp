#include<stdio.h>
#include<math.h>
double len(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
    int T;
    while(scanf("%d",&T)!=EOF){
        for(int q=1;q<=T;q++){
            double x1,y1,x2,y2;
            double a,b,c;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            a=len(0,0,x1,y1);
            b=len(0,0,x2,y2);
            c=len(x1,y1,x2,y2);
            double cos1=(a*a+b*b-c*c)/(2*a*b);
            double t=acos(cos1)*180/3.14159;
            printf("%.2lf\n",t);
        }
    }
    return 0;
}
