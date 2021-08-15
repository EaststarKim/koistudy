#include <stdio.h>   
int a[2][1001][1001],n,cnt,mn=2100000000;   
void back(int b,int w,int s,int p)   
{   
    if((s&&w>s)||(n-s&&w<s))return;   
    if(a[b][w][s]&&a[b][w][s]<p)return;   
    if(b&&w==n&&s==n)   
    {   
        if(mn>p)mn=p;   
        ++cnt;   
        return;   
    }   
    a[b][w][s]=p;   
    if(w>1)back(!b,n-w+2,n-s,p+1);   
    if(s>1)back(!b,n-w,n-s+2,p+1);   
    if(w&&s)back(!b,n-w+1,n-s+1,p+1);   
    if(w)back(!b,n-w+1,n-s,p+1);   
    if(s)back(!b,n-w,n-s+1,p+1);   
}   
int main()   
{   
    scanf("%d",&n);   
    a[0][n][n]=1;   
    back(0,n,n,1);   
    if(cnt)printf("%d\n%d",cnt,mn-1);   
    else printf("-1");   
    return 0;   
}  