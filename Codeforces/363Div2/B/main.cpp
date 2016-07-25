#include <bits/stdc++.h>

using namespace std;

<<<<<<< HEAD
char s[1100][1100];

int x[1100];

int  y[1100];
int n,m;
bool Check()
{
    for(int i =0; i<n; i++)
        for(int j = 0; j<m; j++)
            if(s[i][j] == '*') return false;

    return true;
=======
const int Max = 210000;

int arr[Max];

int pre[Max];

int ans[Max];

int Find(int x)
{
    return pre[x] == x?x:pre[x] = Find(pre[x]);
}

void Union(int x,int y)
{
    int Fx = Find(x);

    int Fy = Find(y);

    if(Fx != Fy)
    {
        pre[Fx] = Fy;
    }
>>>>>>> 0cb576ae3a1f15ec03ffe131c0c1cc7dd0222900
}

int main()
{
<<<<<<< HEAD



    scanf("%d %d",&n,&m);

    for(int i = 0; i<n; i++)
    {
        scanf("%s",s[i]);

        for(int j = 0; j<m; j++)
        {
            if(s[i][j] == '*')
            {
                x[i]++;

                y[j]++;
            }
        }
    }


    int X = 0,Y = 0;
    int num = 0;
    for(int i = 0; i<n; i++)
    {
        if(num<x[i])
        {
            num = x[i];

            X = i;
        }
    }
    num = 0;
    for(int i = 0; i<m; i++)
    {
        if(num<y[i])
        {
            num = y[i];

            Y = i;
=======
    int n;

    scanf("%d",&n);

    for(int i = 1;i<=n;i++) pre[i] = i;

    ans[0] = 0;

    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&arr[i]);


        if(Find(i) == Find(arr[i]) && i != arr[i])
        {
            ans[++ans[0]] = i;
        }

        Union(i,arr[i]);
    }
    bool flag = false;

    int ant;

    for(int i = 1;i<=n;i++)
    {
        if(arr[i] == i)
        {
            flag = true;

            ant = i;

            ans[++ans[0]] = i;
>>>>>>> 0cb576ae3a1f15ec03ffe131c0c1cc7dd0222900
        }
    }


<<<<<<< HEAD
    for(int k = 0; k<n; k++)
    {
        s[k][Y] = '.';
    }

    for(int k = 0; k<m; k++)
    {
        s[X][k] = '.';
    }


    bool ans = Check();
    if(ans)
        printf("YES\n%d %d\n",X+1,Y+1);
    else printf("NO\n");
=======
    printf("%d\n",ans[0]-(flag == true?1:0));


    sort(ans+1,ans+ans[0]+1);

    int num = 1;

    for(int i = 1;i<=n;i++)
    {
        if(i!=1) printf(" ");

        if(num<=ans[0] && i == ans[num])
        {
            if(!flag)
            {
                printf("%d",ans[ans[0]]);
            }
            else printf("%d",ant);

            num++;
        }
        else printf("%d",arr[i]);
    }

    printf("\n");

>>>>>>> 0cb576ae3a1f15ec03ffe131c0c1cc7dd0222900
    return 0;
}
