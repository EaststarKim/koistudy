#include <stdio.h>
int a[21]={0,1},n;
void f(int p){
    if(p>n)return;
    a[p]=a[p-1]+a[p-2];
    f(p+1);
}
void back(int p){
    int i;
    if(p>n)return;
    for(i=1;i<=a[n]-a[p];++i)printf(".");
    for(i=1;i<=a[p];++i)printf("*");
    puts("");
    back(p+1);
}
int main()
{
    scanf("%d",&n);
    f(2);
    back(1);
    return 0;
}
