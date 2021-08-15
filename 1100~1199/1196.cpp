#include <stdio.h>
int main(){
    int x=0,y=0,c,r,a,b;
    scanf("%d%d",&c,&r);
    for(;;){
        scanf("%d%d",&a,&b);
        if(!a&&!b)break;
        x+=a,y+=b;
        if(x<0)x=0;
        if(x>c)x=c;
        if(y<0)y=0;
        if(y>r)y=r;
        printf("%d %d\n",x,y);
    }
    puts("end");
    return 0;
}
