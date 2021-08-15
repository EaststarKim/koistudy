#include <stdio.h>
char a[8000];
int main(){
    int i,j,t,cnt=0;
    scanf("%s",a);
    for(i=0;a[i];++i){
        t=0;
        for(j=i;a[j];++j){
            t+=(a[j]=='('?1:-1);
            if(t<0)break;
            if(t==0)++cnt;
        }
    }
    printf("%d",cnt);
    return 0;
}
