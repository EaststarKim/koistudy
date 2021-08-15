#include <stdio.h>
int a[4][2];
int main(){
    int i;
    for(i=0;i<4;++i){
        scanf("%d%d",a[i],a[i]+1);
        a[0][0]+=a[i][1]-a[i][0];
    }
    for(i=0;i<3;++i){
        printf("%d\n",a[i][0]-a[i][1]);
        a[i+1][0]+=a[i][0]-a[i][1];
    }
    return 0;
}
