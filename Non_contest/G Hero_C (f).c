//https://codeforces.com/problemset/problem/1561/C
#include <stdio.h>
struct monster
{
	int shield;
};
struct cave
{
	struct monster Monster[100];
	struct monster Mun[100];
	int max;
	int num;
}Cave[100];

int c,real_max;


int max()
{
	int max;
	for(int j=0;j<c;j++)
	{
		max = Cave[j].Mun[0].shield;
		for(int i=0;i<Cave[j].num;i++)
		{
			if(Cave[j].Mun[i].shield > max)
			{
				max = Cave[j].Mun[i].shield;
			}
		}
		Cave[j].max = max;
	}
}

int prior()
{
	for(int j=0;j<c;j++)
	{
		for(int i=0;i<Cave[j].num;i++)
		{
			Cave[j].Mun[i].shield= Cave[j].Monster[i].shield-i;
		}
	}
}


void bubble_sort()
{
	struct cave temp;
	for(int i=0;i<c-1;i++)
	{
		for(int j=0;j<c-i-1;j++)
		{
			if(Cave[j].max>Cave[j+1].max)
			{
				temp = Cave[j];
				Cave[j]= Cave[j+1];
				Cave[j+1] = temp;
			}
		}
	}
}

int x;
int setmax()
{
	real_max= Cave[0].max;x =Cave[0].num;
	for(int j=1;j<c;j++)
	{
		if(real_max <Cave[j].max-x)
		{
			real_max= Cave[j].max-x;
		}
		x+=Cave[j].num;
	}
}


int main()
{
	int t;
	scanf("%d",&t);
	for(int x=0;x<t;x++)
	{
		scanf("%d",&c);
		for(int j=0;j<c;j++)
		{
			scanf("%d",&Cave[j].num);
			for(int i=0;i<c;i++)
			{
				scanf("%d",&Cave[j].Monster[i].shield);
			}
		}
		prior();max();bubble_sort();setmax();
		printf("%d\n",real_max+1);
	}
}