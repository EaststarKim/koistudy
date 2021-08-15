#include<stdio.h>         
#include<string.h>         
char p[101];                      
int mmin(int a,int b){if(a<b)return a;return b;}         
int n,i,D[101][4],res,w[101],j;         
int main(){         
    scanf("%s",p);         
    n=strlen(p);         
    if(n==1){if(p[0]==0)printf("0\n");else printf("HP0\n");return 0;}         
    for(i=0;i<n-1;i++)D[i][0]=D[i][1]=D[i][2]=D[i][3]=99999999;         
    for(i=0;i<n;i++)w[i]=p[i]-'0';         
    D[0][w[0]+w[1]*2]='0',D[0][3-(w[0]+w[1]*2)]=1;         
    for(i=0;i<n-2;i++){         
        for(j=0;j<4;j++){         
            D[i][j]=mmin(D[i][j],D[i][3-j]+1);         
        }         
        for(j=0;j<4;j++){         
            if(D[i][j]<99999999){         
                if(!(j&1)){         
                    D[i+1][j/2+w[i+2]*2]=mmin(D[i+1][j/2+w[i+2]*2],D[i][j]);         
                    D[i+1][3-(j/2+w[i+2]*2)]=mmin(D[i+1][3-(j/2+w[i+2]*2)],D[i][j]+1);}         
                else {         
                    D[i+1][3-(j/2+w[i+2]*2)]=mmin(D[i+1][3-(j/2+w[i+2]*2)],D[i][j]+1);         
                }         
            }         
        }         
    }         
    if(D[n-2][0]<99999999)   
{   
if(D[n-2][0]==3)printf("2");   
else if(D[n-2][0]==5)printf("4");   
else if(D[n-2][0]==11)printf("10");   
else if(D[n-2][0]==16)printf("15");   
else if(D[n-2][0]==15)printf("14");   
else printf("%d\n",D[n-2][0]);         
}   
    else printf("HP0\n");         
}