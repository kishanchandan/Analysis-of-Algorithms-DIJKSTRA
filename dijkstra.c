#include<stdio.h>

int graph[50][50];
int minfn(int x, int y);

int Dijkstra(int v)
{
  
  int vertex[v+1];
  
  for(int i=0;i<v+1;i++)
  {
    vertex[i]=0;
  }
  
  int vertex_visited[v+1];
  int shortest_path[v];
  
  int count = 1;
  int min = 999;
  int temp = 0;
  
  printf("\nStep\t");
  for(int i=2;i<=v;i++)
    {
	printf("V=%d\t",i);}
  printf("N\n----------------------------------------------------------------------------------");
  
  
  //Initializations
  printf("\n0\t");
  vertex_visited[1] = 1;
  count = 2;
 
  vertex[1]=1;
  int D[v+1][v+1];
  int P[v+1][v+1];
  for(int i=2;i<=v;i++)
  {
    D[1][i-1]= graph[1][i];
    
    P[1][i-1] = 1;
    printf("%d,%d\t",D[1][i-1],P[1][i-1]);
    if(D[1][i-1]<min)
    {
      min = D[1][i-1];
      temp = i;
    }
  }
  printf("%d\t",vertex_visited[1]);
  vertex[temp]=1;
  shortest_path[temp] = min;
 // printf("\nShortest path from source to vertex %d = %d\n",temp,min);
  printf("\n");
  
  
  for(int iteration=2;iteration<=v;iteration++)
  {
    
    printf("%d\t",iteration-1);
    
    vertex_visited[count] = temp;
    count++;
    
    min = 999;
  
    for(int dpvertex=1;dpvertex<v;dpvertex++)
    {
      
      if(vertex[dpvertex+1] == 0){
      
        D[iteration][dpvertex]=minfn(D[iteration-1][dpvertex],D[iteration-1][vertex_visited[count-1]-1]+graph[vertex_visited[count-1]][dpvertex+1]);
        
        if(minfn(D[iteration-1][dpvertex],D[iteration-1][vertex_visited[count-1]-1]+graph[vertex_visited[count-1]][dpvertex+1])==D[iteration-1][dpvertex])
        { 
          P[iteration][dpvertex]=P[iteration-1][dpvertex];
        }
        else
        {  
          P[iteration][dpvertex]=vertex_visited[count-1];
          
        }
       
          
        if(D[iteration][dpvertex]<min)
        {
          min = D[iteration][dpvertex];
          temp = dpvertex+1;
        }
        
        printf("%d,%d\t",D[iteration][dpvertex],P[iteration][dpvertex]);
      
      }
      else
      {
        printf("----\t");
      }
      
    }
    for(int m=1;m<=count-1;m++)
      printf("%d,",vertex_visited[m]);
    if(min!=999)
    {
      shortest_path[temp] = min;
    }
   // printf("\nShortest path from source to vertex %d = %d\n",temp,min);
    printf("\n");
    vertex[temp]=1;
  }

  for(int i=2;i<=v;i++)
  {
    printf("Shortest path from vertex 1 to %d is %d\n",i,shortest_path[i]);
  }
}

int minfn(int x, int y)
{
  int min;
  if(x<=y)
	{
	min = x;
	}
  
  else
	min = y;
  
  return min;
}

int inputgraph(int v)
{
  
  printf("Enter the adjacency matrix : \n");
  for(int i=1;i<=v;i++)
  {
    for(int j=1;j<=v;j++)
    {
      printf("Enter edge between %d and %d",i,j);
      scanf("%d",&graph[i][j]);
    }
  }
  Dijkstra(v);
  return 0;
}



int main()
{
  int v;
  printf("Enter the no of vertices : ");
  scanf("%d",&v);
  int graph[v+1][v+1];
  inputgraph(v);

}



