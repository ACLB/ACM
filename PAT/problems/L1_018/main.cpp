#include <bits/stdc++.h>

using namespace std;
int h,m;

int main(){
    scanf("%d:%d",&h,&m);
    if(h>=0 && h<12 || (h == 12 && m == 0)) {
        printf("Only %02d:%02d.  Too early to Dang.\n",h,m);
    }
    else {
        h -=12;
        if(m) h++;
        for(int i =0 ;i<h;i++){
            printf("Dang");
        }
        printf("\n");
    }
    return 0;
}
