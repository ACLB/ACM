#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

const int Max = 1100;

void read(int &ans)
{
    char ch;

    while((ch = getchar())<'0' && ch >'9');

    ans = ch-'0';

    while((ch = getchar())>='0' && ch<='9')
    {
        ans = ans*10+ch-'0';
    }
}

int n,m;

int arr[Max][Max];

int st[Max];

int L[Max][Max],R[Max][Max],up[Max][Max],dn[Max][Max];

unsigned cal(unsigned a,unsigned b,unsigned c,unsigned d)
{
    return ((a+1)*(b+1)*(a+b+2)/2)*((c+1)*(d+1)*(c+d+2)/2);
}

int main()
{
    int T;

    read(T);

    while(T--)
    {
        read(n); read(m);

        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                read(arr[i][j]);

                L[i][j] = 1;

                R[i][j] = m;

                up[i][j] = 1;

                dn[i][j] = n;
            }
        }

        int top;

        for(int i = 1;i<=n;i++)
        {
            top = 0;

            st[++top] = 0;

            for(int j = 1;j<=m;j++)
            {
                while(top>1 && arr[i][st[top]] > arr[i][j])
                {
                    R[i][st[top]] = min(j-1,R[i][st[top]]);

                    top--;
                }

                if(top>1 && arr[i][st[top]] == arr[i][j]) L[i][j] = max(L[i][j],st[top]+1) ;

                while(top>1 && arr[i][st[top]] == arr[i][j])
                {
                    R[i][st[top]] = min(j-1,R[i][st[top]]);

                    top --;
                }

                L[i][j] = max(L[i][j],st[top]+1);

                st[++top] = j;
            }
        }

        for(int i = 1;i<=m;i++)
        {
            top = 0;

            st[++top] = 0;

            for(int j = 1;j<=n;j++)
            {
                while(top>1 && arr[st[top]][i]< arr[j][i])
                {
                    dn[st[top]][i] = min(j-1,dn[st[top]][i]);

                    top--;
                }

                if(top >1  && arr[st[top]][i] == arr[j][i]) up[j][i] =max(up[j][i],st[top]+1);

                while(top>1 && arr[st[top]][i] == arr[j][i]) 
                {
                    dn[st[top]][i] = min(j-1,dn[st[top]][i]);

                    top--;
                }

                up[j][i] = max(up[j][i],st[top]+1);

                st[++top] = j;

            }
        }

        unsigned int ans = 0;

        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                unsigned c1 = j - L[i][j];

                unsigned c2 = R[i][j]-j;

                unsigned h1 = i - up[i][j];

                unsigned h2 = dn[i][j] - i;

                unsigned s = arr[i][j];

                ans +=cal(c1,c2,h1,h2)*s;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
