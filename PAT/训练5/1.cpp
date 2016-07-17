#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m,data;

    cin>>m>>n;

    int num = 0;

    for(int i = 0;i<n;i++)
    {
        cin>>data;

        if(data<0)
        {
            num = n+1;

            break;
        }
        if(data == m)
        {
            break;
        }

        if(data<m)
        {
            cout<<"Too small"<<endl;
        }
        else if(data>m)
        {
            cout<<"Too big"<<endl;
        }

        num++;
    }

    if(num == 0)
    {
        cout<<"Bingo!"<<endl;
    }
    else if(num <3)
    {
        cout<<"Lucky You!"<<endl;
    }
    else if(num<n)
    {
        cout<<"Good Guess!"<<endl;
    }
    else 
        cout<<"Game Over"<<endl;
    return 0;
}
