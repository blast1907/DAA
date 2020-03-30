#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,r;
    cin>>n>>r;
    if(n<r)
        cout<<"Not valid"<<endl;
    else
    {
      r=min(r,n-r);
      ll bc[n+1][r+1];
      for(int i=0;i<=r;i++)
               bc[i][i]=1;
       for(int i=0;i<=n;i++)
             bc[i][0]=1;
       for(int i=2;i<=n;i++)
            for(int j=1;j<min(i,r+1);j++)
                bc[i][j]=bc[i-1][j]+bc[i-1][j-1];
        cout<<bc[n][r]<<endl;
    } 
}


/* This solution is developed using Dynamic programming strategy.
    Time comlexity of the program is O(n*r).
    Space complexity of this program is O(n*r);
*/
