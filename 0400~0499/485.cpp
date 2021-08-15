#include <stdio.h>   
char a[10000];      
int main()      
{      
    int i,j,n;      
    scanf("%d",&n);      
    for(i=0;i<n;++i)      
    {   
        a[i]='*';   
        printf("%s\n",a);      
    }      
    return 0;      
}  