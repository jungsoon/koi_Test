#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <vector<int>> arr,DT;
int n,m;

int solution(int row, int col)      //하향식 방법
{
    if(DT[row][col]) return DT[row][col];
    if(row==n && col==m) return arr[row][col];
    if(row>=n || col>=m) return 0;

    return DT[row][col]=arr[row][col]+max(solution(row,col+1),solution(row+1, col));
}

void solution2(int row, int col)        // 상향식 방법
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            DT[i][j] = max(DT[i-1][j],DT[i][j-1])+ arr[i][j];
        }
    }

}
int main()
{

    cin >> n >> m;
    int row,col,first=1;

    arr.resize(n+1, vector<int> (m+1,0));
    DT.resize(n+1, vector<int> (m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
        }
    }
    //cout << solution(0,0) << "\n";
    solution2(1,1);
    cout << DT[n][m] << endl;
}
