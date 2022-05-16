#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v(3, vector<int> (4,0));

int arr[3][4] = {
    {1,3,5,8},
    {4,2,1,7},
    {4,3,2,3}
};
int Min(int x, int y) { return (x<y) ? x: y; }

int solution(int x, int y)
{
    v[0][0] = arr[0][0];
    for(int i=1;i<3;i++){               // i행 0열 채우기
        v[i][0] = arr[i][0] + v[i-1][0];
    }

    for(int j=1;j<4;j++)                // 0행 j열 채우기
    {
        v[0][j] = arr[0][j] + v[0][j-1];
    }

    for(int i=1;i<3;i++){
        for(int j=1;j<4;j++){
            v[i][j]=Min(v[i-1][j],v[i][j-1])+arr[i][j];
        }
    }
    return v[x][y];
}

int main()
{
    cout << solution(2,3) << endl;
    return 0;
}
