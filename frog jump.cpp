#include <bits/stdc++.h>
using namespace std;

int r, c;

int bfs(map<pair<int,int>, vector<pair<int,int> > >a)
{
    int x, y, i, j;
    int dist[300][300];

    queue<pair<int,int> >q;
    q.push(make_pair(0,0));
    
    pair<int, int> m;

    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
            dist[i][j] = INT_MAX;
    
    dist[0][0]=0;
    while(!q.empty())
    {
        m = q.front();
        q.pop();
        
        x = m.first;
        y = m.second;
        
        pair<int, int> n;
        for(i=0; i<a[m].size(); i++)
        {
            n = a[m][i];
            dist[n.first][n.second] = min(dist[n.first][n.second],
                                          dist[x][y]+1);
            q.push(n);    
        }
    }
    return dist[r-1][c-1];
}

int main()
{
    int i, j, k, t;
    int D[300][300], R[300][300];
    map<pair<int,int>, vector<pair<int,int> > >a; 

    cin>>r>>c;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
            cin>>R[i][j];
    }
 
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
            cin>>D[i][j];
    }

    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            t = R[i][j];
 
            for(k=1; k<=t; k++)
                a[make_pair(i,j)].push_back(make_pair(i,j+k)); 
            
            t = D[i][j];

            for(k=1; k<=t; k++)
                a[make_pair(i,j)].push_back(make_pair(i+k,j));
        }
    }
    
    printf("%d\n",bfs(a));
    return 0;
}