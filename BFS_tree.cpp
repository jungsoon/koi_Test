/*
간선의 개수 : 7
1 2
1 3
1 5
2 4
2 6
3 7
3 8
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector <int> v[12];
int n;

void bfs(int k)
{
    queue <int> tree;
    vector <bool> visited(n+2,0);

    visited[k]=true;
    tree.push(k);

    while(!tree.empty()){
        int current=tree.front();
        tree.pop();

        cout << current << "=>";

        for(int i=0;i<v[current].size();i++){
            int s=v[current][i];
            if(!visited[s]){
                visited[s]=true;
                tree.push(s);
            }
        }
    }
}
int main()
{
    int a,b;
    cout << "간선의 개수 : ";
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout << "==========너비우선탐색(BFS)=========="<<endl;
    bfs(1);
}
