#include <iostream>
using namespace std;

int arr[10][10];
bool visited[10];
int n;
void dfs(int V)
{
    visited[V]=true;
    printf("Á¤Á¡ %d -> ",V);
    for(int i=0;i<=n;i++)
    {
        if(arr[V][i]==1 && !visited[i]){
            dfs(i);
        }
    }

}

int main()
{

    cin >> n;
    int v,w;
    for(int i=0;i<n;i++){
        cin >> v >> w;
        arr[v][w]=arr[w][v]=1;
    }

    dfs(0);
}
