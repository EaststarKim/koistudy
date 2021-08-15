#include <stdio.h>
void output(int n){
    if(n>9)printf("%c",'A'+n-10);
    else printf("%d",n);
}
void f(int n,int k){
    if(n<k){
        output(n);
        return;
    }
    f(n/k,k);
    output(n%k);
}
int main()
{
    int i,j,b,t=1;
    scanf("%d",&b);
    for(i=1;i<301;++i){
        while(t<=i*i)t*=b;
        t/=b;
        for(j=1;j<=t&&(i*i%(j*b))/j==(i*i%(t/j*b))/(t/j);j*=b);
        if(j>t){
            f(i,b);
            printf(" ");
            f(i*i,b);
            puts("");
        }
    }
    return 0;
}
