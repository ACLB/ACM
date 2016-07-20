#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

int c[100];

int a[25];

int b[25];

map<int ,bool>M;

int main()
{
    int n,m;

    scanf("%d",&n);

    for(int i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);

    for(int i = 0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }

    int mm = 0;

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(a[i] == b[j])
            {
                c[mm++] = a[i];

                break;
            }
        }
    }
    mm--;

    bool flag =false;

    for(int i = 0,j;i<n;i++)
    {
        if(M[a[i]]) continue;
        for(j = 0;j<=mm;j++)
        {
            if(a[i] == c[j])
            {
                break;
            }
        }

        if(j>mm)
        {
            if(flag) printf(" ");
            else flag =true;

            M[a[i]] = true;

            printf("%d",a[i]);
        }
    }
    for(int i = 0,j;i<m;i++)
    {
        if(M[b[i]])
        {
           continue;
        }
        for(j = 0;j<=mm;j++)
        {
            if(b[i] == c[j])
            {
                break;
            }
        }

        if(j>mm)
        {
            if(flag) printf(" ");
            else flag =true;

            M[b[i]] = true;

            printf("%d",b[i]);
        }
    }

    printf("\n");

    return 0;
}
