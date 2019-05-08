#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;
stack<char>s;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int i;
        getchar();
        for (i=1;i<=n;i++){
            while(!s.empty()){
                s.pop();
            }
            bool f=1;
            char a[129];
            gets(a);
            int l=strlen(a),j=0;
            if (!l) {printf("Yes\n");break;}
            else {
                while (f!=0&&j<l){
                    s.push(a[j]);
                    if(s.top()==')'){
                        s.pop();
                        if(s.empty()==1||s.top()!='(') {f=0;break;}
                        else s.pop();
                    }
                    else if(s.top()==']'){
                        s.pop();
                        if(s.empty()==1||s.top()!='[') {f=0;break;}
                        else s.pop();
                    }
                    j++;
                }
                if(s.empty()==0) f=0;
                if(f)printf("Yes\n");
                else printf("No\n");
            }
        }
    }
    return 0;
}
