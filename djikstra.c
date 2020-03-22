#include<stdio.h>
#include<limits.h>
int min(int a,int b)
{
    return (a<b)?a:b;
}
int min_du_nb(int ebt[],int bv[],int n)
{
    int min=INT_MAX,min_ind;
    for(int i=0;i<n;i++)
    {
        if(ebt[i]<min && bv[i]==0)
            min=ebt[i],min_ind=i;
    }
    return min_ind;
}

void djikstra(int a[][100],int ebt[],int bv[],int s,int n)
{
    ebt[s]=0;
    for(int i=0;i<n-1;i++)
    {
        int x=min_du_nb(ebt,bv,n);       
        bv[x]=1;
        for(int j=0;j<n;j++)
        {
            if(a[x][j]>0)
                ebt[j]=min(ebt[x]+a[x][j],ebt[j]);
        }
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[100][100];
    int ebt[n];
    int bv[n];
    for(int i=0;i<n;i++)
    {
        ebt[i]=INT_MAX;
        bv[i]=0;
        for(int j=0;j<n;j++)
            a[i][j]=0;
    }        
    for(int i=0;i<m;i++)
    {
        int x,y,wt;
        scanf("%d%d%d",&x,&y,&wt);
        a[x][y]=wt;
        a[y][x]=wt;
    }
    int source;
    scanf("%d",&source);
    djikstra(a,ebt,bv,source,n);
    for(int i=0;i<n;i++)
        printf("%d -> %d = %d \n",source,i,ebt[i]);

}
