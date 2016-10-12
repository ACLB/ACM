#include <bits/stdc++.h>

using namespace std;

int num[310000];

int numt[310000];

typedef struct node
{
    int x,t;

    node(){}

    node(int _x,int _t):x(_x),t(_t){}
}Po;

int main()
{
    int n,q;

    int type,x;

    queue< Po > Q;

    memset(num,0,sizeof(num));

    memset(numt,0,sizeof(numt));

    scanf("%d %d",&n,&q);

    int sum = 0;

    int s = 0;

    for(int i  = 1;i<=q;i++)
    {
        scanf("%d %d",&type,&x);

        if(type == 1)
        {
            num[x]++;

            Q.push(node(x,i));

            sum++;
        }
        else if(type == 2)
        {
            sum-=num[x];

            num[x] = 0;

            numt[x] = i;

        }
        else if(type == 3)
        {
            for(int j = s+1;j<=x&&!Q.empty();j++)
            {
                Po u = Q.front(); Q.pop();

                s++;

                if(numt[u.x]<u.t)
                {
                    sum--;

                    num[u.x]--;
                }
            }
        }

        printf("%d\n",sum);
    }
    return 0;
}
