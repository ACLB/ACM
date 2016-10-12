#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const  double eps = 1e-11;
const  double Pi = acos(-1.0);
double h,v;
double fz[5]= {9839.1385,9917.4155,9995.6925,10073.9695,10248.093};
double ang[5];
int dbcmp(double s)
{
    if(fabs(s) < eps) return 0;
    return s>0 ?1:-1;
}
double fm()
{
    return 0.625*(4-2*h)*v*v;
}
double Getalpha()
{
    return atan((31557.3*h-23655.708)/fm());
}
double ash(double x)
{
    return log(x + sqrt(x*x+1));
}
double ach(double x)
{
    return log(x + sqrt(x*x-1));
}
double arth(double x)
{
    return 0.5*log((1+x)/(1-x));
}
double Get()
{
    double ans = fm()/(7*9.8);
    double a = Getalpha();
    return ans*(cosh(asinh(154.35*9.8/(fm())+tan(a)))-cosh(asinh(tan(a))));
}
double Getans()
{
    double ans = h;
    for(int j = 0; j<5; j++)
    {
        ans +=(cos(atan(fm()/(31557.3*h-fz[j]))));
        ang[j] = atan(fm()/(31557.3*h-fz[j]))/Pi*180;
    }
    ans+=Get();
    return ans;
}
void solve()
{
    double ans,s;
    while(~scanf("%lf %lf",&v,&s))
    {
        ans = 0;
        double l = 0,r = 2;
        while(dbcmp(r-l)>0)
        {
            h = (l+r)/2;
            double st = Getans();
            if(dbcmp(st-s)>=0)
            {
                ans = h;
                r = h;
            }
            else l = h;
        }
        h = ans;
//        double al = atan(Getalpha());
//        double lastans = Get();
//        printf("lastans = %.10f\n",lastans);
        printf("when v  = %.10f s = %.10f the h = %.10f s' = %.10f\n",v,s,ans,Getans());
        printf("alpha = %.10f alphaangle = %.10f\n",Getalpha(),Getalpha()*180/Pi);
        double XL = Get();
        for(int i = 0; i<5; i++)
        {
            printf("angle%d = %.10f\n",i+1,ang[i]);
            XL+=(sin(atan(ang[i])));
        }
        printf("XL = %.10f\n",XL);
        printf("\n");
    }
}
int main()
{
    freopen("out1.txt","w",stdout);
    freopen("in1.txt","r",stdin);
    solve();
    fclose(stdout);
    fclose(stdin);
    freopen("out2.txt","w",stdout);
    freopen("in2.txt","r",stdin);
    solve();
    fclose(stdout);
    fclose(stdin);
    return 0;
}
