
#include<stdio.h>

#include<algorithm>

int a[20005], c[15], cv[15];

int temp[15], ans, ansarr[20005];

int main () {

 int n,cn,i,j;

 scanf("%d",&n);

 for(i=1;i<=n;i++) scanf("%d",&a[i]);

 scanf("%d",&cn);

 for(i=1;i<=cn;i++) scanf("%d",&c[i]);

 std::sort(c+1,c+cn+1);

 for(i=1;i<cn;i++) cv[i]=c[i+1]-c[i];

 for(i=1;i<=n-cn+1;i++) {

  for(j=i;j<i+cn;j++) {

   temp[j-i+1]=a[j];

  }

  std::sort(temp+1,temp+cn+1);

  int flag=0;

  for(j=1;j<cn;j++) {

   if(temp[j+1]-temp[j]!=cv[j]) {

    flag=1;

    break;

   }

  }

  if (flag==0) ansarr[++ans]=i;

 }

 printf("%d\n",ans);

 for(i=1;i<=ans;i++) printf("%d\n",ansarr[i]);

 return 0;

}



