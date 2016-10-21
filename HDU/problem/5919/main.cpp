#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn =  1e5+100;
int tr[maxn*100][3],top;
int n,m;
int a[maxn*2],Index[maxn*2];
void PushUp(int st) {
    tr[st][2] = tr[tr[st][0]][2] + tr[tr[st][1]][2]; 
}
int Build(int L,int R) {
    int newnode = top++;
    tr[newnode][2] = 0;
    if(L == R) return newnode;
    int mid = (L+R)>>1;
    tr[newnode][0] = Build(L,mid);
    tr[newnode][1] = Build(mid+1,R);
    PushUp(newnode);
    return newnode;
}
int Update(int pre,int L,int R,int val,int pos) {
    int newnode = top++;
    tr[newnode][0] = tr[pre][0];
    tr[newnode][1] = tr[pre][1];
    tr[newnode][2] = tr[pre][2];
    if(L == R) {
        tr[newnode][2] +=val;
        return newnode;
    }
    int mid = (L+R)>>1;
    if(pos<=mid) tr[newnode][0] = Update(tr[pre][0],L,mid,val,pos);
    else tr[newnode][1] = Update(tr[pre][1],mid+1,R,val,pos);
    PushUp(newnode);
    return newnode;
}
int Query(int now,int L,int R,int pos) {
    if(pos == R) return tr[now][2];
    int mid = (L+R)>>1;
    int sum = 0;
    if(pos<=mid) sum= Query(tr[now][0],L,mid,pos);
    else sum = Query(tr[now][0],L,mid,mid)+Query(tr[now][1],mid+1,R,pos);
    return sum;
}
int Solve(int l,int r) {
    int k = Query(Index[l],1,n,r);
    k = (k+1)/2;
    int ans= -1,L = l,R = r;
    while(L<=R) {
        int mid = (R+L)>>1;
        if(Query(Index[l],1,n,mid)>=k) {
            ans = mid;
            R = mid-1;
        } 
        else L = mid+1;
    }
    return ans;
}
map<int,int>mp;
int main() {
    int T;
    int z = 1;
    scanf("%d",&T);
    while(T--) {
        scanf("%d %d",&n,&m);
        for(int  i = 1;i<=n;i++) scanf("%d",&a[i]);
        top = 0;mp.clear();
        Index[n+1] = Build(1,n);
        for(int i = n;i>=1;i--) {
            if(!mp[a[i]]) {
                Index[i] = Update(Index[i+1],1,n,1,i);
                mp[a[i]] = i;
            }
            else {
                int temp = Update(Index[i+1],1,n,-1,mp[a[i]]);
                Index[i] = Update(temp,1,n,1,i);
                mp[a[i]] = i;
            }
        } 
        int ans = 0,l,r;
        printf("Case #%d:",z++);
        while(m--) {
            scanf("%d %d",&l,&r);
            int L = l,R = r;
            l = min((L+ans)%n+1,(R+ans)%n+1);
            r = max((L+ans)%n+1,(R+ans)%n+1);
            ans = Solve(l,r);
            printf(" %d",ans);
        }
        printf("\n");
    }
    return 0;
}
