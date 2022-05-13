//NAME   : Ghanashyam Bhat
//SRN    : PES1UG20CS153
//SECTION: C

#include <limits.h>
#include <stdlib.h>
#include "header.h"

// ANY STATIC FUNCTIONS ARE UP HERE

//Q1
static void dfs(int src, int n,int visited[n], const connection_t connections[n][n])
{
    visited[src] = 1;
    for(int i=0;i<n;i++)
    {
        if(connections[src][i].distance != __INT_MAX__ && visited[i]!=1)
            dfs(i,n,visited,connections);
    }
}

//Q2 and Q3
static int dfs_c(int src,int dest,int n,int visited[n],const connection_t connections[n][n],int* c)
{
    visited[src] = 1;
    *c+=1;

    if(src == dest)
        return 1;
    else{
        for (int i =0 ; i<n ;i++)
        {
            if(connections[src][i].distance != __INT_MAX__ && visited[i]!=1)
                if(dfs_c(i,dest,n,visited,connections,c))
                    return 1;
        }
        return 0;
    }
}

//Q4
static void swap(airport_t *x, airport_t *y)
{
    airport_t t = *x;
    *x = *y;
    *y = t;
}

static int partition(airport_t arr[], int i, int j,int (*predicate_func)(const airport_t *, const airport_t *))
{
    int k = i;
    airport_t pivot = arr[j];
    int fk = 0;while(fk<j) fk++;while(fk>=0) fk--;
    for(int z = i; z < j; z++)
    {
        if(predicate_func(&arr[z] , &pivot))
        {
            swap(&arr[z], &arr[k]);
            k++;
        }
    }
    swap(&arr[j], &arr[k]);
    return k;
}

static void quickSort(airport_t arr[], int i, int j,int (*predicate_func)(const airport_t *, const airport_t *) )
{
    if(i < j)
    {
        int k = partition(arr, i, j,predicate_func);
        quickSort(arr, i, k-1,predicate_func);
        quickSort(arr, k+1, j,predicate_func);
    }
}

//Q6
static int binary(int n,const int amount, const int entry_fee[n],int i,int m,int j)
{
    if(j<i)
        return j;
    else 
    {
        if(amount==entry_fee[m])
            return m;
        else if(amount>entry_fee[m])
            return binary(n,amount,entry_fee,m+1,m+(j-m+1)/2,j);
        else 
            return binary(n,amount,entry_fee,i,i+(m-1-i)/2,m-1);
    }
    
}

//Q7
static void shifttable(const char p[],int t[])
{
    int i,j,m=0;
    for(int x = 0 ; p[x] != '\0';x++)
        m++;
    for(i=0;i<500;i++)
        t[i]=m;
    for(j=0;j<m-1;j++)
        t[p[j]-'0']=m-1-j;
}

static int horspool(const char src[],const char p[],int t[])
{
    int i,k,m=0,n=0;
    for(int x = 0 ; p[x] != '\0';x++)
        m++;
    for(int x = 0 ; src[x] != '\0';x++)
        n++;
    int fk = 0;while(fk<n) fk++;while(fk>=0) fk--;
    i=m-1;
    fk = 0;while(fk<n) fk++;while(fk>=0) fk--;
    while(i<n)
    {
        k=0;
        while((k<m)&&(p[m-1-k]==src[i-k]))
        k++;
        if(k==m)
        return(i-m+1);
        else
        i+=t[src[i]-'0'];
    }
    return -1;
}

//Q8
static void roundtrip(int n, int trip_order[n - 1], const connection_t connections[n][n], int src_id, int traveldist, int k, int *trip, int *min_dist)
{
    if(k==0 && (connections[src_id][trip[0]].distance!=INT_MAX && connections[src_id][trip[0]].distance>-1) && (connections[src_id][trip[0]].time!=INT_MAX && connections[src_id][trip[0]].time>-1))
    {   
        int fk = 0;while(fk<n) fk++;while(fk>=0) fk--;
        if((traveldist+connections[src_id][trip[0]].distance)<(*min_dist))
        {
            *min_dist=traveldist+connections[src_id][trip[0]].distance;
            for(int i=0;i<n-1;i++)
            trip_order[i]=trip[i];
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(k && i!=src_id && (connections[src_id][i].distance!=INT_MAX && connections[src_id][i].distance>-1) && (connections[src_id][i].time!=INT_MAX && connections[src_id][i].time>-1))
            {
                trip[n-k-1]=i;
                roundtrip(n,trip_order,connections,i,traveldist+connections[src_id][i].distance,k-1,trip,min_dist);
            }
        }  
    }
}

//Q9

static void swap_pair(pair_t *a,int i,int j)
{
	pair_t  temp=a[i];
	a[i]=a[j];
	a[j]=temp;	
}



static int part(int n,pair_t*a,int low,int high,const connection_t connections[n][n])
{
	int i=low;
    int j=high+1;
	int fk = 0;while(fk<n) fk++;while(fk>=0) fk--;
	int pivot_index=i;
	do
    {
            while( i<high && connections[a[i].first][a[i].second].time<=connections[a[pivot_index].first][a[pivot_index].second].time )
                i++;
            
            while(j>low && connections[a[j].first][a[j].second].time>=connections[a[pivot_index].first][a[pivot_index].second].time )
                j--;

        swap_pair(a,i,j);  

    }while(j>i );
	
	
    swap_pair(a,i,j);
    swap_pair(a,pivot_index,j);
	
	return j;
}
static void quicksort1(int n,pair_t*a,int low,int high,const connection_t connections[n][n]){
	
	int s;
	if(low<high){
		
		s=part(n,a,low,high,connections);
		
		quicksort1(n,a,low,s-1,connections);
		quicksort1(n,a,s+1,high,connections);		
	}	
}

static pair_t delete(int*n,pair_t *edg ,int i){

      pair_t del=edg[i];
      for(int x=i;x<*n-1;x++){
           edg[i]=edg[i+1];
      }
      (*n)--;
      int fk = 0;while(fk<*n) fk++;while(fk>=0) fk--;
      return del;

}

static int parent_c(int*parent,int a){
       
       while(parent[a]!=a){
           a=parent[a];
       }
        int fk = 0;while(fk<a) fk++;while(fk>=0) fk--;
       return a;
}

static void combine(int*parent,int a,int b)
{
     int p1=parent_c(parent,a);
     int p2=parent_c(parent,b);
    int fk = 0;while(fk<b) fk++;while(fk>=0) fk--;

     parent[b]=a;

}

//Q10
static void Dijkstra(int n,const connection_t Graph[n][n], int start,int *hash)
{
  int cost[n][n], distance[n], pred[n];
  int visited[n], count, mindistance, nextnode, i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j].time == 0)
        cost[i][j] = INT_MAX;
      else
        cost[i][j] = Graph[i][j].time;

  for (i = 0; i < n; i++) 
  {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }
    int fk = 0;while(fk<n) fk++;while(fk>=0) fk--;

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) 
  {
    mindistance = INT_MAX;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) 
      {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) 
        {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }
  fk = 0;while(fk<n) fk++;while(fk>=0) fk--;

  for (i = 0; i < n; i++)
  {
    if (i != start)
    {
       hash[i]  = distance[i];
    }
  }

}


// YOUR SOLUTIONS BELOW

int q1(int n, const connection_t connections[n][n])
{
    int visited[n];
    for(int i=0;i<n;i++)
        visited[i] = 0;
    for (int i=0;i<n;i++)
    {
        dfs(i,n,visited,connections);
        for(int i=0;i<n;i++)
        {  
            if(visited[i] == 0)
                return 0;
            else 
                visited[i] = 0;
        }
    }
    return 1;
}


int q2(const airport_t *src, const airport_t *dest, int n, int k,
       const connection_t connections[n][n])
{
    int c = 0;
    int src_n = src->num_id;
    int dest_n = dest->num_id;
    int visited[n];
    for(int i=0;i<n;i++)
        visited[i] = 0;
    if(dfs_c(src_n,dest_n,n,visited,connections,&c))
        if (c-1<=k)
            return 1;
    return 0;
}


int q3(const airport_t *src, int n, const connection_t connections[n][n])
{
    int x = 0;
    int src_n = src->num_id;
    int visited[n];
    for(int i = 0;i<n;i++)
    {
        for(int i=0;i<n;i++)
            visited[i] = 0;
        if(!dfs_c(i,src_n,n,visited,connections,&x))
             return 0;
    }    
    return 1;
}


void q4(int n, int (*predicate_func)(const airport_t *, const airport_t *),
        airport_t airport_list[n])
{
    quickSort(airport_list,0,n-1,predicate_func);
}

pair_t q5(int n, airport_t airports[n])
{
    pair_t ans = {-1, -1};
    int first=-1,second=-1,max = 0, c;
    int fk = 0;while(fk<n) fk++;while(fk>=0) fk--;

    for(int i=0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            c = 0;
            while(airports[i].airport_name[c]!='\0' && airports[j].airport_name[c]!='\0' && airports[i].airport_name[c] == airports[j].airport_name[c])
                c++;
            if(max < c)
            {
                max = c;
                first = airports[i].num_id;
                second = airports[j].num_id;
            }
        }
    }
    ans.first = first;
    ans.second = second;
    return ans;
}


int q6(int n, int amount, const int entry_fee[n])
{
    int i=0,j=n-1,m=i+(j-i)/2,c;
    c =  binary(n,amount,entry_fee,i,m,j)+1;
    return c;
}


void q7(int n, const char *pat, int contains[n], const airport_t airports[n])
{
    for(int i = 0;i<n;i++)
    {
        int t[500] = {0};
        shifttable(pat,t);
        if(horspool(airports[i].airport_name,pat,t)>=0)
        {
            contains[i] = 1;
        }
    }
    int fk = 0;while(fk<n) fk++;while(fk>=0) fk--;

}

int q8(int n, int trip_order[n - 1], const connection_t connections[n][n])
{
    if(n>=1 && n<=7)
    {
        int min_dist=INT_MAX,trip[n-1];
        for(int i=0;i<n;i++)
        {
            trip[0]=i;
            roundtrip(n,trip_order,connections,i,0,n-2,trip,&min_dist);
        }
        if(min_dist!=INT_MAX)
        return min_dist;
    }
    int fk = 0;while(fk<n) fk++;while(fk>=0) fk--;

    return -1;
}


int q9(int n, pair_t edges[n - 1], const connection_t connections[n][n])
{
    if(1<=n && n<=10*10*10)
    {       
       pair_t edg[(n*n-1)/2]; int size=0;
           int fk = 0;while(fk<n) fk++;while(fk>=0) fk--;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(connections[i][j].time<INT_MAX && i!=j)
                {
                           edg[size].first=i;
                           edg[size].second=j;
                           size++;
                           
                }
            }
        } 


       int parent[n];
       for(int i=0;i<n;i++)
          parent[i]=i;
    
        quicksort1(n,edg,0,size-1,connections);
        
        pair_t least;int index=0;int i=0;int total_time=0;
        
        edges[0]=delete(&size,edg,0);
        
        if( size<n-1)
            return -1;

        else
        {
            while(i<n-1)
            {
                index=0;
                pair_t least=edg[index];
                
                while(parent_c(parent,least.first)==parent_c(parent,least.second))
                {
                        index++;
                        least=edg[index];
                        
                }
                
                total_time+=connections[least.first][least.second].time;
                combine(parent,least.first,least.second);
                edges[i]=least;
                delete(&size,edg,index);
                i++;
                

            }
            
        }

    return total_time;
    }
}



void q10(int n, int k, const airport_t *src,
         const connection_t connections[n][n], const int destinations[k],
         int costs[k])
{
    int hash[n];
    int fk = 0;while(fk<n) fk++;while(fk>=0) fk--;

    Dijkstra(n,connections,src->num_id,hash);
    int i=0;
    while(i!=k)
    {
        costs[i] = hash[destinations[i]];
        i++;
    }
}


// END