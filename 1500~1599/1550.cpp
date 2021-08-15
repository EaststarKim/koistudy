#include <stdio.h>
int a[6][6],ans;
int main(){
    int i,j,t;
    for(i=1;i<6;++i){
        for(j=1;j<6;++j)scanf("%d",a[i]+j),a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    }
    for(i=3;i<6;++i){
        for(j=3;j<6;++j){
            t=a[i][j]-a[i-3][j]-a[i][j-3]+a[i-3][j-3];
            if(ans<t)ans=t;
        }
    }
    printf("%d",ans);
    return 0;
}
