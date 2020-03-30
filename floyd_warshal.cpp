#include<bits/stdc++.h>
#define INF 10000000
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(i==j)
                a[i][j]=0;
            else
                a[i][j]=INF;
        }
    int u,v,w;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        a[u][v]=w;
    }
    for(int inter=0;inter<n;inter++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                a[i][j]=min(a[i][j],a[i][inter]+a[inter][j]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==INF)
                cout<<"INF ";
            else
                cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}






/* Time Complexity of this algorithm is O(V^3).
    We use dynamic programming strategy to find All pair shortest paths in a weighted graph.
    Space complexity of this algorithm is O(V^2);
*/
