#include <stdio.h>
#include <string.h>
#define MAX 1001

int n,k,s,e,b[2][1010],q[1010];
char a[1010][30];

void search(int p)
{
    if(p==s)
    {
        printf("%d ",p);
        return;
    }
    search(b[1][p]);
    printf("%d ",p);
}
void BFS()
{
    int i,j,f=0,r=1,p=s,cnt;
    while(f<r)
    {
        p=q[++f];
        for(i=1;i<=n;++i)
        {
            if(b[0][i]<=b[0][p]+1)continue;
            cnt=0;
            for(j=0;j<k;++j)
            {
                if(a[p][j]!=a[i][j])++cnt;
                if(cnt>1)break;
            }
            if(j<k)continue;
            b[0][i]=b[0][p]+1;
            b[1][i]=p;
            q[++r]=i;
        }
    }
}

int main()
{
    int i;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;++i)scanf("%s",a[i]),b[0][i]=MAX;
    scanf("%d%d",&s,&e);
    b[0][s]=0;
    q[1]=s;
    BFS();
    if(b[0][e]<MAX)search(e);
    else printf("-1");
    return 0;
}
