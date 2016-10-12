#include <bits/stdc++.h>

using namespace std;

const int Max =210000;


int pre[Max];

int arr[Max];

bool num[Max];

int vis[Max];

bool vist[Max];

int Find(int x)
{
    return vis[x] ==0 ?x:vis[x] = Find(vis[x]);
}


int main()
{
    int n;

    memset(pre,0,sizeof(pre));
    memset(vist,false,sizeof(vist));


    arr[0]= 0 ;

    scanf("%d",&n);

    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&pre[i]);

        if(i == pre[i]) continue;

        if(Find(i) == Find(pre[i]))
        {

            if(!num[Find(i)])
            {
                arr[++arr[0]] = i;

            }

            num[i] = true;

            num[pre[i]] = true;
        }
        else vis[i] = pre[i];

    }

    int ant = 0;

    for(int i = 1;i<=n;i++)
    {
        if(pre[i] == i)
        {
            ant  = 1;
            arr[++arr[0]] = i;
        }
    }

    sort(arr+1,arr+arr[0]+1);



    printf("%d\n",arr[0]-ant);

    int num = 1;

    int id = arr[arr[0]];

    for(int i = 1;i<=n;i++)
    {
        if(i != 1) printf(" ");

        if(arr[num] == i)
        {
            if(ant == 0 || (ant !=0 &&num!=arr[0]))
                printf("%d",arr[arr[0]]);
            else printf("%d",pre[i]);

            num++;
        }
        else printf("%d",pre[i]);
    }

    printf("\n");

    return 0;
}
