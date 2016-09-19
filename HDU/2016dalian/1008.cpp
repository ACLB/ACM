#include <bits/stdc++.h>
using namespace std;
const int maxn = 201000;
const int INF = 0x3f3f3f3f;
struct node {
    int v,next;
}edge[maxn];
int h[maxn],top;
int dis[maxn];
void init() {
    memset(h,-1,sizeof(h));
    memset(dis,INF,sizeof(dis));
    top = 0;
}
void add(int u,int v) {
    edge[top].v = v; edge[top].next = h[u];
    h[u] = top++;
}
int  n,m,s;
bool vis1[maxn];
bool vis2[maxn];
void spfa() {
    queue<int>Q;
    set<int>s1; set<int>s2;
    for(int i = 1;i<=n;i++) {
        if(i!=s) s1.insert(i);
    }
    vis1[s] = false;
    dis[s] = 0;
    Q.push(s);
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        for(int i = h[u];i!=-1;i = edge[i].next) {
            if(s1.count(edge[i].v)) {
                s1.erase(edge[i].v);
                s2.insert(edge[i].v);
            }
        }
        for(set<int>::iterator it = s1.begin(); it!=s1.end();it++){
                Q.push(*it);
                dis[*it] = dis[u]+1;
        }
        s1 = s2;
        s2.clear();
    }
}
int main() {
    int T,u,v;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        init();
        for(int i = 0;i<m;i++) {
            scanf("%d %d",&u,&v);
            add(u,v); add(v,u);
        }
        scanf("%d",&s);
        spfa();
        bool flag= false;
        for(int i =1;i<=n;i++) {
            if(i == s) continue;
            if(flag) printf(" ");
            else flag= true;
            printf("%d",dis[i] == INF?-1:dis[i]);
        }
        printf("\n");
    }
    return 0;
}
