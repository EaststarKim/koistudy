#include <stdio.h>
int a[10];
char c[110],t[110];
int main()
{
    int i,j,n,q,l,r,cp,dp,p;
    scanf("%d%d",&n,&q);
    scanf("%s",c+1);
    for(i=1;i<=q;++i)
    {
        scanf("%d%d",&l,&r);
        cp=l;
        dp=1;
        p=0;
        sscanf(c+1,"%s",t+1);
        while(l<=cp&&cp<=r)
        {
            if(t[cp]>59)
            {
                if(t[cp]=='>')dp=1;
                else dp=-1;
                if(t[p]>59)t[p]=47;
                p=cp;
                cp+=dp;
            }
            else if(t[cp]>47)++a[t[cp]-48],--t[cp],p=cp,cp+=dp;
            else
            {
                while(t[cp]==47)cp+=dp;
            }
        }
        for(j=0;j<10;++j)printf("%d ",a[j]),a[j]=0;
        printf("\n");
    }
    return 0;
}
