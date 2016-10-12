#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
#define fread(x) freopen(x,"r",stdin)
#define fwrite(x) freopen(x,"w",stdout)
using namespace std;

const int MAX=(1<<7)+10;
const int N=10+10;
double p[MAX][MAX],dp[N][MAX];
int n;
int main(){
	while(~scanf("%d",&n),n != -1){
		int bit=1<<n;
		for(int i=0;i<bit;++i){
			for(int j=0;j<bit;++j)scanf("%lf",&p[i][j]);
		}
		memset(dp,0,sizeof dp);
		for(int i=0;i<bit;++i)dp[0][i]=1;
		for(int i=1;i<=n;++i){
			for(int j=0;j<bit;++j){
				int t=j>>(i-1);
				if(t&1){
					for(int k=t*(1<<(i-1))-1;k>=(t-1)*(1<<(i-1));--k){
						dp[i][j]+=dp[i-1][j]*dp[i-1][k]*p[j][k];
					}
				}
                else{
					for(int k=(t+1)*(1<<(i-1));k<(t+2)*(1<<(i-1));++k){
						dp[i][j]+=dp[i-1][j]*dp[i-1][k]*p[j][k];
					}
				}
			}
		}
		int id=0;
		for(int i=0;i<bit;++i){
			if(dp[n][i] > dp[n][id]) id = i;
		}
		printf("%d\n",id+1);
	}
	return 0;
}
