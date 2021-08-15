#include <stdio.h>   
#include <string.h>   
int a[201],b[201],x[201],n,m,y,z;   
char c[201],d[201],t[201];
void change()   
{   
    int i;   
    n=strlen(c);   
    m=strlen(d);   
    for(i=y;i<n;++i)a[i+1-y]=c[i]-48;   
    for(i=z;i<m;++i)b[i+1-z]=d[i]-48;   
}   
void plus()   
{   
    int i;   
    if(y)--n;   
    if(z)--m;   
    for(i=1;i<=n;++i)x[i]=a[i];   
    for(i=0;i<m;++i)x[n-i]+=b[m-i];   
    for(i=n;i>0;--i)x[i-1]+=x[i]/10,x[i]%=10;   
}   
void minus()   
{   
    int i;   
    if(y)--n;   
    if(z)--m;   
    for(i=1;i<=n;++i)x[i]=a[i];   
    for(i=0;i<m;++i)x[n-i]-=b[m-i];   
    for(i=n;i>0;--i)   
    {   
        if(x[i]<0)   
        {   
            x[i]+=10;   
            --x[i-1];   
        }   
    }   
}   
void output()   
{   
    int i;   
    for(i=0;i<=n;++i)   
    {   
        if(x[i])break;   
    }   
    if(i>n)printf("0");   
    else  
    {   
        if(y)printf("-");   
        for(;i<=n;++i)printf("%d",x[i]);   
        printf("\n");   
    }   
}   
int main()   
{   
    int tmp;   
    scanf("%s %s",c,d);   
    n=strlen(c);   
    m=strlen(d);   
    if(c[0]=='-')y=1,--n;   
    if(d[0]=='-')z=1,--m;   
    if(n<m||(n==m&&strcmp(c,d)<0))   
    {   
        strcpy(t,c);   
        strcpy(c,d);   
        strcpy(d,t);   
        tmp=y,y=z,z=tmp;   
    }   
    change();   
    if(y==z)plus();   
    else minus();   
    output();   
    return 0;   
}  