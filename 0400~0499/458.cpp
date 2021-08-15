#include<stdio.h>   
#define max(a,b) a>b? a:b   
int a[10001],ans[10001][501],answer;   
int main()   
{   
    int h,m,i,j;   
    scanf("%d%d",&h,&m);   
    for(i=0;i<h;i++)scanf("%d",a+i);   
    ans[0][m]=0;   
    ans[0][m-1]=a[0];   
    for(i=1;i<h;i++)   
    {   
        ans[i][0]=ans[i-1][1]+a[i];   
        for(j=1;j<m;j++)   
        {   
            ans[i][j]=max(ans[i-1][j-1],ans[i-1][j+1]+a[i]);   
        }   
        ans[i][m]=max(ans[i-1][m-1],ans[i-1][m]);   
    }   
    for(j=0;j<=m;j++)   
    {   
        if(answer<ans[h-1][j])answer=ans[h-1][j];   
    }   
    printf("%d",answer);
    return 0; 
}  