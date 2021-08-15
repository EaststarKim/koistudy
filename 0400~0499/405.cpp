#include <stdio.h>

#include <algorithm>

using namespace std;

struct plant

{

    int x,y;

}pot[100005];




struct range

{

    int num;

    int fr,bk;

};

range x[100005];

range y[100005];

int s_x,s_y;

bool cmp_range(range p, range q) 

{

    if(p.num==q.num) return p.fr < q.fr;

    return p.num < q.num;

}

bool cmp_x(plant p, plant q)

{

    if(p.x == q.x) return p.y <= q.y;

    return p.x < q.x;

}

bool cmp_y(plant p, plant q)

{

    if(p.y == q.y) return p.x <= q.x;

    return p.y < q.y;

}

int main()

{

    int n,m,i;

    scanf("%d",&n);

    for(i=0;i<n;i++) scanf("%d %d",&pot[i].x,&pot[i].y);

    scanf("%d",&m);

    for(i=0;i<m;i++)

    {

        int a,b,c,d;

        scanf("%d %d %d %d",&a,&b,&c,&d);

        if(a>c) swap(a,c); 

        if(b>d) swap(b,d);

        if(a==c) 

        {

            x[s_x].num = a;

            x[s_x].fr = b;

            x[s_x++].bk = d;

        }

        else 

        {

            y[s_y].num = b;

            y[s_y].fr = a;

            y[s_y++].bk = c;

        }

    }

    sort(x,x+s_x,cmp_range); 

    sort(y,y+s_y,cmp_range); 

    sort(pot,pot+n,cmp_x); 

    int ind=0;

    plant tmp;

    int answer = 0;

    for(i=0;i<n;i++) 

    {

        while(ind!=s_x)

        {

            tmp.x = x[ind].num;

            tmp.y = x[ind].fr;

            if(cmp_x(tmp,pot[i])==1) ind++; 

            else break;

        }

        ind--;  

        if(x[ind].num == pot[i].x && x[ind].fr <= pot[i].y && pot[i].y <= x[ind].bk) answer++; 

    }

    sort(pot,pot+n,cmp_y);

    ind = 0;

    for(i=0;i<n;i++)

    {

        while(ind!=s_y)

        {

            tmp.y = y[ind].num;

            tmp.x = y[ind].fr;

            if(cmp_y(tmp,pot[i])==1) ind++;

            else break;

        }

        ind--;

        if(y[ind].num == pot[i].y && y[ind].fr <= pot[i].x && pot[i].x <= y[ind].bk) answer++;

    }

    printf("%d",answer);

    return 0;

}