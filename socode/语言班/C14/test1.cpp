#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[10005];


int main(){
  scanf("%s",s);
  int n =strlen(s);
  for(int i =0;i<n;++i){
    if(s[i]>='A' && s[i]<='Z'){
      printf("%c",s[i]);
    }
    else printf("%c",s[i]-'a'+'A');
  }
  printf("\n");
  for(int i =0;i<n;++i){
    if(s[i]>='A' && s[i]<='Z'){
      printf("%c",s[i]-'A'+'a');
    }
    else printf("%c",s[i]);
  }
    return 0;
}

