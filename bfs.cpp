//bfs for an undirected graph using adjacency matrix
/*
5
1
2
3
4
5
6
1 2
2 3
3 4
4 5
3 5
1 4


*/
#include <bits/stdc++.h>
#define MAX 1000
#define MOD 1000000007
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
        visited[start]=1;
        cout<<start+1<<" ";
        q.pop();
        if(vertexVal[start]==val)
        {
            return start;
        }    
        for (int j = 0; j < totalVertices; ++j)
        {
            if(graph[start][j]==1&&visited[j]==0)
            {
		//cout<<endl<<start+1<<"pushing"<<j+1<<endl;
                q.push(j);
		visited[j]=1;
            }
        }
    }
    return -1;

}
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.out","w",stdout);
    int V,E,v1,v2,val;
    
    vvi graph(1000,vi(1000,0));
    vi vertexVal(1000,0);
    vi visited(1000,0);
    cout<<"Enter the number of vertices:"<<endl;
    cin>>V;
    //insert the value of the vertex
    for (int i = 0; i < V; ++i)
    {
        cout<<"\nEnter the value of node "<<i<<":";
        cin>>vertexVal[i];

    }
    cout<<"Enter the number of edges:"<<endl;
    cin>>E;
    cout<<"Enter the edges in the graph:"<<endl;
    for (int i = 0; i < E; ++i)
    {
        cin>>v1>>v2;
        graph[v1-1][v2-1]=1;
        graph[v2-1][v1-1]=1;
    }
    cout<<"The graph matrix is:"<<endl;
    displayMatrix(graph,V);
    /*
    cout<<"Enter the value of the node you want to search for:";
    cin>>val;
    */
    int nodeIndex=0;
    bfs(graph,vertexVal,visited,val,V,0);
    /*
    for(int i=0;i<V;i++)
    {
        nodeIndex=bfs(graph,vertexVal,visited,val,V,i);
        if(nodeIndex!=-1)
            break;
    }
    if(nodeIndex!=-1)
        cout<<"The value "<<val<<" is present in node "<<nodeIndex+1<<endl;
    else
        cout<<"The value "<<val<<" is not present in the graph"<<endl;
    */
    return 0;

}
