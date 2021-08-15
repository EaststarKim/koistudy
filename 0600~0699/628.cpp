#include <stdio.h>      
char a[1010][30],c[30],ans[30];      
int t[30],b[30];      
int main()      
{      
    int i,j,k,n,m;      
    scanf("%d%d",&k,&n);      
    scanf(" %s",c+1);      
    for(i=1;i<=n;++i)      
    {      
        scanf(" %s",a[i]+1);      
        if(a[i][1]=='?')m=i;      
    }      
    for(j=1;j<=k;++j)      
    {      
        t[j]=j;      
        for(i=1;i<m;++i)      
        {      
            if(a[i][t[j]-1]=='-')--t[j];      
            else if(a[i][t[j]]=='-')++t[j];      
        }      
    }      
    for(j=1;j<=k;++j)      
    {      
        b[c[j]-64]=j;      
        for(i=n;i>m;--i)      
        {      
            if(a[i][b[c[j]-64]-1]=='-')--b[c[j]-64];      
            else if(a[i][b[c[j]-64]]=='-')++b[c[j]-64];      
        }      
    }      
    for(i=1;i<=k;++i)      
    {      
        if(ans[t[i]-1]=='-'&&ans[t[i]]=='-')break;      
        if(ans[t[i]-1]=='-')      
        {      
            if(t[i]-1==b[i])continue;      
            else break;      
        }      
        if(ans[t[i]]=='-')      
        {      
            if(t[i]+1==b[i])continue;      
            else break;      
        }      
        if(t[i]==b[i])      
        {      
            ans[t[i]-1]=ans[t[i]]='*';      
            continue;      
        }      
        if(t[i]+1==b[i])      
        {      
            ans[t[i]]='-';      
            continue;      
        }      
        if(t[i]-1==b[i])      
        {      
            ans[t[i]-1]='-';      
            continue;      
        }      
        break;            
    }      
    if(i>k)      
    {      
        for(i=1;i<k;++i)      
        {      
            if(!ans[i])printf("*");      
            else printf("%c",ans[i]);      
        }      
    }      
    else for(i=1;i<k;++i)printf("x");      
    return 0;      
}  