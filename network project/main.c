#include<stdio.h>
#include<stdlib.h>

int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[20][20],parent[20];
int find(int);
int uni(int,int);


char division[][20] = {"DHAKA","GAZIPUR","JAMALPUR","KISHOREGANJ","MANIKGANJ","MYMENSINGH","MUNSHIGANJ","NARAYANGANJ","NARSINGDI","NETROKONA","SHERPUR","TANGAIL"};



void main()
{

    printf("\n\n\tNetwork design of different branches of AUAAUA inc. within Dhaka division by using Kruskal's algorithm\n\n");

    freopen("in.txt","r",stdin);

    scanf("%d",&n);//entering the number of vertices:12


    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d",&cost[i][j]);//entering cost adjacency matrix
            if(cost[i][j]==0)
                cost[i][j]=999;//
        }
    }
   // printf("\nThe edges of Minimum Cost Spanning Tree are\n\n");
    while(ne<n)
    {
        min=999;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(cost[i][j]<min)//if path exists
                {
                    min=cost[i][j];//min=path cost
                    a=u=i;//
                    b=v=j;
                }
            }
        }
       u=find(u);
       v=find(v);
        if(uni(u,v))
        {
            printf("\n%d. (%s<-->%s) = %d Kilometers\n",ne++,division[a-1],division[b-1],min);
            mincost +=min;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("\n\tMinimum path to cover = %d Kilometers\n",mincost);
    getch();
}
int find(int i)
{
    while(parent[i])
        i=parent[i];
    return i;
}
int uni(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}
