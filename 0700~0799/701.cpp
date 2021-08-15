#include<stdio.h>      
#include<queue>      
std::priority_queue<int> a;      
int m[300100][2];      
int tmp[300100][2];      
int left[300100],p;      
int n;      
void sort(int start,int end){      
    if(end<start+2)return;      
    int mid=(start+end)/2;      
    sort(start,mid);      
    sort(mid,end);      
    int i,j,k;      
    i=start;      
    j=mid;      
    k=start;      
    for(;i<mid&&j<end;k++){      
        if(m[i][1]>m[j][1]){      
            tmp[k][0]=m[i][0];      
            tmp[k][1]=m[i][1];      
            i++;      
        }      
        else{      
            tmp[k][0]=m[j][0];      
            tmp[k][1]=m[j][1];      
            j++;      
        }      
    }      
    for(;i<mid;i++){      
        tmp[k][0]=m[i][0];      
        tmp[k][1]=m[i][1];      
        k++;      
    }      
    for(i=start;i<k;i++){      
        m[i][0]=tmp[i][0];      
        m[i][1]=tmp[i][1];      
    }      
}      
int main(){      
    scanf("%d",&n);      
    int i,ans,siz;      
    long long int total;      
    for(i=0;i<n;i++){      
        scanf("%d%d",&m[i][0],&m[i][1]);      
    }      
    sort(0,n);      
    for(total=siz=ans=i=0;i<n;i++){      
        a.push(m[i][0]);      
        siz++;      
        total+=m[i][0];      
        while(p&&total<=(long long int)siz*m[i][1]){      
            p--;      
            a.push(left[p]);      
            siz++;      
            total+=left[p];      
        }      
        if(total>(long long int)siz*m[i][1]){      
            left[p]=a.top();      
            p++;      
            total-=a.top();      
            a.pop();      
            siz--;      
        }      
        if(siz>ans){      
            ans=siz;      
        }      
    }      
    printf("%d",ans);      
}  