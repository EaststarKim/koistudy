#include <stdio.h>
void back(int n){
    int i;
    if(!n)return;
    back(n-1);
    for(i=1;i<=n;++i)printf("*");
    puts("");
    back(n-1);
    for(i=1;i<=n;++i)printf("*");
    puts("");
    back(n-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    back(n);
    return 0;
}
