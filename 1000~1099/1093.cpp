#include <stdio.h>
int n,m;
void back(int p,int t){
    int i,j;
    if(p>n){
        m=t;
        return;
    }
    back(p+1,t*3);
    for(i=1;;){
        for(j=1;j<t;++j)printf(".");
        i+=j;
        if(i>m)break;
        printf("*");
    }
    puts("");
}
int main()
{
    scanf("%d",&n);
    back(1,1);
    return 0;
}
