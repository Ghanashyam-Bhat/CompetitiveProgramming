#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef long double LD;
typedef long long ll;
#define int ll
#define pb push_back
#define mp make_pair
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
// -----<SCANF>-----
#define sfi(x) scanf("%d",&x);
#define sfi2(x,y) scanf("%d%d",&x,&y);
#define sfi3(x,y,z) scanf("%d%d%d",&x,&y,&z);

#define sfl(x) scanf("%lld",&x);
#define sfl2(x,y) scanf("%lld%lld",&x,&y);
#define sfl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z);
#define sfl4(x,y,z,x1) scanf("%lld%lld%lld%lld",&x,&y,&z,&x1);
#define sfl5(x,y,z,x1,y1) scanf("%lld%lld%lld%lld%lld",&x,&y,&z,&x1,&y1);
#define sfl6(x,y,z,x1,y1,z1) scanf("%lld%lld%lld%lld%lld%lld",&x,&y,&z,&x1,&y1,&z1);

#define sfs(x) scanf("%s",x);
#define sfs2(x,y) scanf("%s%s",x,y);
#define sfs3(x,y,z) scanf("%s%s%s",x,y,z);
// ----</SCANF>-----

// ----<PRINTF>-----
#define pfi(x) printf("%d\n",x);
#define pfi2(x,y) printf("%d %d\n",x,y);
#define pfi3(x,y,z) printf("%d %d %d\n",x,y,z);

#define pfl(x) printf("%lld\n",x);
#define pfl2(x,y) printf("%lld %lld\n",x,y);
#define pfl3(x,y,z) printf("%lld %lld %lld\n",x,y,z);

#define pfs(x) printf("%s\n",x);
#define pfs2(x,y) printf("%s %s\n",x,y);
#define pfs3(x,y,z) printf("%s %s %s\n",x,y,z);

#define pwe(x) printf("%lld ",x); // print without end
// ----</PRINTF>----
long long a,b,c,d,e,t,no,i,j,n,m,row,col,change,x;


int main()
{
   sfl(t);
   while(t--)
   {
       no=0;
       e=1;
       change=0;
       sfl2(n,x);
    long long array[n];
       REP(i,n)
       {
           sfl(array[i]);


       }
       REP(i,n)
       {
           no=no+array[i];
           if(no==x)
           {

               change=1;
               a=i;
           }
       }

       if(no==x)
       {
           printf("NO\n");
           e=0;

       }
       if(change==1&&no!=x)
       {
           b=array[a+1];
           array[a+1]=array[a];
           array[a]=b;

       }
       if(e==1)
       {
           printf("YES\n");
           REP(i,n)
           {
               printf("%d ",array[i]);
           }
           printf("\n");
       }





   }




    return 0;
}
