#include <iostream>
using namespace std;

int arr[11][11];
int n;
void dfs(int V)
{
    cout << V << " => ";

    for(int i=1;i<=n+1;i++)
    {
        if(arr[V][i]==1){
            dfs(i);
        }
    }
    return;

}

int main()
{
    int v,w;
    cout << "<< tree - ���̿켱Ž��(DFS) >> " << endl;
    cout << "������ ���� �Է��ϼ��� : ";
    cin >> n;

    cout << "����� ��� �Է�" << endl;
    for(int i=0;i<n;i++){
        cin >> v >> w;
        arr[v][w]=1;
    }
    dfs(1);
}
