#include <iostream>
#include <vector>
using namespace std;

vector <vector<int>> DT;
int solution(int x, int y)      //하향식 - 메모이제이션
{
    if(DT[x][y]) return DT[x][y];
    if(x==1 || y==1) return DT[x][y]=1;
    return DT[x][y]=solution(x-1,y)+solution(x,y-1);
}

int solution2(int x, int y) //상향식
{
    for(int i=1;i<=x;i++){
        DT[i][1]=1;
    }

    for(int i=1;i<=y;i++){
        DT[1][i]=1;
    }

    for(int i=2;i<=x;i++){
        for(int j=2;j<=y;j++){
            DT[i][j] = DT[i-1][j] + DT[i][j-1];
        }
    }

    return DT[x][y];
}

int main()
{
    int row, col;

    cin >> row >> col;

    DT.resize(row+1,vector<int> (col+1,0));
    cout << solution2(row,col) << endl;

    for(int i=0;i<=row;i++){
        for(int j=0;j<=col;j++){
            cout << DT[i][j] << " ";
        }
        cout << endl;
    }
}
