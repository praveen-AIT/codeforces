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

void topoUtil(vector<vector <int> >a, 
              int v, bool visited[], stack<int> &Stack)
{
    visited[v] = 1;

    for(int i=0; i<a[v].size(); i++)
        if(visited[a[v][i]] == 0)
            topoUtil(a, a[v][i], visited, Stack);

    Stack.push(v);
}

void topological_sort(vector<vector <int> >a, int v)
{
    bool *visited = new bool[v];
    stack<int> Stack;

    for(int i=0; i<v; i++)
        visited[i] = 0;

    for(int i=0; i<v; i++)
        if(visited[i] == 0)
            topoUtil(a, i, visited, Stack);

    while(!Stack.empty())
    {
        printf("%d\t", Stack.top());
        Stack.pop();
    }
}

int main()
{   
    int V;
    V = 6;
    vector<vector<int> > a(V);

    a[5].push_back(2);
    a[5].push_back(0);
    a[4].push_back(0);
    a[4].push_back(1);
    a[2].push_back(3);
    a[3].push_back(1);
    a[4].push_back(5);
    
    topological_sort(a, V);
    printf("\n");
    return 0;
}
