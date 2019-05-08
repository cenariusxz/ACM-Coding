#include<stdio.h>
int main(){
    char buf[512];
    sscanf("iios/12DDWDFF@122", "%*[^/]/%[^@]", buf);
    printf("%s\n",buf);
    sscanf("1468 456 world","%*s%s", buf);
    printf("%s\n", buf);
    return 0;
}
