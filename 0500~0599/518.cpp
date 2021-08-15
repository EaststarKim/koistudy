#include <stdio.h>   
#include <algorithm>   
using namespace std;                //by august14   
struct point{int x,y;}S[222],A[1111];   
bool cmp(const point& a, const point& b){return (a.y == b.y) ? a.x < b.x : a.y < b.y;}   
int N,M;   
  
int main()   
{   
    int i,j,k;   
  
    scanf ("%d",&N);   
    for (i=0;i<N;i++) scanf ("%d %d",&S[i].x,&S[i].y);   
    sort(S,S+N,cmp);   
  
    scanf ("%d",&M);   
    for (i=0;i<M;i++) scanf ("%d %d",&A[i].x,&A[i].y);   
    sort(A,A+M,cmp);   
  
    for (i=0;i<M;i++){   
        j = 1;   
        for (k=i+1;k<M&&j<N;k++){   
            if (S[0].x-S[j].x == A[i].x-A[k].x &&   
                S[0].y-S[j].y == A[i].y-A[k].y) j++;   
        }   
  
        if (j == N){   
            printf ("%d %d\n",A[i].x-S[0].x,A[i].y-S[0].y);   
            break;   
        }   
    }   
  
    return 0;   
}   
    