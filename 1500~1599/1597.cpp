#include <stdio.h>
int main(){
    int a,t;
    char b;
    scanf("%d %c",&a,&b);
    for(;a>9;){
        for(t=0;a;a/=10)t+=a%10;
        a=t;
    }
    puts(a==b-65?"match":"error");
    return 0;
}
