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
#include <queue>
#include <algorithm>
using namespace std;

struct Pos{ int x,y; };

vector<vector<int>> v;
vector<int> Size;

int n;
int cnt;
int idx=1;      // 깊이우선 탐색을 몇번 했는 카운트
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};   // x축 1:오른쪽, -1:왼쪽, y축 1:위, y축 -1:아래

// 왼쪽 끝, 오른쪽 끝, 위쪽 끝, 아래쪽 끝
bool gade(int x, int y){
    return (x>=0 && x<n) && (y>=0 && y<n);
}
//내림차순 정렬을 하기 위한 함수 포인터
bool cmp(int x, int y)
{
    return x>y;
}
void f_fill(int x, int y, int z)
{
    queue<Pos> Q;           // 좌표를 가진 위치 클래스 Q

    Q.push((Pos){x,y});             // 첫번째 1을 Q에 삽입
    v[x][y]=z;                      // 2로 채운다.


    while(!Q.empty())
    {
        Pos current = Q.front();    //Queue에 가장 첫번째 위치 정보를 current에 삽입
        Q.pop();
        cnt++;                      // 한개의 블럭 시작
        printf("%d %d %d\n",current.x,current.y, cnt);
        for(int i=0;i<4;i++)
        {
            int tx=current.x+dx[i];
            int ty=current.y+dy[i];
            if(gade(tx,ty) && v[tx][ty]==1)        // 방문 정보가 gade에 걸리는가? 방문을 한번도 하지 않았는가?
            {
                v[tx][ty] = z;
                Q.push((Pos) { tx, ty});
            }

        }
    }

}
void print()
{
    cout << idx-1 << endl;
    for(int i=0;i<Size.size();i++)
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
                cout << "*" << cnt << endl;
                Size[idx-2]=cnt;
            }
        }
    }
    sort(Size.begin(),Size.end(),cmp);
    print();
}
