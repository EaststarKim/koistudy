#include <stdio.h>
char a[5][3];
int main()
{
    scanf("%s%s%s%s%s",a[0],a[1],a[2],a[3],a[4]);
    if(a[0][0]=='.')puts("1");
    else if(a[0][1]=='.')puts("4");
    else if(a[3][2]=='.')puts("2");
    else if(a[2][0]=='.')puts("7");
    else if(a[2][1]=='.')puts("0");
    else if(a[1][0]=='.')puts("3");
    else if(a[1][2]=='.'){
        if(a[3][0]=='.')puts("5");
        else puts("6");
    }
    else{
        if(a[3][0]=='.')puts("9");
        else puts("8");
    }
    return 0;
}
