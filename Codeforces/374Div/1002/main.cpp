#include <bits/stdc++.h>

using namespace std;

int vis[110];
char str[110];
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    memset(vis,false,sizeof(vis));
    for(int i = 0;i<n;i++) {
        scanf("%s",str);
        vis[strlen(str)]++;
    }
    scanf("%s",str);
    int len = strlen(str);
    int num1 = 0 ,num2 = 0;
    for(int i = 1;i<len;i++)num1+=vis[i];
    num2 = vis[len];
    printf("%d %d\n",num1/k*5+(num1+1),(num1+num2-1)/k*5+num2+num1);
    return 0;
}
