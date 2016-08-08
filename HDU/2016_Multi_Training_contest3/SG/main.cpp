#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

int SG[1100][1100];

bool mex[50];

int GetSg(int x,int y)
{
    memset(mex,false,sizeof(mex));

    for(int i = x-1;i>=1;i--)
    {
        mex[SG[i][y]] = true;
    }

    for(int i = y-1;i>=1;i--)
    {
        mex[SG[x][i]] = true;
    }

    for(int i = x-1,j = y - 1;i>=1&&j>=1;i--,j--)
    {
        mex[SG[i][j]] = true;
    }

    for(int i = 0;i<50;i++)
    {
        if(mex[i]) continue;

        return i;
    }
}

int main()
{
    freopen("test.txt","w",stdout);

    SG[1][1] = 0;

    for(int i = 1;i<=1000;i++)
    {
        for(int j = 1;j<=1000;j++)
        {
            if(i == 1 && j == 1) continue;

            SG[i][j] = GetSg(i,j);
        }
    }

    int num = 1;

    for(int i = 2;i<=1000;i++)
    {
        for(int j = 2;j<=1000;j++)
        {
            if(SG[i][j]) continue;

            num++;

            printf("{%d,%d},",i,j);

            if(num%20 ==0 ) printf("\n");
        }
    }
    return 0;
}
