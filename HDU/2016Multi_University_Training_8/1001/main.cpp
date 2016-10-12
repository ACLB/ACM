#include <bits/stdc++.h>

using namespace std;

const int Max  = 1100;

int a[Max];

int b[Max];

queue<int>Q[Max];

int main()
{
    int n,T,m,l,r;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d",&n,&m);

        for(int i = 0; i<n; i++)
        {
            while(!Q[i].empty()) Q[i].pop();
        }

        for(int i = 0; i<n; i++) scanf("%d",&a[i]);

        for(int i = 0; i<n; i++)
        {
            scanf("%d",&b[i]);

            Q[b[i]].push(i);
        }

        bool flag = false;

        for(int i = 0; i<n; i++)
        {
            if(flag) continue;

            if(Q[a[i]].empty()) flag = true;

            else
            {
                int  t= a[i];
                a[i] = Q[a[i]].front();

                Q[t].pop();
            }
        }

        for(int i  = 0; i<m; i++)
        {
            scanf("%d %d",&l,&r);

            if(flag) continue;

            sort(a+l-1,a+r);
        }

        for(int i = 0; i<n; i++) if(a[i]!=i) flag = true;

        if(flag) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
