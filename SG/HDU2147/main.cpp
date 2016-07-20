#include <bits/stdc++.h>

using namespace std;

//int Sg[2100][2100];
//
//bool mex[10];
//
//int GetSg(int x,int y)
//{
//    memset(mex,false,sizeof(mex));
//    if(x == 1 && y!=1)
//    {
//        mex[Sg[x][y-1]] = true;
//    }
//
//    if(y == 1 && x!=1)
//    {
//        mex[Sg[x-1][y]] = true;
//    }
//
//    if(x>1 && y>1)
//    {
//        mex[Sg[x][y-1]] = true;
//        mex[Sg[x-1][y-1]] = true;
//        mex[Sg[x-1][y]] = true;
//    }
//
//    for(int i = 0;i<=9;i++)
//    {
//        if(!mex[i]) return i;
//    }
//}

int main()
{
//    Sg[1][1] = 1;

//    for(int i = 1;i<=2000;i++)
//    {
//        for(int j = 1;j<=2000;j++)
//        {
//            Sg[i][j] = GetSg(i,j);
//
//        }
//    }
//
//    for(int i = 1;i<=15;i++)
//    {
//        for(int j = 1;j<=15;j++)
//        {
//            if(j!=1) printf(" ");
//
//            printf("%d",Sg[i][j]);
//        }
//
//        printf("\n");
//    }

    int n,m;

    while(~scanf("%d %d",&n,&m) &&(n+m))
    {
        if(n%2 == 0 || m%2 == 0)
        {
            printf("Wonderful!\n");
        }
        else printf("What a pity!\n");
    }
    return 0;
}
