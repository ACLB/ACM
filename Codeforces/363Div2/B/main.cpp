#include <bits/stdc++.h>

using namespace std;

const int Max = 210000;

int arr[Max];

int pre[Max];

int ans[Max];

int Find(int x)
{
    return pre[x] == x?x:pre[x] = Find(pre[x]);
}

void Union(int x,int y)
{
    int Fx = Find(x);

    int Fy = Find(y);

    if(Fx != Fy)
    {
        pre[Fx] = Fy;
    }
}

int main()
{
    int n;

    scanf("%d",&n);

    for(int i = 1;i<=n;i++) pre[i] = i;

    ans[0] = 0;

    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&arr[i]);


        if(Find(i) == Find(arr[i]) && i != arr[i])
        {
            ans[++ans[0]] = i;
        }

        Union(i,arr[i]);
    }
    bool flag = false;

    int ant;

    for(int i = 1;i<=n;i++)
    {
        if(arr[i] == i)
        {
            flag = true;

            ant = i;

            ans[++ans[0]] = i;
        }
    }


    printf("%d\n",ans[0]-(flag == true?1:0));


    sort(ans+1,ans+ans[0]+1);

    int num = 1;

    for(int i = 1;i<=n;i++)
    {
        if(i!=1) printf(" ");

        if(num<=ans[0] && i == ans[num])
        {
            if(!flag)
            {
                printf("%d",ans[ans[0]]);
            }
            else printf("%d",ant);

            num++;
        }
        else printf("%d",arr[i]);
    }

    printf("\n");

    return 0;
}
