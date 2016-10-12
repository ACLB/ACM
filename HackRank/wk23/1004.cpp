#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int Ne[maxn*6];
char str[maxn*6];
int getnext()
{
    int i=0,j=-1;
    int len=strlen(str);
    Ne[0]=-1;
    while(i<len)
    {
        if(j==-1||str[i]==str[j])
        {
            i++;
            j++;
            Ne[i]=j;
        }
        else
        {
            j=Ne[j];
        }
    }
    int ans = len - Ne[len];
    if(len % ans) return 1;
    else return len/ans;
}
int main() {
    int k ;
    scanf("%s",str);
    scanf("%d",&k);
    int len = strlen(str);
    int po = getnext();
    int st = len/po;
    printf("%d\n",k/st);
    return 0;
}
