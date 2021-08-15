#include <stdio.h>
int main()
{
    int k;
    scanf("%d",&k);
    if(k>0)printf("plus\n");
    else printf("minus\n");
    if(k%2)printf("odd\n");
    else printf("even\n");
}
