#include<bits/stdc++.h>
using namespace std;
int find_min(int dist[],int mst_present[],int n)
{
    int mini=INT_MAX,min_ind;
    for(int i=0;i<n;i++)
    {
        if(dist[i]<mini && mst_present[i]==0)
            mini=dist[i],min_ind=i;
    }
    return min_ind;
}
void prims_mst(int graph[][10],int n)
{
    int parent[n];
    int mst_present[n];
    int dist[n];
    for(int i=0;i<n;i++)
        dist[i]=INT_MAX,mst_present[i]=0;
    parent[0]=-1;
    dist[0]=0;
    for(int cnt=0;cnt<n-1;cnt++)
    {
        int u=find_min(dist,mst_present,n);
        mst_present[u]=1;
        for(int v=0;v<n;v++)
        {
            if(graph[u][v] && mst_present[v]==0 && graph[u][v]<dist[v])
            {
                parent[v]=u;
                dist[v]=graph[u][v];
            }
        }
    }


    for(int i=1;i<n;i++)
    {
        cout<<parent[i]<<" -> "<<i<<" = "<<graph[i][parent[i]]<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    int graph[n][10];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>graph[i][j];
    prims_mst(graph,n);   
}
