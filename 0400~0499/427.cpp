#include <stdio.h>
int main(){
    int t,x,y;
    scanf("%d%d%d",&t,&t,&t);
    while(t--){
        scanf("%d%d",&x,&y);
        if((x+y)%2){
            if(x<2||y<2||(x>2&&y>2))puts("G");
            else puts("s");
        }
        else{
            if(x&&y)puts("G");
            else puts("s");
        }
    }
    return 0;
}
