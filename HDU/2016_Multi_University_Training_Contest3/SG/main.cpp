#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int SG[1100][1100];

bool mex[30];

int GetSg(int x,int y)
{
    memset(mex,false,sizeof(mex));

//    for(int i = x-1;i>=1;i--)
//    {
//        mex[SG[i][y]] = true;
//    }
//
//    for(int i = y-1;i>=1;i--)
//    {
//        mex[SG[x][i]] = true;
//    }
//
//    for(int i = x-1,j = y-1;i>=1&& j>=1;i--,j--)
//    {
//        mex[SG[i][j]] = true;
//    }
    if(x>2 && y>1)
    {
        mex[SG[x-2][y-1]] = true;
    }

    if(x>1 && y>2)
    {
        mex[SG[x-1][y-2]] = true;
    }

    for(int i = 0;i<30;i++)
    {
        if(mex[i] ) continue;

        return i;
    }
}

int main()
{
    SG[1][1] = 0;

    freopen("test.txt","w",stdout);

    for(int i = 1;i<=30;i++)
    {
        for(int j = 1;j<=30;j++)
        {
            if(i== 1 && j==1) continue;
            SG[i][j] = GetSg(i,j);
        }
    }

    int ans = 0;

    for(int i = 2;i<=30;i++)
    {
        for(int j = 2;j<=30;j++)
        {
            if(j != 2) printf(" ") ;

            printf("%d",SG[i][j]!=0);
        }

        printf("\n");
    }

    printf("%d\n",ans);
    return 0;
}
