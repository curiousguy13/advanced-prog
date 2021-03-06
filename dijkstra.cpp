//dijkstra for an undirected graph using adjacency matrix
/*
6
1
2
3
4
5
6
9
1 6 14
5 4 6
6 5 9
3 4 11
3 2 10
3 1 9
4 2 15
2 1 7
2 3 10
1
5

*/
#include <bits/stdc++.h>
#define MAX 1000
#define MOD 1000000007
#define INF 99999
#define for_each(i,n) for(i=0;i<n;++i)
#define for_each_dec(i,n) for(i=n-1;i>=0;--i)
typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<LL> vll;
typedef vector<vll> vvll;


//fucntion to display a vector
template <typename T>
void displayVector(T v)
{
    for(typename T::iterator i=v.begin();i!=v.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}

//fucntion to display a vector
template <typename T>
void displayVector(T v,int size)
{
    for(typename T::iterator i=v.begin();i!=v.begin()+size;i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}

//function to display a matrix
template <typename T>
void displayMatrix(T mat)
{
    for(typename T::iterator i=mat.begin();i!=mat.end();i++)
    {
            displayVector(*i);       
    }
    cout<<endl; 
}

//function to display a matrix
template <typename T>
void displayMatrix(T mat,int size)
{
    for(typename T::iterator i=mat.begin();i!=mat.begin()+size;i++)
    {
            displayVector(*i,size);       
    }
    cout<<endl; 
}


//fucntion to input a vector
template <typename T>
void inputVector(T &v)
{
    for(typename T::iterator i=v.begin();i!=v.end();i++)
    {
        cin>>*i;
    }
}

//function to input a matrix
template <typename T>
void inputMatrix(T &mat)
{
    for(typename T::iterator i=mat.begin();i!=mat.end();i++)
    {
            inputVector(*i);
    }
}
int dfs(vvi graph,vi vertexVal,vi &visited,int val,int totalVertices,int start=0)
{
    visited[start]=1;
    if(vertexVal[start]==val)
    {
        return start;
    }
    for (int i = 0; i < totalVertices; ++i)
    {
         if(graph[start][i]==1 && visited[i]==0)
         {
            return dfs(graph,vertexVal,visited,val,totalVertices,i);
         }
    }
    return -1;
}

int bfs(vvi graph,vi vertexVal,vi &visited,int val,int totalVertices,int start=0)
{
    queue<int> q;
    q.push(start);
    for(int i=0;i<totalVertices;++i)
    {
        start=q.front();
        q.pop();
        if(vertexVal[start]==val)
        {
            return start;
        }    
        for (int j = 0; j < totalVertices; ++j)
        {
            if(graph[start][j]==1)
            {
                q.push(j);
            }
        }
    }
    return -1;

}
//pathTable-consists predecessor nodes from which we get the shortest path
void dijkstra(vvi graph,int totalVertices, vi &visited,int sourceNode,vi &distanceTable, vi &pathTable)
{
    //initializing the table with infinity(99999)
    for(int i=0;i<totalVertices;i++)
    {
        distanceTable[i]=INF;  
        pathTable[i]=i;
    }
    distanceTable[sourceNode]=0;
    int source=sourceNode;
    int min=-1,minIndex;
    while(min!=INF)
    {
        visited[source]=1;
        //updating distance table
        displayVector(distanceTable,totalVertices);
        for(int i=0;i<totalVertices;i++)
        {
            if(graph[source][i]!=0)
            {
                //if we found a shorter path then that node goes in the pathTable
                if(graph[source][i]+distanceTable[source]<distanceTable[i])
                {
                    distanceTable[i]=distanceTable[source]+graph[source][i];
                    pathTable[i]=source;
                }
            }
         
        }
        displayVector(distanceTable,totalVertices);
        //find the shortest distance node
        min=INF;minIndex=-1;
        for(int i=0;i<totalVertices;i++)
        {
            if(min>distanceTable[i]&&visited[i]==0)
            {
                min=distanceTable[i];
                minIndex=i;
            }
        }
        cout<<"min="<<min<<endl;
        //repeating the process with the node with shortest distance
        source=minIndex;

    }
}
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.out","w",stdout);
    int V,E,v1,v2,val,w,source;
    
    vvi graph(1000,vi(1000,0));
    vi vertexVal(1000,0);
    vi visited(1000,0);
    vi distanceTable(1000,0);
    vi pathTable(1000,0);
    cout<<"Enter the number of vertices:"<<endl;
    cin>>V;
    //insert the value of the vertex
    for (int i = 0; i < V; ++i)
    {
        cout<<"\nEnter the value of node "<<i+1<<":";
        cin>>vertexVal[i];

    }
    cout<<"Enter the number of edges:"<<endl;
    cin>>E;
    cout<<"Enter the edges in the graph in the format (v1,v2,weight)"<<endl;
    for (int i = 0; i < E; ++i)
    {
        cin>>v1>>v2>>w;
        graph[v1-1][v2-1]=w;
        graph[v2-1][v1-1]=w;
    }
    cout<<"The graph matrix is:"<<endl;
    displayMatrix(graph,V);
    cout<<"Enter the source node of the graph:";
    cin>>source;
    source=source-1;
    cout<<endl;
    cout<<"Enter the destination node of the graph:";
    int dest;
    cin>>dest;
    dest=dest-1;
    cout<<endl;
    dijkstra(graph,V,visited,source,distanceTable,pathTable);
    cout<<"The shortest distance of the source node to all other nodes in the graph:"<<endl;
    for(int i=0;i<V;i++)
    {
        if(distanceTable[i]!=INF)
            cout<<"Node"<<i+1<<":"<<distanceTable[i]<<endl;
        else
            cout<<"Node"<<i+1<<":"<<"INF"<<endl;
    }
    //displayVector(pathTable,V);
    
    cout<<"The shortest path to the destination node "<<dest+1<<"is:";
    int count=0;
    vi path;
    path.push_back(dest);
    while(dest!=source)
    {
        path.push_back(pathTable[dest]);
        dest=pathTable[dest];
        count++;
    }
    for(int i=count;i>=0;i--)
    {
        if(i!=0)
            cout<<path[i]+1<<"-->";
        else
            cout<<path[i]+1;
    }
    cout<<endl;
    return 0;

}