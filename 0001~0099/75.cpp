#include <stdio.h>
int main()
{
    char a,b='a';
    scanf("%c",&a);
    do{
        printf("%c\n",b);
        ++b;
    }while(b<=a);
}
