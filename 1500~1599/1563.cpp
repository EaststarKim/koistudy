#include <stdio.h>
char a[410],tmp[410];
int main(){
    int i,j,t,cnt=0;
    scanf("%s",a);
    for(i=0;a[i];++i){
        t=0;
        for(j=i;a[j];++j){
            t+=(a[j]=='('?1:-1);
            if(t<0)break;
            tmp[j-i]=a[j];
            if(t==0){
                tmp[j-i+1]=0;
                puts(tmp);
                ++cnt;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
