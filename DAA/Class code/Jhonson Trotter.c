#include <stdio.h>
#define RTOL 0
#define LTOR 1

int get_mobile(int a[10],int dir[10],int n)
{
	int mobile=0;
	for (int i=0;i<n;i++)
	{
		if(dir[i]==RTOL && i!=0)
		{
			if ((a[i]>a[i-1]) && a[i]>mobile)
				mobile=a[i];
				
		}
		else if(dir[i]==LTOR && i!=n-1)
		{
			if ((a[i]>a[i+1]) && a[i]>mobile)
				mobile=a[i];
		}
	}
	return mobile;
}

int search(int a[10],int n,int mobile)
{
	for (int i=0;i<n;i++)
	{
		if(a[i]==mobile)
			return i;
	}
	return -1;	
}

void swap(int i,int j,int a[10],int dir[10])
{
	int temp;
	
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
	
	temp = dir[i];
	dir[i] = dir[j];
	dir[j] = temp;
}

int fact(int n)
{
	if (n==0) return 1;
	return (n*fact(n-1));
}

void print_one_perm(int a[10],int dir[10],int n)
{
	int mobile = get_mobile(a,dir,n);
	int pos = search(a,n,mobile);
	
	if(dir[pos]==RTOL)
		swap(pos-1,pos,a,dir);
	else
		swap(pos,pos+1,a,dir);
	
	for (int i=0;i<n;i++) //This is to change the direction of all the elements greater than mobile element
	{
		if(a[i]>mobile)
		{
			if (dir[i]==RTOL)
				dir[i] = LTOR;
			else 
				dir[i] = RTOL;
		}
	}
	//By now we have created one more permutation according to the algorithm
	for(int i=0;i<n;i++)
		printf("%d",a[i]);
	printf("\n");
}


void printperm(int n)
{
	int a[10],dir[10];
	for(int i=0;i<n;i++)
	{
		a[i] = i+1;
		dir[i] = RTOL;
		printf("%d",a[i]);//First permutation
	}
	printf("\n");
	for(int i=1;i<fact(n);i++)
		print_one_perm(a,dir,n);	
}

int main()
{
	int n;printf("Enter n: ");scanf("%d",&n);
	printperm(n);
}