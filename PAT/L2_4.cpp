#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdio> 
#include <iostream>
#include <algorithm>

using namespace std;

const int Max = 1100;

typedef struct node {

	int data;
	
	int l,r;
}Tree;

Tree Tr[Max];

int top;

int  n;

int  arr[Max];

bool op;

void Init(){

	for(int i = 0;i<Max;i++) {
		
		Tr[i].l = Tr[i].r = -1;
	}
		
}

int Creat(int data)
{
	Tr[++top].data = data;
	
	return top;
}
bool Build(int num,int u,int L,int R)
{
	
	if(L>R) return true;
	 
	int i = L;
	
	for(;i<=R;i++)
	{
		if(!op) 
		{
			if(arr[u]<=arr[i]) break;
		}
		else 
		{
			if(arr[u]>arr[i]) break;
		}
	}
	
	int l=-1,r=-1,endL,endR;
	
	endL = i-1;
	
	if(i!=L)
	
	{
		l= Creat(arr[L]);
	
		Tr[num].l = l;
	
		if(!Build(l,L,L+1,endL))
		{
		return false;
		}
	}	
	
	
	r = i;
	
	if(r>R) return true;
	
	for(i++;i<=R;i++)
	{
	
		if(!op) 
		{
			if(arr[i]<arr[u]) return false;
		}
		else
		{
			
			if(arr[i]>=arr[u]) return false;
		}
	}
	
	int numr = Creat(arr[r]);
	
	Tr[num].r = numr;
	
	if(!Build(numr,r,r+1,R))
	{
		return false;
	}	
	
	return true;
} 

void Get(int num)
{
	if(num==-1)
	{
		return ;
	}
	
	Get(Tr[num].l);
	
	Get(Tr[num].r);
	
	if(op) printf(" %d",Tr[num].data);
	
	else printf("%d",Tr[num].data);
	
	op = true;
}
int main() {
	
	while(~scanf("%d",&n)) {
		
		Init();
		
		for(int i = 1; i<= n; i++) {
			
			scanf("%d",&arr[i]);
		} 
		
		if(n<=0)
		{
			printf("NO\n");
		
			continue;
		}
	
		bool flag1 = false,flag2=false;
	
		for(int i = 2;i<=n;i++)
		{
			if(arr[i]<arr[1])
			{
				flag1 = true ;
				
			}
			else
			{
				flag2 = true;
			}
		}
		
		if(!flag1||!flag2) op = false;
		
		else 
		{
			if(arr[1]>arr[2]) 
				
				op=false;
			
			else op = true;
		}
		
		top = 1;
		
		Tr[1].data = arr[1];	
		
		if(!Build(1,1,2,n))
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
			op = false;
			Get(1);
			printf("\n");
		}
	}
	return 0;
}
