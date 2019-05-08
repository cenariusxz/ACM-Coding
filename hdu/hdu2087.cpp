#include<stdio.h>
#include<string.h>

int main(){
    char a[1005],b[1005];
    while(scanf("%s",a)!=EOF&&a[0]!='#'){
        scanf("%s",b);
        getchar();
        int la=strlen(a),lb=strlen(b);
        int ans=0,i,j,p=0;
        for (i=0,j=0;i<la;i++,j++){
            if(j==1) p=i;
            if (a[i]!=b[j]) {
                if(j!=0) i=p-1;
                j=-1;
            }
            else {
                if (j==lb-1) {
                    ans++;
                    j=-1;
                }
            }
        }
        printf ("%d\n",ans);
    }
    return 0;
}
