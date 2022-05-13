#include "header.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

// ANY STATIC FUNCTIONS ARE UP HERE

static void q1_dfs (int x , int vis[] , int n , const connection_t graph[n][n])
{
    vis[x] = 1;
    for(int i = x ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if (graph[i][j].distance != __INT_MAX__ && vis[j]!= 1)
            {
                q1_dfs(j , vis , n , graph);
            }
        }
    }
}

static int check(int vis[] , int n)
{

    for (int i = 0 ; i < n ; i++)
    {
        if (vis[i] != 1)
        {
            return 0;
        }
        vis[i] = 0;
    }
    return 1;
}

static void q2_dfs (int x , int vis[] , int n , const connection_t graph[n][n] , int dest , int num , int *ans)
{
    vis[x] = 1;
    if (x == dest)
    {
        
        int flag = 0;
        for (int i  = 0 ; i < n ; i++)
        {
            if (vis[i] == 1)
            {
                flag ++;
            }
        }
        if (flag <= num+1)
        {
            *ans = 1;
        }
    }
    for(int i = x ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if (graph[i][j].distance != __INT_MAX__ && vis[j]!= 1)
            {
               q2_dfs(j , vis , n , graph , dest , num , ans);
            }
        }
    }

}

static void q3_dfs (int x , int vis[] , int n , const connection_t matrix[n][n] , int s , int *ans)
{
    vis[x] = 1;
    for(int i = x ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if (matrix[i][j].distance != __INT_MAX__ && j == s)
            {
                *ans = 1;
            }
            if (matrix[i][j].distance != __INT_MAX__ && vis[j]!= 1)
            {
                q3_dfs(j , vis , n , matrix , s , ans);
            } 
        }
    }
}

static void swap(airport_t *x, airport_t *y)
{
    airport_t t = *x;
    *x = *y;
    *y = t;
}

static int partition(airport_t arr[], int start, int end,int (*predicate_func)(const airport_t *, const airport_t *))
{
    int pIndex = start;
    airport_t pivot = arr[end];
    int i;
    for(i = start; i < end; i++)
    {
        if(predicate_func(&arr[i] , &pivot))
        {
            swap(&arr[i], &arr[pIndex]);
            pIndex++;
        }
    }
    swap(&arr[end], &arr[pIndex]);
    return pIndex;
}

static void quickSort(airport_t arr[], int start, int end,int (*predicate_func)(const airport_t *, const airport_t *) )
{
    if(start < end)
    {
        int pIndex = partition(arr, start, end,predicate_func);
        quickSort(arr, start, pIndex-1,predicate_func);
        quickSort(arr, pIndex+1, end,predicate_func);
    }
}

static int len(airport_t airport1,airport_t airport2)
{
    int i=0;
    while(airport1.airport_name[i]!='\0' && airport2.airport_name[i]!='\0' && airport1.airport_name[i] == airport2.airport_name[i])
    {
        i++;
    }
    return i;
}

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
    i=m-1;
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


static void Dijkstra(int n,const connection_t Graph[n][n], int start,int *hash) {
  int cost[n][n], distance[n], pred[n];
  int visited[n], count, mindistance, nextnode, i, j;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j].time == 0)
        cost[i][j] = INT_MAX;
      else
        cost[i][j] = Graph[i][j].time;

  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    mindistance = INT_MAX;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  for (i = 0; i < n; i++)
    if (i != start) {
       hash[i]  = distance[i];
    }
}

// YOUR SOLUTIONS BELOW

int q1(int n, const connection_t connections[n][n])
{
    int vis[100000];

    for(int i = 0 ; i < n ; i++)
    {
        vis[i] = 0;
    }
    int ans = 1;

    for (int i = 0 ; i < n ; i++)
    {
        q1_dfs(i , vis , n , connections);
        ans = ans & check(vis , n);
    }
    return ans;

}

int q2(const airport_t *src, const airport_t *dest, int n, int k,const connection_t connections[n][n])
{
    int sval = src->num_id;
    int dval = dest->num_id;
    int vis[100000];
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        vis[i] = 0;
    }
    q2_dfs(sval , vis , n , connections , dval , k , &ans);
    if(ans == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int q3(const airport_t *src, int n, const connection_t connections[n][n])
{
    int s = src->num_id;
    int vis[100000];
    int ans = 0;
    for(int i = 0 ; i < n ; i++)
    {
        vis[i] = 0;
    }
    q3_dfs(s , vis , n , connections, s , &ans);
    return ans;
}

void q4(int n, int (*predicate_func)(const airport_t *, const airport_t *),airport_t airport_list[n])
{
    quickSort(airport_list,0,n-1,predicate_func);
}

pair_t q5(int n, airport_t airports[n])
{
    pair_t ans = {-1, -1};
    int max = 0;
    int a;
    for(int i=0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            a = len(airports[i],airports[j]);
            if(max < a)
            {
                max = a;
                ans.first = airports[i].num_id;
                ans.second = airports[j].num_id;
            }
        }
    }
    return ans;

}

int q6(int n, int amount, const int entry_fee[n])
{
        int si=0, ei=n-1;
        int mid;
        while(si <= ei) {

            mid = si + (ei-si)/2; 


            if(entry_fee[mid] == amount) {
                return mid+1;
            } else if(entry_fee[mid] < amount) {
                si = mid+1;
            } else { 
                ei = mid-1;
            }
        }

        return si;
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
}


static void roundtrip(int n, int trip_order[n - 1], const connection_t connections[n][n], int srcid, int traveldist, int k, int *trip, int *min_dist)
{
    if(k==0 && (connections[srcid][trip[0]].distance!=INT_MAX && connections[srcid][trip[0]].distance>-1) && (connections[srcid][trip[0]].time!=INT_MAX && connections[srcid][trip[0]].time>-1))
    {
        if((traveldist+connections[srcid][trip[0]].distance)<(*min_dist))
        {
            *min_dist=traveldist+connections[srcid][trip[0]].distance;
            for(int i=0;i<n-1;i++)
            trip_order[i]=trip[i];
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(k && i!=srcid && (connections[srcid][i].distance!=INT_MAX && connections[srcid][i].distance>-1) && (connections[srcid][i].time!=INT_MAX && connections[srcid][i].time>-1))
            {
                trip[n-k-1]=i;
                roundtrip(n,trip_order,connections,i,traveldist+connections[srcid][i].distance,k-1,trip,min_dist);
            }
        }  
    }
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
    return -1;
}

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
      return del;

}

static int parent_c(int*parent,int a){
       
       while(parent[a]!=a){
           a=parent[a];
       }
       return a;
       
    

}

static void combine(int*parent,int a,int b)
{
     int p1=parent_c(parent,a);
     int p2=parent_c(parent,b);
     parent[b]=a;

}



int q9(int n, pair_t edges[n - 1], const connection_t connections[n][n])
{
    if(1<=n && n<=10*10*10)
    {       
       pair_t edg[(n*n-1)/2]; int size=0;
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
void q10(int n, int k, const airport_t *src, const connection_t connections[n][n], const int destinations[k],int costs[k])
{
    int hash[n];
    Dijkstra(n,connections,src->num_id,hash);
    int i=0;
    while(i!=k)
    {
        costs[i] = hash[destinations[i]];
        i++;
    }
}

// END
