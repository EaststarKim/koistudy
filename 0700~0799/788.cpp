#include <stdio.h>
int m[1010][1010],w,h,cnt,mxi,mni,t,a[510],mx,mn=2147483647;
int dr[]={-1,0,1,0},dc[]={0,1,0,-1};
void ff(int r,int c)
{
    int i,nr,nc;
    m[r][c]=0;
    ++cnt;
    for(i=0;i<4;++i)
    {
        nr=r+dr[i];
        nc=c+dc[i];
        if(nr<1||nr>h||nc<1||nc>w||m[nr][nc]!=t)continue;
        ff(nr,nc);
    }
}
int main()
{
    int i,j,n;
    scanf("%d%d%d",&n,&w,&h);
    for(i=1;i<=h;++i)
    {
        for(j=1;j<=w;++j)scanf("%d",&m[i][j]);
    }
    for(i=1;i<=h;++i)
    {
        for(j=1;j<=w;++j)
        {
            if(m[i][j])
            {
                cnt=0;
                t=m[i][j];
                ff(i,j);
                a[t]+=cnt*cnt;
            }
        }
    }
    for(i=1;i<=n;++i)
    {
        if(mx<a[i])mx=a[i],mxi=i;
        if(mn>a[i])mn=a[i],mni=i;
    }
    printf("%d %d %d %d",mxi,mx,mni,mn);
    return 0;
}
