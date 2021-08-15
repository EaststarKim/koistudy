#include <stdio.h>
int ans[3005][3005];
struct store
{
    int v,t;
}a[3005];
int main()
{
    int n,t,s,i,j;
    long long int max=0;
    scanf("%d %d %d",&n,&t,&s);
    for(i=1;i<=n;i++)
    scanf("%d %d",&a[i].v,&a[i].t);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=t;j++)
        {
            if(!(j-a[i].t < s && j > s) && j >= a[i].t) ans[i][j] = ans[i-1][j-a[i].t] + a[i].v;
            if(ans[i][j] < ans[i][j-1]) ans[i][j] = ans[i][j-1];
            if(ans[i][j] < ans[i-1][j]) ans[i][j] = ans[i-1][j];
            if(max < ans[i][j]) max = ans[i][j];
        }
    }
    printf("%lld",max);
    return 0;
}