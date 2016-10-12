#include <bits/stdc++.h>

using namespace std;

<<<<<<< HEAD
typedef long long LL;

int main()
{
=======
<<<<<<< HEAD
int arr[110];

int n;

bool vis[110];

int main()
{
    int sum = 0;

    cin>>n;

    for(int i =0;i<n;i++)
    {
        cin>>arr[i];

        sum+=arr[i];
    }

    sum/=(n/2);

    for(int i = 0;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i] = true;

            for(int j = i+1;j<n;j++)
            {
                if(vis[j]) continue;
                if(arr[i] + arr[j] == sum)
                {
                    printf("%d %d\n",i+1,j+1);

                    vis[j] = true;

                    break;
                }
            }
        }
    }
=======
const double eps = 1e-9;

int n,k;

double l,v1,v2;

double t;

int main()
{
    scanf("%d %lf %lf %lf %d",&n,&l,&v1,&v2,&k);

    int num = (n+k-1)/k;

    double s = l*(v2+v1)/((num-1)*2*v1+v1+v2);

    printf("%.10f\n",(l-s)/v1+s/v2);

>>>>>>> e0a5ae877837cf03b24e96e02237c6251abde0bb
>>>>>>> origin/master
    return 0;
}
