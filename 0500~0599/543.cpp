#include<stdio.h>      
int abs (int n) {      
    if (n<0) return -n;      
    else return n;      
}      
int main () {      
    int i,j;      
    int x1,x2,y1,y2,d1,d2;      
    int ans=0;      
    scanf("%d %d %d %d %d %d",&x1,&y1,&d1,&x2,&y2,&d2);      
    if (d1>d2) {       
        for(i=x2-d2;i<=x2+d2;i++) {      
            int temp=d2-abs(x2-i);      
            j=y2-temp;      
            if(i>=0 && j>=0 && abs(x1-i)+abs(y1-j)==d1) ans++;      
            if (temp!=0) {      
                j=y2+temp;      
                if(i>=0 && j>=0 && abs(x1-i)+abs(y1-j)==d1) ans++;      
            }      
        }      
    }      
    else {      
        for(i=x1-d1;i<=x1+d1;i++) {      
            int temp=d1-abs(x1-i);      
            j=y1-temp;      
            if(i>=0 && j>=0 && abs(x2-i)+abs(y2-j)==d2) ans++;      
            if (temp!=0) {      
                j=y1+temp;      
                if(i>=0 && j>=0 && abs(x2-i)+abs(y2-j)==d2) ans++;      
            }      
        }      
    }      
    printf("%d",ans);      
    return 0;      
}  