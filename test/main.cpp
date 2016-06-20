#include <bits/stdc++.h>

using namespace std;

int main()
{
    int st1,p1,t1,st2,p2,t2;

    scanf("%d %d %d %d %d %d",&st1,&p1,&t1,&st2,&p2,&t2);

    for(int i = 0;i<=t1;i++)
    {
        for(int j = 0;j<=t2;j++)
        {
            if(st1+i*p1 == st2 + j*p2)
            {
                printf("%d %d\n",i,j);
                printf("hhhhh\n");

                return 0;
            }
        }
    }

    printf("ffffff\n");

    return 0;
}
