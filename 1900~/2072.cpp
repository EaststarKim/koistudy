#include <stdio.h>
int bit[1025][1025],n;
int sum(int x,int y){
    int i,j,s=0;
    for(i=x;i;i-=i&-i){
        for(j=y;j;j-=j&-j)s+=bit[i][j];
    }
    return s;
}
void update(int x,int y,int a){
    int i,j;
    for(i=x;i<=n;i+=i&-i){
        for(j=y;j<=n;j+=j&-j)bit[i][j]+=a;
    }
}
int main(){
    int t,x,y,a,b;
    for(;;){
        scanf("%d",&t);
        if(!t)scanf("%d",&n);
        else if(t<3){
            scanf("%d%d%d",&x,&y,&a);
            ++x,++y;
            if(t<2)update(x,y,a);
            else{
                scanf("%d",&b);
                ++a,++b;
                printf("%d\n",sum(a,b)-sum(a,y-1)-sum(x-1,b)+sum(x-1,y-1));
            }
        }
        if(t>2)return 0;
    }
}
