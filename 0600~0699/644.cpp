#include <stdio.h>
#include <string.h>
char a[60];
int main(){
    int i,n;
    scanf("%s",a+2);
    n=strlen(a+2)+1;
    for(i=n;i>1;){
        if(a[i]=='C'){
            while(a[i]=='C')--i;
            if(i<2)break;
            if(a[i]=='H')--i;
            else if(a[i]=='O'){
                if(a[i-1]=='C')i-=2;
                else break;
            }
        }
        else if(a[i]=='O'){
            while(a[i]=='O')--i;
            if(i<2)break;
            if(a[i]=='H'){
                if(a[i-1]=='C')i-=2;
                else break;
            }
            else break;
        }
        else break;
    }
    if(i<2)puts("YES");
    else puts("NO");
    return 0;
}
