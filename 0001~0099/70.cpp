#include <stdio.h>
int main()
{
    int k;
    aa:
    scanf("%d",&k);
    if(k){
        printf("%d\n",k);
        goto aa;
    }
}
