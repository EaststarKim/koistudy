#include <stdio.h>
struct data{
    int x,y,d;
}f,c;
char a[11][11];
int x[]={-1,0,1,0},y[]={0,1,0,-1},cnt;
void next(data &t) {
    int r=t.x+x[t.d],c=t.y+y[t.d];
    if(r<0||r>9||c<0||c>9||a[r][c]=='*')t.d=(t.d+1)%4;
    else t.x=r,t.y=c;
}
int main(){
    int i,j;
    for(i=0;i<10;++i){
        scanf("%s",a[i]);
        for(j=0;j<10;++j){
            if(a[i][j]=='F')f.x=i,f.y=j;
            if(a[i][j]=='C')c.x=i,c.y=j;
        }
    }
    while(++cnt<1e4){
        next(f),next(c);
        if(f.x==c.x&&f.y==c.y)break;
    }
    if(cnt==1e4)cnt=0;
    printf("%d",cnt);
    return 0;
}
