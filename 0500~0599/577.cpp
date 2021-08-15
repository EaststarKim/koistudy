#include <stdio.h>   
#define MN 100001   
  
int n, a, b;   
int d[MN], t[MN];   
int main()   
{   
    int i, p, k;   
  
    scanf("%d%d%d", &n, &a, &b);   
    if (a+b-1 <= n && n <= (long long)a*b) {   
        for (i = 1; i <= n; i++) d[i] = n+1-i;   
        k = p = n;   
        while (k-(a-1) > b) {   
            k -= a-1; p -= a;   
            for (i = 1; i <= a; i++) t[p+i] = d[p+a+1-i];   
            for (i = 1; i <= a; i++) d[p+i] = t[p+i];   
        }   
        a = k-b+1; p -= a;   
        for (i = 1; i <= a; i++) t[p+i] = d[p+a+1-i];   
        for (i = 1; i <= a; i++) d[p+i] = t[p+i];   
        for (i = 1; i <= n; i++)   
            printf("%d ", d[i]);   
    }   
    else  
        printf("-1");   
    return 0;   
}  