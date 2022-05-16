/*
7
0 1 1 0 1 0 0
0 1 1 0 1 0 1
1 1 1 0 1 0 1
0 0 0 0 1 1 1
0 1 0 0 0 0 0
0 1 1 1 1 1 0
0 1 1 1 0 0 0
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
vector<int> Size;
int n;
int cnt;        // 몇개의 블록인가?
int idx=1;      // 한개의 블록을 1로 변경
// 왼쪽 끝, 오른쪽 끝, 위쪽 끝, 아래쪽 끝
bool gade(int x, int y){
    return (x>=0 && x<n) && (y>=0 && y<n);
}
//내림차순 정렬을 하기 위한 함수 포인터
bool cmp(int x, int y)
{
    return x>y;
}
void f_fill(int x, int y, int z)        //x행, y열 ,채울 숫자
{
    cnt++;
    v[x][y]=z;
    if(gade(x+1,y) && v[x+1][y]==1)   f_fill(x+1,y,z);  //오른쪽
    if(gade(x-1,y) && v[x-1][y]==1)   f_fill(x-1,y,z);  //왼쪽
    if(gade(x,y+1) && v[x][y+1]==1)   f_fill(x,y+1,z);  //위
    if(gade(x,y-1) && v[x][y-1]==1)   f_fill(x,y-1,z); //아래

}
void print()
{
    cout << idx-1 << endl;
    for(int i=0;i<n;i++)
        if(Size[i]!=0)
            cout << Size[i] << endl;
}

int main()
{
    cin >> n;
    v.resize(n+1,vector<int> (n+1,0));
    Size.resize(n+1,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> v[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cnt=0;
            if(v[i][j] == 1)
            {
                idx++;
                f_fill(i,j,idx);
                Size[idx-2]=cnt;
            }
        }
    }
    sort(Size.begin(),Size.end(),cmp);
    print();
}
