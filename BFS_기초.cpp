/*
너비우선 탐색 : 최단경로 구할때 많이 쓰임, 미로찾기
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int visit[8];
vector<int> a[8];

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    visit[start]=true;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        cout << x << " ";
        for(int i=0;i<a[x].size();i++){
            int y=a[x][i];
            if(!visit[y]){
                q.push(y);
                visit[y]=true;
            }
        }

    }

}

int main()
{
    /*
    a[1] = 2 3
    a[2] = 1 3 4 5
    a[3] = 1 2 6 7
    a[4] = 2 5
    a[5] = 2 4
    a[6] = 3 7
    a[7] = 3 6
    */
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int num,node;
        cin >> node >> num;
        a[node].push_back(num);
    }
    BFS(1);

}
