#include<stdio.h>      
int n;      
int code[1010];      
int codeb[2010];      
char str[2010];      
int f(int a,int b){      
    if(a==b)return 1;      
    int i,j=0,k=0;      
    for(i=a;i<b;i++){      
        j+=codeb[i];      
        k+=codeb[i]*i;      
    }      
    if(j!=(b-a)/2)return 0;      
    if(k!=j*(a+b)/2)return 0;      
    for(i=a+1;i<=(a+b)/2;i++){      
        if(codeb[i]){      
            codeb[i]--;      
            if(f(a+1,2*i-a-1)==1&&f(2*i-a,b)==1){      
                str[a]='[';      
                str[2*i-a-1]=']';      
                codeb[i]++;      
                return 1;      
            }      
            codeb[i]++;      
        }      
    }      
    return 0;      
}      
int main()   
{      
    int i;      
    scanf("%d",&n);      
    for(i=0;i<n;i++){      
        scanf("%d",&code[i]);      
        codeb[code[i]]++;      
    }      
    if(f(0,2*n)==0)printf("ERR");      
    printf("%s",str);     
    return 0;   
}  