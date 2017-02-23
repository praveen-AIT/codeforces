#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int max_health(int a[], int n, int s)
{
    if(n < 0)
        return 0;

    return max(max_health(a, n-1, s+1), 
               s*a[n] + max_health(a, n-1, s));
}

void traverse(vector<vector<int> > a, int visited[], int v)
{
    visited[v] = true;

    for(int i=0; i<a[v].size(); i++)
        if(!visited[i])
            traverse(a, visited, a[v][i]);
}

int mother_vertex(vector< vector<int> > a, int v)
{
    int i, x;
    int visited[v] = {0};

    for(i=0; i<v; i++)
        visited[i]=0;

    for(i=0; i<v; i++)
    {
        if(!visited[i])
        {
            traverse(a, visited, i);
            x = i;
        }
    }

    for(i=0; i<v; i++)
        printf("%d\t", visited[i]);
    
    printf("%d\n", x);
    for(i=0; i<v; i++)
        visited[i]=0;

    traverse(a, visited, 5);
    
    for(i=0; i<v; i++)
        printf("%d\t", visited[i]);
    for(i=0; i<v; i++)
        if(!visited[i])
            return -1;
    return x;
}

int main()
{   
    int V;
    V = 7;
    vector<vector<int> > a(V);

    a[0].push_back(1);
    a[0].push_back(2);
    a[1].push_back(3);
    a[4].push_back(1);
    a[6].push_back(4);
    a[5].push_back(6);
    a[5].push_back(2);
    a[6].push_back(0);

    printf("%d\n", mother_vertex(a, V));
    return 0;
}

