#include<stdio.h>   
#include<set>   
using namespace std;   
set<int> S;   
int main()   
{   
    int i,j,k;   
    for (k=0;k<3;k++){   
        scanf("%d",&j);   
        for (i=1;i*i<=j;i++){   
            if (j % i == 0){   
                S.insert(j/i);   
                S.insert(i);   
            }   
        }   
    }   
    while (!S.empty()){   
        printf ("%d ",*S.begin());   
        S.erase(S.begin());   
    }   
    return 0;   
}  