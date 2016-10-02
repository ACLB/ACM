#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#define maxn (1000 + 20)
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
using namespace std;
typedef long long int LLI;

char str1[maxn];
char str2[maxn];
char aim[maxn];

int main() {
    int t;
    scanf("%d",&t);
    while(t --) {
        int n,m,cnt = 0;
        scanf("%d%d",&n,&m);
        getchar();
        for(int i = 1; i <= n / 2; i ++)  scanf("%c",&str1[i]);
        for(int i = 1; i <= n / 2; i ++)  scanf("%c",&str2[i]);
        for(int i = 1; i <= n / 2; i ++)
            if(str1[i] != str2[i])  cnt ++;
        if(m < cnt) printf("Impossible\n");
        else if(cnt == 0 && m % 2 != 0) printf("Impossible\n");
        else {
            int cnt2 = n / 2 - cnt,i;
            for(i = 1; i <= n / 2; i ++) {
                if(m < cnt || cnt == 0 && m % 2 != 0)   break;
                if(str1[i] == str2[i]) {
                    if(m > cnt + 1) {
                        if(str1[i] == 'a') {
                            if(m <= (cnt2 + cnt - 1) * 2) {
                                aim[i] = 'a';
                                cnt2 --;
                            } else {
                                aim[i] = 'b';
                                cnt2 --;
                                m -= 2;
                            }
                        } else {
                            aim[i] = 'a';
                            cnt2 --;
                            m -= 2;
                        }
                    } else {
                        aim[i] = str1[i];
                        cnt2 --;
                    }
                } else {
                    if(m == (cnt2 + cnt) * 2) {
                        if(min(str1[i],str2[i]) != 'a') {
                            aim[i] = 'a';
                            m -= 2;
                            cnt --;
                        } else {
                            if(max(str1[i],str2[i]) == 'b') {
                                aim[i] = 'c';
                                m -= 2;
                                cnt --;
                            } else {
                                aim[i] = 'b';
                                m -= 2;
                                cnt --;
                            }
                        }
                    } else if(m > cnt + 1) {
                        aim[i] = 'a';
                        if(min(str1[i],str2[i]) == 'a') {
                            m --;
                            cnt --;
                        } else {
                            m -= 2;
                            cnt --;
                        }
                    } else {
                        aim[i] = min(str1[i],str2[i]);
                        m --;
                        cnt --;
                    }
                }
            }
            if(i <= n / 2)  printf("Impossible\n");
            else {
                for(int i = 1; i <= n / 2; i ++) {
                    printf("%c",aim[i]);
                }
                for(int i = 1; i <= n / 2; i ++) {
                    printf("%c",aim[i]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
