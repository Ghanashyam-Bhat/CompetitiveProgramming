#include <stdio.h>
int sum(int a[],int lw,int up)
{
	int s = 0;
	for(int i=lw;i<=up;i++)
	{
		s+= a[i];	
	}	
	return s;
}

int fake()
{
	//Help!!
	
}

int main()
{
	int a[]={1,1,1,1,1,1,1,1,1,1,0,1,1};int n=13;
	printf("%d",fake(a,0,n));
}