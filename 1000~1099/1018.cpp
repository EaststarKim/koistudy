#include <stdio.h>
int a[1048576],chk[1048576];
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<(1<<n);++i)a[i]=-1;
    chk[0]=1;
    a[0]=0;
    i=1;
    for(;i<(1<<n);){
        if((a[i]==-1)&&!chk[(a[i-1]<<1)&((1<<n)-1)]){
            chk[(a[i-1]<<1)&((1<<n)-1)]=1;
            a[i]=(a[i-1]<<1)&((1<<n)-1);
            ++i;
            continue;
        }
        if(!chk[((a[i-1]<<1)|1)&((1<<n)-1)]){
            chk[((a[i-1]<<1)|1)&((1<<n)-1)]=1;
            a[i]=((a[i-1]<<1)|1)&((1<<n)-1);
            ++i;
            continue;
        }
        a[i]=-1;
        --i;
        chk[a[i]]=0;
    }
    scanf("%d",&n);
    printf("%d",a[n]);
    return 0;
}
