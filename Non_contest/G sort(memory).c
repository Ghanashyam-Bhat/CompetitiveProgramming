#include <stdio.h>
#include <stdlib.h>

int check(int **ptr,int n);
void f(int **ptr,int i);
int loop(int **ptr,int n);

int main()
{
	int n,trials,*p,**ptr;
	fflush(stdin);scanf("%d",&trials);
	for(int trial=0;trial<trials;trial++)
	{
		fflush(stdin);scanf("%d",&n);
		p= (int*)malloc(n*sizeof(int));
		ptr = (int**)malloc(n*sizeof(int*));
		for(int j=0;j<n;j++)
		{
			scanf("%d",(p+j));
			*(ptr+j) = (p+j);
		}
		printf("%d\n",loop(ptr,n));
		free(p);free(ptr);
	}
	p=NULL;ptr=NULL;
}

int check(int **ptr,int n)
{
	for(int i=0;i<n-1;i++)
	{
		if(**(ptr+i)>**(ptr+i+1))
			return 0;
	}
	return 1;
	
}
void f(int **ptr,int i)
{
	int *temp;
	if(**(ptr+i)>**(ptr+i+1))
	{
		temp = *(ptr+i+1);
		*(ptr+i+1) = *(ptr+i);
		*(ptr+i) = temp;
	}
}

int loop(int **ptr,int n)
{
	for(int i=0;i<n;i++)
		{
			if((i+1)%2)
			{
				for(int j=1;j<n-1;j+=2)
				{
					if(check(ptr,n))
					{
						return i;
					}
					else
					{
						f(ptr,j);
					}
				}
			}
			else 
			{
				for(int j=0;j<n-1;j+=2)
				{
					if(check(ptr,n))
					{
						return i;
					}
					else
					{
						f(ptr,j);
					}
				}
			}
			
		}
}