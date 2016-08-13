#include <bits/stdc++.h>

using namespace std;

int a[25][25];

int ans;

bool ok(int x,int y)
{
    if(x>=0 &&x<20 && y>=0 &&y<20) return true;

    return false;
}

void Get(int x,int y,int opx,int opy)
{
    int l = x,r  = y;

    int sum = 1;

    while(ok(x,y))
    {

        if(a[x][y] ==0)
        {
            l = x+opx;

            r = y+opy;

            sum = 1;
        }
        else
        {
            sum*=a[x][y];

            if(abs(x-l+1)>=4 || abs(y-r+1)>=4)

                if(abs(x-l+1)>4 || abs(y -r+1) >4)
                {
                    int Fx = x+4*(-opx);

                    int Fy = y+4*(-opy);

                    sum = sum/(a[Fx][Fy]);
                }
            ans = max(ans,sum);
        }
        x+=opx;

        y+=opy;
    }
}

int main()
{
    for(int i = 0; i<20; i++)
        for(int j = 0; j<20; j++)
            scanf("%d",&a[i][j]);
    ans = 0;
    for(int i = 0; i<20; i++)
    {
        Get(i,0,0,1);
        Get(0,i,1,0);
        Get(0,i,1,1);
        Get(i,0,1,1);
        Get(0,i,1,-1);
        Get(i,19,1,-1);
    }

    printf("%d\n",ans);
    return 0;
}
