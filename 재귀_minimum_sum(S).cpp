/*
3
1 5 3
2 4 7
5 3 5
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector <vector<int>> v;
vector <int> check_col;
int n,min0=INT_MAX;

void solution(int row, int score)
{
    int sum=0;
    if(row == n){
        min0=min(min0,score);       // �ּҰ� ���ϱ�,���� ������ ���� �ּҰ� �Ǵ� ��
        cout << "���� �հ� : " << score << ", �ּҰ� : " << min0 << "\n\n";
        return;
    }

    for(int i=0;i<n;i++){
        if(!check_col[i])           // ���� ���� �湮�ߴ°� check!
        {
            cout << row << " " << i << " "  << score << endl;
            check_col[i]=1;
            solution(row+1,score+v[row][i]);
            check_col[i]=0;
        }
    }
    return;
}

int main()
{
    cout << "[�Է�]" << endl;p;
    cin >> n;
    v.resize(n,vector<int>(n,0));
    check_col.resize(n,0);

    for(int i=0;i<n;i++){ n  mm
        for(int j=0;j<n;j++){
            cin >> v[i][j];
        }
    }
    cout << "[�湮������ �հ�]" << endl;
    solution(0,0);
    cout << "[����]" << endl;
    cout << min0;
}
