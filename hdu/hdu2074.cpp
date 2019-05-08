#include<stdio.h>

char pic[81][81];

int main(){
    int n,count=0;
    char a,b;
    while(scanf("%d %c %c",&n,&a,&b)!=EOF){
        if(count)printf("\n");
        count++;
        int i,j,h,l,c=1;
        char m;
        for(i=(n+1)/2;i>=1;i--){
            h=i;l=n+1-i;
            m=(c%2)?a:b;
            c++;
            for(j=h;j<=l;j++){
                pic[h][j]=pic[l][j]=pic[j][h]=pic[j][l]=m;
            }
        }
        pic[1][1]=pic[1][n]=pic[n][1]=pic[n][n]=' ';
        if(n==1)pic[1][1]=a;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                printf("%c",pic[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
