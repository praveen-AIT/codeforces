#include <bits/stdc++.h>
#define ll unsigned long long int

using namespace std;

int visited[5] = {0};

void dfs(vector <vector <int> >a, int v, int s)
{
    visited[s] = 1;
    printf("%d\t", s);

    for(int i=0; i < a[s].size(); i++)
        if(!visited[a[s][i]])
            dfs(a, v, a[s][i]);
}

int main()
{   
    int V;
    V = 4;
    vector<vector<int> > a(V);

    a[0].push_back(1);
    a[0].push_back(2);
    a[1].push_back(2);
    a[2].push_back(0);
    a[2].push_back(3);
    a[3].push_back(3);

    dfs(a, V, 2);
    printf("\n");
    return 0;
}
