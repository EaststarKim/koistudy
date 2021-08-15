#include <stdio.h>
int a[5][5],b[5][5],y=8,d[8][5],o[8][5],rr,rw;
void row(int x){
    int i,c;
    c=a[x][3];
    for(i=2;i>=0;--i)a[x][i+1]=a[x][i];
    a[x][0]=c;
}
void col(int x){
    int i,c;
    c=a[3][x];
    for(i=2;i>=0;--i)a[i+1][x]=a[i][x];
    a[0][x]=c;
}
void f(int x){
    if(x>=y)return;
    int flag=0;
    int i,j,h;
    for(i=0;i<4;++i){
        for(j=0;j<4;++j)if(a[i][j]==b[i][j])flag++;
    }
    h=x+5-y;
    if(flag<(h*4))return;
    if(flag==16&&x<y){
        for(i=0;i<x;++i){
            o[i][0]=d[i][0];
            o[i][1]=d[i][1];
            o[i][2]=d[i][2];
        }
        y=x;
    }
    else{
        for(i=0;i<4;++i){
            d[x][0]=1;
            d[x][1]=i+1;
            for(j=1;j<=3;++j){
                row(i);
                d[x][2]=j;
                f(x+1);
            }
            row(i);
        }
        for(i=0;i<4;++i){
            d[x][0]=2;
            d[x][1]=i+1;
            for(j=1;j<=3;++j){
                col(i);
                d[x][2]=j;
                f(x+1);
            }
            col(i);
        }
    }
}
int main(){
    int i,j;
    for(i=0;i<4;++i)for(j=0;j<4;j++)scanf("%d",a[i]+j);
    for(i=0;i<4;++i)for(j=0;j<4;j++)b[i][j]=(i*4)+(j+1);
    f(0);
    printf("%d\n",y);
    return 0;
}
