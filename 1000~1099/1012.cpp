#include <stdio.h>
#define SZ 10000
int n,now,pass,q[SZ],chk[SZ],p;
void BFS(){
    int i,f=0,r=1;
    q[1]=now;
    chk[now]=0;
    while(f<r){
        p=q[++f];
        if(p==pass){
            printf("%d",chk[pass]);
            return;
        }
        for(i=1;i<SZ;i*=10){
            if(!chk[(SZ+p+i)%SZ])q[++r]=(SZ+p+i)%SZ,chk[(SZ+p+i)%SZ]=chk[p]+1;
            if(!chk[(SZ+p-i)%SZ])q[++r]=(SZ+p-i)%SZ,chk[(SZ+p-i)%SZ]=chk[p]+1;
        }
    }
}
int main()
{
    int i,k;
    scanf("%d%d%d",&now,&pass,&n);
    for(i=1;i<=n;++i){
        scanf("%d",&k);
        chk[k]=-1;
    }
    BFS();
    if(p!=pass)puts("-1");
    return 0;
}
