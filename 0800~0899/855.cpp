#include <stdio.h>
int a[10];
int main()
{
    int i,j,y,t;
    scanf("%d",&y);
    for(i=y+1;;++i)
    {
        t=i;
        while(t)
        {
            ++a[t%10];
            t/=10;
        }
        for(j=0;j<10;++j)
        {
            if(a[j]>1)break;
        }
        if(j>9)break;
        for(j=0;j<10;++j)a[j]=0;
    }
    printf("%d",i);
    return 0;
}
