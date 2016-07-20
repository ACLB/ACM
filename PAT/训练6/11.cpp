#include <bits/stdc++.h>

using namespace std;

map<string,int>M;

char s[50];

int main()
{

    int n ;

    scanf("%d",&n);

    getchar();

    for(int i = 0;i<n;i++)
    {
        gets(s);

        M[s]++;
    }


    for(map<string,int>::iterator it = M.begin();it != M.end();it++)
    {
        printf("%s %.4f%%\n",it->first.c_str(),it->second*100.0/n);
    }
    return 0;
}
