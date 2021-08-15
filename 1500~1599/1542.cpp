#include <stdio.h>
int a[3][3]={{0,1,2},{2,0,1},{1,2,0}};
int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    if(!a[x][y])puts("Draw");
    else if(a[x][y]<2)puts("Win");
    else puts("Lose");
    return 0;
}
