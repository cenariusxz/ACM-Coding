#include<stdio.h>
#include<math.h>

int main(){
    int h,m,s,T;
    while(scanf("%d",&T)!=EOF){
        for(int q=1;q<=T;q++){
            scanf("%d%d%d",&h,&m,&s);
            if(h>=12)h-=12;
            double a,b;
            a=(30*h+30*m/60.0+30*s/3600.0);
            b=(6*m+6*s/60.0);
            double t=a-b;
            if(t>180) t=360-t;
            else if(t<-180) t=t+360;
            else if(t<0) t=-t;
            int p=t;
            printf("%d\n",p);
        }
    }
    return 0;
}
