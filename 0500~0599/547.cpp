#include <stdio.h>   
  
int n, m, k, t, now;   
long long sum, mul=1;   
bool dir;   
  
int main(){   
    scanf("%d%d%d", &n, &m, &k);   
  
    int i;   
    for(i=0; i<m; i++){   
        scanf("%d", &t);   
        now+=dir?-1:1;   
        if(now == 0) now = n;   
        if(now > n) now = 1;   
  
        if(t == 10001) dir = !dir;   
        else if(t == 10002) mul *= 2;   
        else{   
            sum += t*mul;   
            if(sum%11 == 0 || sum >= k) break;   
            mul = 1;   
        }   
    }   
  
    if(i == m) printf("0\n");   
    else printf("%d\n", now);   
  
    return 0;   
}