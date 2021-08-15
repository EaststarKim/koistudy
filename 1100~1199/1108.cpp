#include <stdio.h>
#include <string.h>
char a[10010];
int main()
{
    int i,n;
    scanf("%s",a);
    n=strlen(a);
    for(i=0;i<n;++i){
        if(a[i]=='A'||a[i]=='B')printf("A.B");
        else printf("%c",a[i]);
    }
    return 0;
}
