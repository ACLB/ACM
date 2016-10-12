#include <bits/stdc++.h>

using namespace std;

char s[][50]={
"Cleveland Cavaliers",
"Golden State Warriors",
"San Antonio Spurs",
"Miami Heat",
"Miami Heat",
"Dallas Mavericks",
"L.A. Lakers",
"L.A. Lakers",
"Boston Celtics",
"San Antonio Spurs",
"Miami Heat",
"San Antonio Spurs",
"Detroit Pistons",
"San Antonio Spurs",
"L.A. Lakers",
"L.A. Lakers",
"L.A. Lakers",
"San Antonio Spurs",
"Chicago Bulls",
"Chicago Bulls",
"Chicago Bulls",
"Houston Rockets",
"Houston Rockets",
"Chicago Bulls",
"Chicago Bulls",
"Chicago Bulls",
"Detroit Pistons",
"Detroit Pistons",
"L.A. Lakers",
"L.A. Lakers",
"Boston Celtics",
"L.A. Lakers",
"Boston Celtics",
"Philadelphia 76ers",
"L.A. Lakers",
"Boston Celtics",
"L.A. Lakers",
"Seattle Sonics",
"Washington Bullets",
"Portland Trail Blazers",
"Boston Celtics",
"Golden State Warriors",
"Boston Celtics",
"New York Knicks",
"L.A. Lakers",
"Milwaukee Bucks",
"New York Knicks",
"Boston Celtics",
"Boston Celtics",
"Philadelphia 76ers",
"Boston Celtics",
"Boston Celtics",
"Boston Celtics",
"Boston Celtics",
"Boston Celtics",
"Boston Celtics",
"Boston Celtics",
"Boston Celtics",
"St. Louis Hawks",
"Boston Celtics",
"Philadelphia Warriors",
"Syracuse Nats",
"Minneapolis Lakers",
"Minneapolis Lakers",
"Minneapolis Lakers",
"Rochester Royals",
"Minneapolis Lakers",
"Minneapolis Lakers",
"Baltimore Bullets",
"Philadelphia Warriors"
};

int n;

char str[50];

int main()
{
    scanf("%d\n",&n);

    for(int i = 1;i<=n;i++)
    {
        gets(str);

        int num = 0;

        for(int j = 0;j<70;j++)
        {
            if(!strcmp(s[j],str))
            {
                num++;
            }
        }

        printf("Case #%d: %d\n",i,num);
    }
    return 0;
}
