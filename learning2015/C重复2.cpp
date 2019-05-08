#include<stdio.h>
#include<stack>
using namespace std;

bool run(){
    stack<char>s;
    char c,c2;
    bool f=1;
    for(;;){
        c=getchar();
        if(c=='\n')break;
        if(f){
            if(c=='('||c=='[')s.push(c);
            else{
                if(s.empty()){
                    f=0;
                    continue;
                }
                c2=s.top();
                s.pop();
                if(c==')'&&c2!='(') f=0;
                else if(c==']'&&c2!='[') f=0;
            }
        }
    }
    if(!s.empty())f=0;
    return f;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        getchar();
        for(int i=0;i<n;i++){
            printf(run()?"Yes\n":"No\n");
        }
    }
    return 0;
}
