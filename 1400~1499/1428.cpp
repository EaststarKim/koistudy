#include <stdio.h>
int main(){
    int x,y,s;
    scanf("%d%d%d",&x,&y,&s);
    s-=(x<0?-x:x)+(y<0?-y:y);
    puts(s<0||s%2?"No":"Yes");
    return 0;
}
