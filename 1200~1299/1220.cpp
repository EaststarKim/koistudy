#include <stdio.h>
int a[]={0,0,1,2,1,1,0,2,0};
int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d",(a[y%8+1]-a[x%8]+3)%3);
    return 0;
}
