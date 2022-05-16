#include <iostream>
#include <climits>
using namespace std;

bool visited[12];
int g[10][10];
int n,m, sol=INT_MAX;
void dfs(int V,int W)
{
    if(V==n){
        if(W<sol) sol=W;
        return;
    }

    for(int i=1;i<=n;i++)
    {
        if(g[V][i] && !visited[i])
        {
            visited[i] = true;
            cout << V << i << " " << W << endl;
            dfs(i,W+g[V][i]);

            visited[i]=false;
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
    cout << ((sol==INT_MAX)?-1:sol) << endl;
    return 0;
}
