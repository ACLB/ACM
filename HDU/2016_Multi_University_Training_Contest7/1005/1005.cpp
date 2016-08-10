#include <bits/stdc++.h>

using namespace std;

vector<int>E[1100];

typedef struct node
{
    int num,Id;

    bool operator < (const node &a)const
    {
        return num<a.num;
    }
}No;

No a[1100];

int main()
{
    int T;

    scanf("%d",&T);

    for(int z = 1;z<=T;z++)
    {
        int n;

        scanf("%d",&n);

        for(int i =1;i<=n;i++)
        {
            scanf("%d",&a[i].num);

            a[i].Id = i;
        }

        sort(a+1,a+n+1);

        bool flag = false;

        for(int i = 1;i<=n;i++) E[i].clear();

        int ans = 0;

        for(int i = 1;i<=n;i++)
        {
            if(a[i].num>=i) {
                flag = true;
                break;
            }

            for(int j = 1;j<=a[i].num;j++)
            {
                ans++;
                E[a[i].Id].push_back(a[j].Id);
            }
        }
        printf("Case #%d: ",z);
        if(flag) printf("No\n");
        else {
            printf("Yes\n");

            printf("%d\n",ans);

            for(int i =1;i<=n;i++)
            {
                for(int j =0;j<E[i].size();j++)
                {
                    printf("%d %d\n",i,E[i][j]);
                }

            }
        }

    }
    return 0;
}
