/*
n:������ ����
m:������ ����
w:������ �������� ���
visited[12] : �湮�ߴ°�?
g[10][10] : �������
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
            cout <<"����: "<< v << i <<"������ ���: " << w << endl;
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
