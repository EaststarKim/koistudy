#include <stdio.h>
int a[9][9],chk[9],n,cnt;
void back(int p,int k){
    int i;
    chk[k]=1;
    if(p==n){
        if(a[k][0])++cnt;
        return;
    }
    for(i=1;i<n;++i)if(a[k][i]&&!chk[i]){
        chk[i]=1;
        back(p+1,i);
        chk[i]=0;
    }
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        for(j=0;j<n;++j)scanf("%1d",a[i]+j);
    }
    back(1,0);
    printf("%d",(cnt/2)%9901);
    return 0;
}
