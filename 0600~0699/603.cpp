#include <stdio.h>      
int a1,b1,a[5091],b[5091],cnt,x,sm;      
int main()   
{      
     int i,j;   
     scanf("%d%d",&a1,&b1);      
     for(i=0;i<a1;i++){scanf("%d",&a[i]);}      
     for(i=0;i<b1;i++){scanf("%d",&b[i]);}      
     for(i=0;i<b1;i++){      
         sm=0;      
         x=b[sm+i];      
         for(j=0;j<a1;j++){      
             if(x==a[j]){      
                 sm++;      
                 x=b[sm+i];      
             }      
         }      
         if(cnt<sm)cnt=sm;      
         if(sm==b1-i)break;      
     }      
     printf("%d",cnt);   
     return 0;   
}  