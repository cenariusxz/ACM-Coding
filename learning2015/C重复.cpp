#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        getchar();
        for(int j=1;j<=n;j++){
            stack <char> s;
            bool f=1;
            char a[129];
            gets(a);
            int l=strlen(a);
            if(!l){
                printf("Yes\n");
                continue;
            }
            else {
                for(int i=0;i<l&&f==1;i++){
                    if(a[i]=='('||a[i]=='[')s.push(a[i]);
                    else if(a[i]==')'){
                        if(s.empty()||s.top()!='('){
                            f=0;
                            break;
                        }
                        else s.pop();
                    }
                    else if(a[i]=']'){
                        if(s.empty()||s.top()!='['){
                            f=0;
                            break;
                        }
                        else s.pop();
                    }
                }
            }
            if(!s.empty())f=0;
            if(f)printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
