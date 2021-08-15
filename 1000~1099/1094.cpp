#include <stdio.h>
int a[21]={0,1},n;
void back(int p){
    int i;
    if(p>n)return;
    a[p]=a[p-1]+a[p-2];
    for(i=1;i<=a[p];++i)printf("*");
    puts("");
    back(p+1);
}
int main()
{
    scanf("%d",&n);
    puts("*");
    back(2);
    return 0;
}
