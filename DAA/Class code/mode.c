//Find mode:Transform and Conquer
#include <stdio.h>
void sort(int a[],int n)
{
	int temp,min;
	for(int i=0;i<n-1;i++)
	{
		min = i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j] < a[min])
				min = j;
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}

int mode(int a[],int n)
{
	sort(a,n);
	int m = a[0],c = 0,cur = a[0],cur_c = 0;
	for(int i=0;i<n;i++)
	{
		if(cur==a[i])
			cur_c++;
		else
		{
			cur_c = 1;
			cur = a[i];
		}
		
		if(c<cur_c)
		{
			c = cur_c;
			m = cur;
		}
	}
	return m;
}

int main()
{
	int a[30]={1,6,4,3,8,5,4,5,3,6,7,8,4,3,1,2,9,6,7,4,8,5,2,3,4,5,7,7,8,5},n = 30;
	int m = mode(a,n);
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n%d",m);
}