#include <stdio.h>
int n, k, cnt;  
int main(){   
    scanf("%d%d", &n, &k);   
    cnt = n/k;   
    if(n-cnt*k >= (k+1)/2) printf("%d\n", cnt*-~cnt*k);   
    else printf("%d\n", cnt*cnt*k);   
    return 0;   
}  
