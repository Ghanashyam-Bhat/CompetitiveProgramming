#include <stdio.h>
void swap(int a[],int i,int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void quick(int a[],int l,int n)
{
	if(l<n)
	{
		int pivot = a[l];
		int i=l+1,j=n-1,t1=0,t2=0;
		while(i<=j)
		{
			if (a[i]<pivot) //updating i if the a[i] value is less than pivot(it means, a[i] is on crt side)
				i++;
			else if(t1==0) 
				t1 = 1; //Halting if a[i] is in wrong side
			if (a[j]>pivot) 
				j--;
			else if(t2==0)
				t2=1;//t2 is halted
			if (t1&&t2)
			{ 
				swap(a,i,j);//Swapping at 2 halted positions
				t1=0;i++;//Unhalting
				t2=0;j--;
			}
		}
		swap(a,l,j);//Swapping pivot and element at jth position
		quick(a,l,j);quick(a,i,n);//Calling recursive functions for left and right of pivot
	}
}

int main()
{
	int a[]={1,2,4,3,10,6,5,8,9},n = 9;
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
	quick(a,0,n);
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}