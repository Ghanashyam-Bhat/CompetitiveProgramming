#include <stdio.h>
int bs(int a[],int lw,int up,int key,int mid)
{
	if (lw>up)
		return -1;
	else if(a[mid]==key)
		return mid;
	else if(key>a[mid])
		return bs(a,mid+1,up,key,(mid+up+1)/2);
	else 
		return bs(a,lw,mid-1,key,(mid+lw-1)/2);
}

int main()
{
	int a[]={1,2,3,4,5,6,7,22,88,100};int n=10;int key=88;
	printf("%d",bs(a,0,n-1,key,(n-1)/2));
}