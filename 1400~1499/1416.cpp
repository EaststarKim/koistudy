#include <stdio.h>
char a[100010];
int i,t,ans;
int main(){
    scanf("%s",a);
    for(;a[i];++i){
        if(a[i]==')'){
            --t;
            if(a[i-1]=='(')ans+=t-1;
        }
        else ++t,++ans;
    }
    printf("%d",ans);
    return 0;
}
