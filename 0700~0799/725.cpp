#include<stdio.h>   
int p,a[150001],b[150001],k[1000][1000],l1,l2;   
int comb(int a,int b){   
    if(b==0) return 1;   
    if(a==0) return 0;   
    if(a<b) return 0;   
    return k[a][b];   
}   
void input(){   
    scanf("%d%d%d",&p,&l1,&l2);   
    for(int i=l1;i>0;i--) scanf("%d",&a[i]);   
    for(int i=l2;i>0;i--) scanf("%d",&b[i]);   
}   
void init(){   
    k[0][0]=k[1][0]=k[1][1]=1;   
    for(int i=2;i<=p;i++){   
        k[i][0]=1;   
        for(int j=1;j<=i;j++) k[i][j]=(k[i-1][j-1]+k[i-1][j])%p;   
    }   
}   
int calc(){   
    int prod=1;   
    for(int i=1;i<=150000;i++) prod=(prod*comb(a[i],b[i]))%p;   
    return prod;   
}   
int main(){   
    input();   
    init();   
    printf("%d",calc());   
    return 0;   
}  