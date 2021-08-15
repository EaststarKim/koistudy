 #include<stdio.h>

    int d[10005][2];

    int main () {

        int n,i,x;

        int prev=0,prevk=0,k=0;

        scanf("%d",&n);

        for(i=1;i<=n;i++){

            scanf("%d",&x);

            if (x!=prev) {

                d[k][0]=prev; // jongryu

                d[k++][1]=prevk; // gesu

                prev=x;

                prevk=1;

            }

            else prevk++;

        }

        d[k][0]=prev;

        d[k][1]=prevk;

        int max=0;

        for(i=1;i<=k;i++) {

            int ans=0;

            if (d[i][1]==1) {

                ans=1;

                int temp=1;

                while(1) {

                    if (d[i-temp][0] == d[i+temp][0] && d[i-temp][1]+d[i+temp][1]>3) {

                        ans+=d[i-temp][1]+d[i+temp][1];

                        temp++;

                    }

                    else break;

                }

            }

            else if (d[i][1]==3) {

                if (d[i-1][1]==1 && i>1) {

                    ans=4;

                    int temp=1;

                    while (1) {

                        if (d[i-temp-1][0] == d[i+temp][0] && d[i-temp-1][1]+d[i+temp][1]>3) {

                            ans+=d[i-temp-1][1]+d[i+temp][1];

                            temp++;

                        }

                        else break;

                    }

                }

                else if (d[i+1][1]==1 && i<k) {

                    ans=4;

                    int temp=1;

                    while (1) {

                        if (d[i-temp][0] == d[i+temp+1][0] && d[i-temp][1]+d[i+temp+1][1]>3) {

                            ans+=d[i-temp-1][1]+d[i+temp+1][1];

                            temp++;

                        }

                        else break;

                    }

                }

                else {

                    int ans1=4;

                    int temp=1;

                    d[i-1][1]--;

                    while(1) {

                        if (d[i-temp][0] == d[i+temp][0] && d[i-temp][1]+d[i+temp][1]>3) {

                            ans1+=d[i-temp][1]+d[i+temp][1];

                            temp++;

                        }

                    else break;

                    }

                    d[i-1][1]++;

                    int ans2=4; temp=1;

                    d[i+1][1]--;

                    while(1) {

                        if (d[i-temp][0] == d[i+temp][0] && d[i-temp][1]+d[i+temp][1]>3) {

                            ans2+=d[i-temp][1]+d[i+temp][1];

                            temp++;

                        }

                    else break;

                    }

                    d[i+1][1]++;

                    if (ans1>ans2) ans=ans1;

                    else ans=ans2;

                }

        }

        if (ans>max) max=ans;

        }

        printf("%d",n-max);

        return 0;

    }





