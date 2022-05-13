#include <stdio.h>
void print(int a[],int n)
{
	for (int i=0;i<n;i++)
		printf("%d",a[i]);
	printf("\n");
}

void swap(int i,int j,int a[])
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void rec(int n,int m, int a[])
//We keep n and m seperatly because we need total number of elements to print elements
{
	if (n==0)
		print(a,m); //When n==0, printing the numbers in the order
	else
	{
		for(int i=0;i<n;i++)  
		{
			rec(n-1,m,a);
			if(n%2!=0)
				swap(0,n-1,a);
			else 
				swap(i,n-1,a);
		}
	}
}

int main()
{
	int a[]={1,2,3,4};
	int n = 4;
	rec(n,n,a);
	printf("%d",s);
}