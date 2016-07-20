### BestCoder 2nd Anniversary

----

#### HDU【5718】——Oracle

---

##### Time Limit: 8000/4000 MS (Java/Others)    Memory Limit: 262144/262144 K (Java/Others)



##### Problem Description

There is once a king and queen, rulers of an unnamed city, who have three daughters of conspicuous beauty.

The youngest and most beautiful is Psyche, whose admirers, neglecting the proper worship of the love goddess Venus, instead pray and make offerings to her. Her father, the king, is desperate to know about her destiny, so he comes to the Delphi Temple to ask for an oracle.

The oracle is an integer n without leading zeroes. 

To get the meaning, he needs to rearrange the digits and split the number into two positive integers without leading zeroes, and their sum should be as large as possible. 

Help him to work out the maximum sum. It might be impossible to do that. If so, print `Uncertain`.
 

##### Input

The first line of the input contains an integer T (1≤T≤10), which denotes the number of test cases.
For each test case, the single line contains an integer n (1≤n<1010000000).
 
##### Output
For each test case, print a positive integer or a string `Uncertain`.
 

##### Sample Input
3
112
233
1
 

##### Sample Output
22
35
Uncertain

##### Hint

In the first example, it is optimal to split $ 112 $ into $ 21 $ and $ 1 $, and their sum is $ 21 + 1 = 22 $.

In the second example, it is optimal to split $ 233 $ into $ 2 $ and $ 33 $, and their sum is $ 2 + 33 = 35 $.

In the third example, it is impossible to split single digit $ 1 $ into two parts.


`题解：一眼题解，但是自己把自己给坑了，调了一段时间的bug，判断所给的字符串中非零的数量是不是大于等于2，符合，则将最小的一个非零的数作为单独的数，剩下的字符按照从大到小组成另一个数，然后是大数加法`。

```cpp

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef long long LL;

char s[11000000];

int  a[11000000];

int T;

int main()
{
    scanf("%d",&T);

    while(T--)
    {
        scanf("%s",s);

        int len = strlen(s);

        int num = 0;

        int Min = 10;

        for(int i = 0;i<len;i++)
        {
            if(s[i] != '0') num++;

            if(s[i] != '0')
            {
                Min = min(Min,s[i] - '0');
            }
        }

        if(num <2 || len <2)
        {
            printf("Uncertain\n");
        }
        else
        {

            bool flag = false;

            sort(s,s+len);

            int n = 0;

            int st = Min;

            for(int i = 0,j = 0;i<len;i++)
            {
                if(s[i] - '0' == st)
                {
                    if(!flag)
                    {
                        flag = true;

                        continue;
                    }
                }

                a[j] = s[i]-'0';

                a[j] += Min;

                if(a[j]>=10)
                {
                    a[j] -= 10;

                    Min = 1;
                }
                else Min = 0;

                j++;

                n = max(n,j);
            }

            if(Min)
            {
                printf("%d",Min);
            }

            for(int i = n-1;i>=0;i--)
            {
                printf("%d",a[i]);
            }

            printf("\n");
        }
    }
    return 0;
}

```

#### HDU【5719】——Arrange

----


##### Time Limit: 8000/4000 MS (Java/Others)    Memory Limit: 262144/262144 K (Java/Others)



##### Problem Description

Accidentally, Cupid, god of desire has hurt himself with his own dart and fallen in love with Psyche. 

This has drawn the fury of his mother, Venus. The goddess then throws before Psyche a great mass of mixed crops.

There are n heaps of crops in total, numbered from 1 to n. 

Psyche needs to arrange them in a certain order, assume crops on the i-th position is Ai.

She is given some information about the final order of the crops:

1. the minimum value of A1,A2,...,Ai is Bi.

2. the maximum value of A1,A2,...,Ai is Ci.

She wants to know the number of valid permutations. As this number can be large, output it modulo 998244353.

Note that if there is no valid permutation, the answer is 0.
 

##### Input
The first line of input contains an integer T (1≤T≤15), which denotes the number of testcases.

For each test case, the first line of input contains single integer n (1≤n≤105).

The second line contains n integers, the i-th integer denotes Bi (1≤Bi≤n).

The third line contains n integers, the i-th integer denotes Ci (1≤Ci≤n).
 


##### Output

For each test case, print the number of valid permutations modulo 998244353.
 

Sample Input
2
3
2 1 1
2 2 3
5
5 4 3 2 1
1 2 3 4 5
 

Sample Output
1
0

##### Hint

In the first example, there is only one valid permutation (2,1,3) .

In the second example, it is obvious that there is no valid permutation.

`题解：对于每一个给定的最大值和最小值的区间，判断是否合法，如果合法，那么如果现在的区间和之前的取件一样，那么判断这个区间的已经用了多少的数，如果全部已经用了，则不合法，否则用乘法原理得出结果，如果和之前的取件不同，那么只能是最小值变小或者最大值变大，不可能同时改变（一个数不能有两种结果，只能造成最大值变大或者最小值变小，并且这个数只能取这个变化的数）。`

```cpp

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

const int Max = 1e5+100;

typedef long long LL;

const long long Mod =  998244353;

int a[Max],b[Max];

int Tr[Max];

int n;

int lowbit(int x)
{
    return x&(-x);
}

void Up(int x)
{
    while(x<=n)
    {
        Tr[x]++;

        x+=lowbit(x);
    }
}

int Qey(int x)
{
    int sum = 0;

    while(x)
    {
        sum+=Tr[x];

        x-=lowbit(x);
    }
    return sum;
}

LL Judge()
{
    if(a[0] != b[0]) return 0;

    Up(a[0]);

    LL ans = 1;

    for(int i =1;i<n;i++)
    {
        int op = (a[i] !=a[i-1])+(b[i]!=b[i-1]);

        if(op == 2) return 0;

        if(op == 0)
        {
            ans = (ans *(b[i]-a[i]+1-(Qey(b[i])-Qey(a[i]-1))))%Mod;

            Up(a[i]);
        }
        else
        {
            Up(a[i] == a[i-1]?b[i]:a[i]);
        }

    }

    return ans;
}

int main()
{
    int T;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        memset(Tr,0,sizeof(Tr));

        for(int i = 0;i<n;i++) scanf("%d",&a[i]);

        for(int i = 0; i<n;i++) scanf("%d",&b[i]);

        LL ans = Judge();

        cout<<ans<<endl;
    }
    return 0;
}

```

#### HDU【5720】——wool

###### Time Limit: 8000/4000 MS (Java/Others)    Memory Limit: 262144/262144 K (Java/Others)

######Problem Description

At dawn, Venus sets a second task for Psyche.
She is to cross a river and fetch golden wool from violent sheep who graze on the other side.
The sheep are wild and tameless, so Psyche keeps on throwing sticks to keep them away. 
There are n sticks on the ground, the length of the i-th stick is ai.
If the new stick she throws forms a triangle with any two sticks on the ground, the sheep will be irritated and attack her. 
Psyche wants to throw a new stick whose length is within the interval [L,R]. Help her calculate the number of valid sticks she can throw next time.
 
###### Input
The first line of input contains an integer T (1≤T≤10), which denotes the number of test cases.

For each test case, the first line of input contains single integer n,L,R (2≤n≤$10^5$,1≤L≤R≤$10^{18}$).

The second line contains n integers, the i-th integer denotes ai (1≤ai≤$10^{18}$).
 

###### Output

For each test case, print the number of ways to throw a stick.
 
##### Sample Input
2
2 1 3
1 1
4 3 10
1 1 2 4
 

###### Sample Output

2
5

###### Hint

In the first example, $ 2, 3 $ are available.

In the second example, $ 6, 7, 8, 9, 10 $ are available.

`题解：对于三角新组成的不等式是很清楚的，既a+b>c && abs(a-b)<c,那么我们久可以算出每一个长度和所给线段中的其他长度的线段组成的三角形的可行区间，当我们对所给的线段排序之后，会发现对于区间[a-b,a+b]（a>=b）,当b最接近a的时候区间覆盖最大，我们可以贪心的求出不合法的区间，进而求出在区间[L,R]中的长度`

```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

const int Max = 1e5+100;

typedef long long LL;

LL L,R;

int n;

LL arr[Max];

struct node
{
    LL l,r;

    bool operator < (const node &a)const
    {
        return l == a.l? r > a.r:l<a.l;
    }

} b[Max];

int main()
{
    int T;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %I64d %I64d",&n,&L,&R);

        for(int i = 0; i<n; i++)
        {
            scanf("%I64d",&arr[i]);
        }

        sort(arr,arr+n);

        int num = 0;

        for(int i = 0; i<n; i++)
        {
            if(i)
            {
                b[num].l = arr[i]-arr[i-1]+1;

                b[num++].r = arr[i]+arr[i-1]-1;
            }
        }

        sort(b,b+num);

        LL ans = 0;

        LL last = b[0].r,be = b[0].l;

        for(int i = 1; i<num; i++)
        {
            if(b[i].l>last)
            {
                if(!(last < L || be > R))
                    ans += (min(R,last)-max(L,be)+1);

                be = b[i].l;

                last = b[i].r;
            }
            else  last = max(last,b[i].r);
        }

        if(num)
        {
            if(!(last < L || be > R))
                ans += (min(R,last)-max(L,be)+1);
        }

        printf("%I64d\n",R-L+1-ans);

    }

    return 0;
}
```