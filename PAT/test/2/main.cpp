#include <bits/stdc++.h>

using namespace std;

char str[1100];
bool flag ;
int Trans(char c)
{
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return -1;
}
void Print(char c)
{
    if(flag) printf(" ");
    else flag = true;
    printf("%c",c);
}
bool Judge(char c)
{
    if(c == '+' || c== '-' || c == '/' || c== '*' || c== ')' || c== '(') return false;
    return true;
}
int main()
{
    scanf("%s",str);
    int len = strlen(str);
    stack<char>s;
    flag = false;
    for(int i = 0; i<len; i++)
    {
        bool sp = false;
        if(str[i] == '-' && (i ==0 || (!Judge(str[i-1])))) {
            if(!sp)
            {
                if(flag) printf(" ");
                else flag = true;
            }
            sp = true;
            printf("%c",str[i]);
            i++;
        }
        while(Judge(str[i]) && i<len)
        {
            if(!sp)
            {
                if(flag) printf(" ");
                else flag = true;
            }
            printf("%c",str[i]);
            i++;
            sp = true;
        }
        if(sp)
        {
            i--;
            continue;
        }
        if(str[i] == '(')
        {
            s.push(str[i]);
            continue;
        }
        else
        {
            int op = Trans(str[i]);
            if(op == -1)
            {
                while(!s.empty()&& Trans(s.top())!=op)
                {
                    Print(s.top());
                    s.pop();
                }
                s.pop();
            }
            else
            {
                while(!s.empty() && Trans(s.top())>=op)
                {
                    Print(s.top());
                    s.pop();
                }
                s.push(str[i]);
            }

        }
    }
    while(!s.empty())
    {
        Print(s.top());
        s.pop();
    }
    printf("\n");
    return 0;
}
