#include <stdio.h>
void merge(int a[],int l, int m, int n)
{
	if(l<=n)//Return void incase the array has only 1 element
		return;
	else 
	{
		//Temporary variable declaration
		int temp[m-l+1],t=0,i=l,j=m;
		
		//Recurrsive call for 1st piece (low to mid)
		merge(a,l,(m-l+1)/2,m);
		//Recurrsive call for 2nd piece (mid to end)
		merge(a,m,(n-m+1)/2,n);
		
		//While loop for merging 2 arrays and storing it in temporary array
		while(i<m||j<n)
		{
			//If array2 is empty and array 1 is not empty
			if(j==n)
			{
				temp[t] = a[i];
				t++;i++;
			}
			//If array1 is empty and array2 is not empty
			else if(i==m)
			{
				temp[t] = a[j];
				t++;j++;
			}
			//If both arrays not empty,comapring and inserting into temp
			else 
			{
				if(a[i]<a[j])
				{
					temp[t] = a[i];
					t++;i++;
				}
				else 
				{
					temp[t] = a[j];
					t++;j++;
				}
			}
		}
		//Copying temp back to original array
		for(int k=n-1;k>=l;k--)
		{
			a[k] = temp[t];
			t --;
		}
	}	
}

int main()
{
	//Example
	int a[]={1,2,4,3,10,6,5,8,9},n = 9;
	//Printing Unsorted array
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
	//Calling merge function and passing arguments
	merge(a,0,n/2,n-1);
	//printing the sorted array
	for(int i=0;i<n;i++)
		printf("%d\t",a[i]);
}