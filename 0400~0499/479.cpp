#include <stdio.h>   
#include <algorithm>   
using namespace std;   
#define MAX 10000010;   
struct G   
{   
    int x,y,z;   
    bool operator<(const G&a)const{   
        return x<a.x;   
    }   
}l[200010];   
int s[20010],d[20010],chk[20010];   
struct data   
{   
    int d,p;   
    bool operator<(const data&a)const{   
        return d>a.d;   
    }   
}dis[20010];   
int main()   
{   
    int i,n,m,mv,k=1;   
    scanf("%d%d",&n,&m);   
    for(i=1;i<=m;++i)   
    {   
        scanf("%d%d%d",&l[i].x,&l[i].y,&l[i].z);   
        l[m+i].x=l[i].y,l[m+i].y=l[i].x,l[m+i].z=l[i].z;   
    }   
    m*=2;   
    sort(l+1,l+m+1);   
    for(i=1;i<=m;++i)   
    {   
        if(l[i].x!=l[i-1].x)s[l[i].x]=i;   
    }   
    for(i=1;i<=n;++i)d[i]=MAX;   
    d[1]=0;   
    dis[0].d=0;   
    dis[0].p=1;   
    while(1)   
    {   
        mv=dis[0].p;   
        pop_heap(dis,dis+k);   
        --k;   
        if(chk[mv])continue;   
        if(mv==n)
		{
			printf("%d",d[n]);   
			return 0;   
		}   
        chk[mv]=1;   
        for(i=s[mv];l[i].x==mv;++i)   
        {   
            if(!chk[l[i].y]&&d[l[i].y]>d[mv]+l[i].z){   
                d[l[i].y]=d[mv]+l[i].z;   
                dis[k].d=d[l[i].y];   
                dis[k].p=l[i].y;   
                ++k;   
                push_heap(dis,dis+k);   
            }   
        }   
        if(!k)   
        {   
            printf("Impossible");   
            return 0;   
        }   
    } 
}