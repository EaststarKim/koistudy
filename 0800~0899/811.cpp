#include <stdio.h>
#include <stdlib.h>
int dis(int a,int b,int c,int d){return abs(a-c)+abs(b-d);}
int main(){
    int i,m,s,x,y,top,mid,bot,rm,rs,bm,bs;
    scanf("%d%d%d%d%d%d%d%d%d%d%d",&m,&s,&x,&y,&top,&mid,&bot,&rm,&rs,&bm,&bs);
    s+=m*60,rs+=rm*60,bs+=bm*60;
    for(;;){
        int gt=1e3,gi,bt=1e3,bi;
        if(mid&&dis(x,y,40,40)<gt)gt=dis(x,y,40,40),gi=0;
        if(bot&&dis(x,y,80,0)<gt)gt=dis(x,y,80,0),gi=1;
        if(top&&dis(x,y,0,80)<gt)gt=dis(x,y,0,80),gi=2;
        if(rs<=s&&dis(x,y,40,20)<bt)bt=dis(x,y,40,20),bi=0;
        if(bs<=s&&dis(x,y,20,40)<bt)bt=dis(x,y,20,40),bi=1;
        if(gt>bt){
            if(bi)bs=1e9,x=20,y=40,puts("Blue");
            else rs=1e9,x=40,y=20,puts("Red");
            s+=bt;
        }
        else{
            if(gt==1e3)break;
            if(!gi)mid=0,x=y=40,puts("Mid");
            else if(gi<2)bot=0,x=80,y=0,puts("Bot");
            else top=0,x=0,y=80,puts("Top");
            s+=gt;
        }
    }
    printf("%d %d",s/60,s%60);
    return 0;
}
