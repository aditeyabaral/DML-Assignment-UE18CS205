//Profile a connected undirected unweighted graph for the following properties.
#include <stdlib.h>
#include "graphprofile.h"

// 1. What is average degree of a vertex in the graph?
int avgDegree(int **g, int n) 
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(g[i][j])
                sum++;
        }
    }
    return (sum/n);
}

// 2. Is the graph a regular graph?
int isRegular(int **g, int n) 
{
    int first = 0;
    for (int i = 0; i<n ;i++)
    {
        if(g[0][i]) first++;
    }
    int deg;
    for (int i = 0;i<n;i++)
    {
        deg = 0;
        for (int j = 0;j<n;j++)
        {
            if(g[i][j])
                deg++;
        }
        if(deg!=first)
            return 0;
    }
    return 1;
}

// 3. Is the graph a complete graph?
int isComplete(int **g, int n) 
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!g[i][j])
                return 0;
        }
    }
    return 1;
}

// 4. Is the graph a cycle graph?
int isCycleGraph(int **g, int n) 
{
    int deg = 0;
    for (int i = 0;i<n;i++)
    {
        deg = 0;
        for(int j = 0;j<n;j++)
        {
            if (g[i][j])
                deg++;
        }
        if(deg!=2)
            return 0;
    }
    return 1;
}  

// 5. Is the graph a path graph but not a cycle graph?
int isPathGraph(int **g, int n) 
{
    int deg = 0;
    int ctr1 = 0, ctr2 = 0;
    for (int i = 0;i<n;i++)
    {
        deg = 0;
        for(int j = 0;j<n;j++)
        {
            if (g[i][j])
                deg++;
        }
        if(deg==1)
            ctr1++;
        if(deg==2)
            ctr2++;
    }
    return (ctr1==2 && ctr2==(n-2));
}

// 6. Does the graph has an Euler circuit?
int hasEulerCkt(int **g, int n) 
{
    int ctr;
    for(int i=0;i<n;i++)
    {
        ctr = 0;
        for(int j=0;j<n;j++)
        {
            if(g[i][j])
                ctr++;
        }
        if(ctr%2==1)
            return 0;
    }
    return 1;
}

// 7. Does the graph has an Euler path but not an Euler circuit?
int hasEulerPath(int **g, int n) 
{
    int ctr = 0, deg = 0;;
    for(int i=0;i<n;i++)
    {
        deg = 0;
        for(int j=0;j<n;j++)
        {
            if(g[i][j])
                deg++;
        }
        if(deg%2==1)
            ctr++;
    }
    return (ctr==2);
}

// 8. Does the graph satisfy the sufficient condition of the Ore's theorem?
// Sufficient condition for the graph to have a Hamilton according the Ore's theorem:
// deg(u) + deg(v) ≥ n for every pair of nonadjacent vertices u and v in the graph
int satifiesOresTheorem(int **g, int n) 
{
    int degree[n];
    for(int i=0;i<n;i++)
    {
        degree[i] = 0;
        for(int j=0;j<n;j++)
        {
            if(g[i][j])
                degree[i]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!g[i][j] && (degree[i]+degree[j])<n && i!=j)
                return 0;
        }
    }
    return 1;
}
