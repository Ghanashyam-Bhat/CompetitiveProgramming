#include <stdio.h>
int main()
{
	int n,r,l;scanf("%lld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&r,&l);
		if(r>l/2)
			printf("%d\n",(l%r));
		else
			printf("%d\n",l%((l/2)+1));
	}	
}