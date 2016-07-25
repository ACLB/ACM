#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int Du[30];

int Dut[30];

int Map[30][30];

bool vis[30];

int arr[30];

int n,m;

char s[10];

int OP()
{
    for(int i = 0; i<n; i++)
    {
        Dut[i] = Du[i];
    }
    arr[0] = 0;

    memset(vis,false,sizeof(vis));

    int op = 1;

    for(int i =0 ; i<n; i++)
    {
        int Mi = 0,index;

        for(int j = 0; j<n; j++)
        {
            if(!vis[j] && Dut[j] == 0)
            {
                Mi++;

                index = j;
            }
        }

        if(Mi == 0 ) return 0;
        if(Mi>1) op = -1;



        vis[index] = true;

        arr[++arr[0]] = index;

        for(int j = 0; j<n; j++)
        {
            if(Map[index][j])
            {
                Dut[j] --;
            }
        }
    }

    return op;
}

int main()
{
    while(~scanf("%d %d",&n,&m) && (n+m))
    {
        memset(Du,0,sizeof(Du));

        memset(Map,0,sizeof(Map));

        int flag = 0;

        int st;

        for(int i = 0; i<m; i++)
        {
            scanf("%s",s);

            if(flag) continue;

            int u = s[0]-'A';

            int v = s[2]-'A';

            if(!Map[u][v])
            {
                Map[u][v] = 1;

                if(u!=v)
                    Du[v]++;

                int ans = OP();

                if(ans == 1)
                {
                    st = i+1;

                    flag = 1;
                }
                else if(ans == 0)
                {
                    st = i+1;

                    flag = 2;
                }
            }
        }

        if(n == 1 && m == 0)
        {
            printf("Sorted sequence determined after 0 relations: A.\n");

            continue;
        }

        if(flag ==0)
        {
            printf("Sorted sequence cannot be determined.\n");
        }
        else if(flag == 1)
        {
            printf("Sorted sequence determined after %d relations: ",st);

            for(int i = 1; i<=arr[0]; i++)
            {
                printf("%c",arr[i]+'A');
            }

            printf(".\n");
        }
        else if(flag == 2)
        {
            printf("Inconsistency found after %d relations.\n",st);
        }
    }
    return 0;
}
