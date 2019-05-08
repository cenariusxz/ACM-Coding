#include<stdio.h>
#include<math.h>
double len(double x){
    return sqrt(x*x+(x+1)*(x+1));
}

int main(){
    int N;
    while(scanf("%d",&N)!=EOF){
        for(int q=1;q<=N;q++){
            double x1,y1,x2,y2;
            double l=0;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            if(x1+y1==x2+y2){
                l=abs(y1-y2)*sqrt(2.0);
            }
            else{
                double a,b;
                if(x1+y1>x2+y2){
                    double t;
                    t=x1;x1=x2;x2=t;
                    t=y1;y1=y2;y2=t;
                }
                a=x1+y1;b=x2+y2;
                int i;
                for(i=a;i<b;i++) l+=len(i);
                l+=((a+b)*(b-a-1)/2+y1+x2)*sqrt(2.0);
            }
            printf("%.3lf\n",l);

        }
    }
    return 0;
}
