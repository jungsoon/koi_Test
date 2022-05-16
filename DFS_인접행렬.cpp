/*
n:정점의 개수
m:간선의 개수
w:정점과 간선간의 비용
visited[12] : 방문했는가?
g[10][10] : 인접행렬
*/

#include <iostream>
#include <climits>
using namespace std;

bool visited[12];
int g[10][10];
int n,m;
int mincost=INT_MAX;

void dfs(int v,int w)
{
    if(v==n) {
        if(mincost > w) mincost=w;
        return;
    }

    for(int i=1;i<=n;i++)
    {
        if(g[v][i] && !visited[i])
        {
            cout <<"정점: "<< v << i <<"누적된 비용: " << w << endl;
            visited[i] = true;
            dfs(i,w+g[v][i]);
            visited[i] = false;
        }
    }

}

int main()
{
    cin >> n >> m;
    int a,b,w;
    for(int i=1;i<=m;i++){
        cin >> a >> b >> w;
        g[a][b]=g[b][a]=w;
    }
    dfs(1,0);

    cout << ((mincost==INT_MAX)? -1: mincost) << endl;
    return 0;
}
