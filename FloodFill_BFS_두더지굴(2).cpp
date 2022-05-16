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
int idx=1;      // ���̿켱 Ž���� ��� �ߴ� ī��Ʈ
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};   // x�� 1:������, -1:����, y�� 1:��, y�� -1:�Ʒ�

// ���� ��, ������ ��, ���� ��, �Ʒ��� ��
bool gade(int x, int y){
    return (x>=0 && x<n) && (y>=0 && y<n);
}
//�������� ������ �ϱ� ���� �Լ� ������
bool cmp(int x, int y)
{
    return x>y;
}
void f_fill(int x, int y, int z)
{
    queue<Pos> Q;           // ��ǥ�� ���� ��ġ Ŭ���� Q

    Q.push((Pos){x,y});             // ù��° 1�� Q�� ����
    v[x][y]=z;                      // 2�� ä���.


    while(!Q.empty())
    {
        Pos current = Q.front();    //Queue�� ���� ù��° ��ġ ������ current�� ����
        Q.pop();
        cnt++;                      // �Ѱ��� �� ����
        printf("%d %d %d\n",current.x,current.y, cnt);
        for(int i=0;i<4;i++)
        {
            int tx=current.x+dx[i];
            int ty=current.y+dy[i];
            if(gade(tx,ty) && v[tx][ty]==1)        // �湮 ������ gade�� �ɸ��°�? �湮�� �ѹ��� ���� �ʾҴ°�?
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
