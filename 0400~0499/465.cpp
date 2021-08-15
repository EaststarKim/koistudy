
#include<stdio.h>

#include<string.h>

int a[100],ans=-1;

char s1[50],s2[50];

int f(char s[], int k) {

 int n=strlen(s),i;

 int ret=0, gop=1;

 for(i=n-1;i>=0;i--) {

  ret+=(s[i]-'0')*gop;

  gop*=k;

 }

 return ret;

}

int main () {

 scanf("%s %s",s1,s2);

 int i,j,len1=strlen(s1),len2=strlen(s2);

 for(i=0;i<len2;i++) {

  if (s2[i]=='0') {

   s2[i]='1'; a[2*i+1]=f(s2,3);

   s2[i]='2'; a[2*i+2]=f(s2,3);

   s2[i]='0';

  }

  else if (s2[i]=='1') {

   s2[i]='0'; a[2*i+1]=f(s2,3);

   s2[i]='2'; a[2*i+2]=f(s2,3);

   s2[i]='1';

  }

  else {

   s2[i]='0'; a[2*i+1]=f(s2,3);

   s2[i]='1'; a[2*i+2]=f(s2,3);

   s2[i]='2';

  }

 }

 for(i=0;i<len1;i++) {

  if (s1[i]=='0') s1[i]='1';

  else if (s1[i]=='1') s1[i]='0';

  int temp=f(s1,2);

  for(j=1;j<=2*len2;j++) {

   if (temp==a[j]) {

    ans=temp;

    break;

   }

  }

  if (ans>=0) break;

  if (s1[i]=='0') s1[i]='1';

  else if (s1[i]=='1') s1[i]='0';

 }

 printf("%d",ans);

 return 0;

}

