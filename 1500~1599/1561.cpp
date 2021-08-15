#include <stdio.h>
int x[]={0,2,4,5,7,9,11};
char *a="WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW",*b="CDEFGAB";
char c[30];
int main(){
    int i,j;
    scanf("%s",c);
    for(i=0;i<7;++i){
        for(j=0;j<20;++j)if(a[j+x[i]]!=c[j])break;
        if(j>19)break;
    }
    printf("%c",b[i]);
    return 0;
}
