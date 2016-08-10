#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n,B,num;

int pre[1100];

int a[1100],b[1100];

vector<int>E[1100];

void Init(){
    for(int i =1;i<=n;i++) E[i].clear();
}

int dfs(int u,int fa){
    
    int size = 0;

    for(int i = 0;i<E[u].size();i++)
    {
        if(E[u][i] == fa) continue;

        size += dfs(E[u][i],u);

        if(size >=B){
            ++num;
            
            for(int i = a[0];i>a[0]-size;i--){
                pre[a[i]] = num;
            }
            b[++b[0]] = u;

            a[0] -=size;

            size = 0;
        }
    }

    size ++;

    a[++a[0]] = u;

    return size;
}

int main()
{
    int u,v;

    while(~scanf("%d %d",&n,&B)){
        Init();

        for(int i = 1;i<n;i++){
            scanf("%d %d",&u,&v);

            E[u].push_back(v);

            E[v].push_back(u);
        }

        num = 0;

        a[0] = 0; b[0] = 0;

        int ans = dfs(1,0);

        if(ans) {
            for(int i = 1;i<=a[0];i++)
            {
                pre[a[i]] = num;
            }
        }

        printf("%d\n",num);


        if(num){
            for(int i =1;i<=n;i++) {
                if(i!=1) printf(" ");
                printf("%d",pre[i]);
            }

            printf("\n");

            for(int i = 1;i<=b[0];i++) {
                if(i != 1) printf(" ");
                printf("%d",b[i]);
            }

            printf("\n");
        }
    }
    return 0;
}
