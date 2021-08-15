#include <stdio.h>
int main(){
    int s=0,ans=0,a;
    for(;;){
        a=getchar();
        if(a<40)break;
        s+=a<41?1:-1;
        if(s<0)++s,++ans;
    }
    printf("%d",ans+s);
    return 0;
}
