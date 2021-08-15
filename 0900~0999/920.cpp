#include <stdio.h>
int a[30];
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<28;++i)a[i]=a[i-1]*2+i+2;
    for(i=27;i>0;){
        if(n>=a[i]){
            n-=a[i];
            if(n>=i+3)n-=i+3;
            else break;
        }
        else --i;
    }
    if(n==1)puts("m");
    else puts("o");
    return 0;
}
