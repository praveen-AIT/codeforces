#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int traverse(vector<vector<int> > a, int v, int indegree[], int visited[])
{
    visited[v]++;

    for(int i=0; i<a[v].size(); i++)
        if(visited[a[v][i]] > indegree[a[v][i]])
        {
            return 1;
        }
        else
            traverse(a, a[v][i], indegree, visited);
}

int iscyclic(vector<vector<int> > a, int v, int indegree[])
{
    int visited[v+2]={0}, i, x=0;

    for(i=0; i<v; i++)
    {
        if(!visited[i])
        {
            x += traverse(a, i, indegree, visited);
            if(visited[i] > indegree[i])
                return 1;
        }
        printf("\n");
    }
    return x;
}

int main()
{   
    int V;
    V = 4;
    vector<vector<int> > a(V);
    int indegree[V+2]={0};

    a[0].push_back(1);
    indegree[1]++;
    a[0].push_back(2);
    indegree[2]++;
    a[1].push_back(2);
    indegree[2]++;
    a[2].push_back(0);
    indegree[0]++;
    a[2].push_back(3);
    indegree[3]++;
    a[3].push_back(3);
    indegree[3]++;

    int ans = iscyclic(a, V, indegree);
    if(ans)
        printf("Graph contains cycle\n");
    else
        printf("Graph has no cycle\n");
    return 0;
}

