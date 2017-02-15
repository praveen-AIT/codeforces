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

void bfs(vector <vector <int> >a, int v, int s)
{
    int visited[v] = {0};

    queue<int> q;
    visited[s] = 1;
    q.push(s);
    printf("%d\t", s);
    
    while(!q.empty())
    {
        int x = q.front();

        q.pop();
        int i=0;
        
        while(i < a[x].size())
        {
            if(visited[a[x][i]] == 0)
            {
                visited[a[x][i]] = 1;
                q.push(a[x][i]);
                printf("%u\t", a[x][i]);
            }
           i++;
        }
        visited[x] = 1;
    }
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

    bfs(a, V, 2);

    return 0;
}
