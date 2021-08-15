#include <stdio.h>
int f(int x,int y){return (0<x&&x<4&&y==0)||(x==2&&y==1);}
int main(){
    int i,n,m,x,y,a,b,t;
    scanf("%d",&n);
    for(;n--;){
        scanf("%d%d%d",&m,&x,&y);
        for(i=t=1;i<m;++i)t*=5;
        for(;t;t/=5){
            a=x/t,b=y/t;
            if(f(a,b)){
                puts("crystal");
                break;
            }
            if(a==1&&b==1)x-=t,y-=t;
            else if(a==2&&b==2)x-=t*2,y-=t*2;
            else if(a==3&&b==1)x-=t*3,y-=t;
            else{
                puts("empty");
                break;
            }
        }
        if(!t)puts("empty");
    }
    return 0;
}
