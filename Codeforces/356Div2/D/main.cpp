#include <iostream>

using namespace std;

typedef long long LL;

LL cube[100100];

int main()
{
    for(LL i = 1;i<=100000;i++)
    {
        cube[i] = i*i*i;
    }

    LL m;

    cin >> m;

    LL sum = 0;

    LL num = 0;

    for(int i = 100000;i>1;i--)
    {
        if(m>cube[i])
        {
            sum += cube[i];

            num++;

            m -= cube[i];
        }
    }

    cout<<num<<" "<<sum<<endl;

    return 0;
}
