#include <stdio.h>
int mul(int a,int b,int c){
    if(!a)return c;
    if(a%2)c+=b;
    return mul(a/2,b*2,c);
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",mul(a,b,0));
    return 0;
}
