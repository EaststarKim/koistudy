#include <stdio.h>
int a[1010][1010],cnt;
int main()
{
    int x,y,c,r,k,sw;
    scanf("%d%d%d",&c,&r,&k);
    if(k>r*c){
        puts("0");
        return 0;
    }
    x=y=sw=1;
    while(1){
        for(;x<=r&&x>0&&!a[x][y];x+=sw){
            a[x][y]=++cnt;
            if(cnt==k)break;
        }
        if(cnt==k)break;
        x-=sw;
        y+=sw;
        for(;y<=c&&y>0&&!a[x][y];y+=sw){
            a[x][y]=++cnt;
            if(cnt==k)break;
        }
        if(cnt==k)break;
        y-=sw;
        sw*=-1;
        x+=sw;
    }
    printf("%d %d",y,x);
    return 0;
}
